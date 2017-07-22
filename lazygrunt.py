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

### LAZY GRUNT ###
### UTILITY FOR CONVERTING .ENT PLUGINS INTO C++ CODE ###

import xml.etree.ElementTree as et
import sys
import ent_functions as ent

# Takes in a path to a .ent file and attempts to
# translate it into c++ code.
def create_tag(path):
	# Check for bad path.
	if (path == None):
		return
	tag = et.parse(path).getroot()
	
	# Check for malformed xml.
	if (tag == None):
		print "Error parsing file: \"" + path + "\""
		return

	# Make sure it is an ent plugin file.
	if (tag.tag != "plugin"):
		print "Not a plugin file: \"" + path + "\""
		return

	# Create the .h file and write to it.
	output = open(tag.attrib["class"] + ".h", "w+")
	errors = open("errors.txt", "w+")
	ent.print_struct(tag, output, errors)

# Get command line arguments.
def get_argv():
	if (len(sys.argv) < 2):
		print "No file path arguments found."
		return
	# Check for recursive flag.
	if (sys.argv[1] == "-R"):
		# Check for folder.
		if (len(sys.argv) < 3):
			print "No folder specified for recursive conversion."
			return
		# Get file list.
	else:
		# Only one file to translate.
		create_tag(sys.argv[1])

# Begin execution
get_argv()
