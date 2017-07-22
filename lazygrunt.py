'''
 Copyright 2017 Andrew Burnett

 Redistribution and use in source and binary forms, with or without modification, are permitted provided that the following conditions are met:

 1. Redistributions of source code must retain the above copyright notice, this list of conditions and the following disclaimer.

 2. Redistributions in binary form must reproduce the above copyright notice, this list of conditions and the following disclaimer in the documentation and/or other materials provided with the distribution.

 3. Neither the name of the copyright holder nor the names of its contributors may be used to endorse or promote products derived from this software without specific prior written permission.

 THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
'''

### UTILITY FOR CONVERTING .ENT PLUGINS INTO C++ CODE ###

import xml.etree.ElementTree as et
import sys
import re

# Setup exclusion dictionary.
# There are several types in .ent files that contain lists of options.
# We'll want to deal with them after the initial generation of structure definintions.
exclude = list({"bitmask32", "bitmask16", "bitmask8", "enum16"))

# Takes in a string and removes unwanted characters and leading whitespace.
def sanitize(name):
	n = name
	n = n.replace(" ", "_")
	n = n.lower()
	n = re.sub('[^0-9a-zA-Z_]', '', n)	# Strip unwanted characters.
	n = re.sub('^[^a-zA-Z_]+', '', n)	# Stripe leading whitespace.
	return n

def generate_lookup(path = "keywords.txt"):
	# Set up a replacement dictionary for keywords.
	with open(path) as f:
		keywords = [line.rstrip('\n') for line in f]
	types = dict()
	for pair in keywords:
		pair = pair.split("->")
		types[pair[0]] = pair[1]
	return types

types = generate_types()

def generate_sizes(path = "size.txt"):
	# Set up a size dictionary for the length of a data.
	with open(path) as f:
		size = [line.rstrip('\n') for line in f]
	sizes = dict()
	for pair in size:
		pair = pair.split("->")
		sizes[pair[0]] = int(pair[1])
	return sizes

sizes = generate_sizes()

def print_struct(tree, unknowns = 0):
	if (len(tree) == 0):
		return

	if (tree.tag in exclude):
		return
	if (tree.tag == "plugin"):
		print "struct " + (sanitize(tree.attrib["class"]))
	else:
		print "struct " + (sanitize(tree.attrib["name"]))
	print "{"
	
	previous_offset = 0
	for child in tree:
		if (child.tag != "note"):
			att = child.attrib
			elem = att["name"]
			offset = int(att["offset"], 16)
			size = offset - previous_offset
			if (child.tag not in sizes.keys()):
				print "NEED: " + child.tag
			if ((size) > 0x28):
				unknowns += 1
				print "char padding" + str(unknowns) + "[" + hex(size) + "];"
			previous_offset = offset
			var_name = (child.attrib["name"])
			var_name = sanitize(var_name)
			if (child.tag in types.keys()):
				var_type = types[child.tag]
			else:
				var_type = "<FIGURE OUT = \"" + child.tag + "\" >"
			print var_type + " " + var_name + ";"
	print "};\n"
	for child in tree:
		print_struct(child, unknowns)

ent_file = sys.argv[len(sys.argv) - 1]
e = et.parse(ent_file).getroot()
if (e == None):
	print "No file path arguments found."
else:
	print_struct(e, target_file)
