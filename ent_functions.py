
# Copyright 2017 Andrew Burnett
#
# Redistribution and use in source and binary forms, with or without modification, are permitted provided that the following conditions are met:
#
# 1. Redistributions of source code must retain the above copyright notice, this list of conditions and the following disclaimer.
# 
# 2. Redistributions in binary form must reproduce the above copyright notice, this list of conditions and the following disclaimer in the documentation and/or other materials provided with the distribution.
#
# 3. Neither the name of the copyright holder nor the names of its contributors may be used to endorse or promote products derived from this software without specific prior written permission.
#
# THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

### LAZY GRUNT -- ENT_FUNCTIONS ###
### UTILITY FUNCTIONS FOR LAZY GRUNT ###

import xml.etree.ElementTree as et
import re

# Setup exclusion dictionary.
# There are several types in .ent files that contain lists of options.
# We'll want to deal with them after the initial generation of structure definintions.
exclude = list({"bitmask32", "bitmask16", "bitmask8", "enum16"})

# Takes in a string and removes unwanted characters and leading whitespace.
def sanitize(name):
	n = name
	n = n.replace(" ", "_")
	n = n.lower()
	n = re.sub('[^0-9a-zA-Z_]', '', n)	# Strip unwanted characters.
	return n

# Creates dictionaries for looking up .ent names and translating them
# into specific information.
def generate_lookup(path = "lookup.txt"):
	# Set up a lookup dictionary for keywords and their translations.
	with open(path) as f:
		lines = [line.rstrip('\n') for line in f]
	lookup = dict()
	for pair in lines:
		pair = pair.split("->")
		lookup[pair[0]] = pair[1]
	return lookup

# Setup lookup and replacement dictionaries.
types = generate_lookup("keywords.txt")
sizes = generate_lookup("sizes.txt")

# Recursively walks down the .ent structures and interprets the elements.
# Prints the interpretation to the specified file.
def print_struct(tree, output, errors):
	# Check for subtrees
	if (len(tree) == 0):
		return
	
	# Check for structure exlusions
	if (tree.tag in exclude):
		return
	
	# Write the initial tag header structure
	if (tree.tag == "plugin"):
		output.write("struct " + (sanitize(tree.attrib["class"])) + "\n")
	else:
		output.write("struct " + (sanitize(tree.attrib["name"])) + "\n")
	output.write("{\n")
	
	previous_offset = 0
	unknowns = 0
	for child in tree:
		if (child.tag != "note"):
			att = child.attrib
			offset = int(att["offset"], 16)
			size = offset - previous_offset
			if (child.tag not in sizes.keys()):
				errors.write("<Need size for: \"" + child.tag + "\"\n")
			### TEMP CODE; REMOVE LATER FOR ACTUAL SIZE CALCULATIONS ###
			if ((size) > 0x28):
				unknowns += 1
				output.write("char unknown" + str(unknowns) + "[" + hex(size) + "];\n")
			previous_offset = offset
			var_name = sanitize(att["name"])
			var_type = child.tag
			if (child.tag in types.keys()):
				var_type = types[child.tag]
			else:
				errors.write("<Need lookup for: \"" + child.tag + "\" >\n")
			output.write(var_type + " " + var_name + ";\n")
	output.write("};\n\n")
	for child in tree:
		print_struct(child, output, errors)
