# Trie-Tree
CS 480 Trie Tree implementation
Author: Devin Lepur
Project for SDSU CS 480 Prof Shen

This project is an implementation of a trie tree that processes
a given testfile and finds how many substrings of each line exist
in a vocabulary file. 

countsubstrings is the main file and creates a tree of every possible
substring of a line of the testfile and iterates through the vocabulary
file, counting every time a match is found in the tree. After every line
the program outputs the count per line to the standard output.

Sample input files, "vocabulary.txt", "testfile.txt", and a sample
output file "testoutput" are provided.

Usage: ./countsubstrings vocabulary.txt testfile.txt
