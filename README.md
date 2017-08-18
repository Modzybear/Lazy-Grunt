# Lazy Grunt
Copyright &copy; 2017 Andrew Burnett

Lazy Grunt is a utility for converting .ent files (Eschaton plugins)
to C++ header files with all relevent data written into structs.

## Necessary Files
There are two necessary files: sizes.txt and keywords.txt.
sizes.txt contains a list of types and their binary length.
keywords.txt contains a list of .ent types and their c++-friendly
translations. Each line in the files contains a key-value pair structured
as follows:

ent_type->c++-friendly

## Work in Progress

This release is an initial release with a *majority* of the functionality
I plan to implement. Both of the necessary files are incomplete, and therefore
the header files that are generated at this point aren't of much use.

## How To Use

Run 'python lazygrunt.py <path to .ent file>

Once the above command is given, the program will open the .ent file
and attempt to translate it into a C++ header file. The generated header
file will be in the same directory as the program.

## Python Version

This project is build for Python 2.

## License

Lazy Grunt is available under the BSD three-clause license.
See the LICENSE file for more information.

## TO DO

- Implement recursive conversion when given a folder
- Generate .cpp code.
