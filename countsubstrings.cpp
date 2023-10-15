/* Author: Devin Lepur
 * 9/7/23
 * Instructor: Prof Shen
 * SDSU CS 480
 * Counts substrings of given words in a list
 */

#include "tree.h"
#include <iostream>
#include <fstream>
#include <string>

int main(int argc, char **argv) {

    //arg check
    if(argc != 3) {
        std::cerr << "Usage: " << argv[0] << " vocabulary.txt testfile.txt" << std::endl;
        return 0;
    }

    //open files
    const char* testfile = argv[2];
    const char* vocabfile = argv[1];
    std::ifstream inputfile1(testfile);
    std::ifstream inputfile2(vocabfile);


    if(!testfile || !vocabfile) {
        std::cerr << "Error: Could not open file." << std::endl;
        return 0;
    }

    const char* word;
    std::string line1;
    std::string line2;

    //get and run through testfile
    while(std::getline(inputfile1, line1)) {
        tree myTree = tree();
        word = line1.c_str();

        int length = 0;
        while (word[length] != '\0') {
            length++;
        }


        //Code for generating and inserting substrings of test words
        //loop for the starting position of the substring
        for (int start = 0; start < length; start++) {
            //loop for the length of the substring
            for (int len = 1; len <= length - start; len++) {
                //Extract the substring
                char substring[len + 1];
                for (int i = 0; i < len; i++) {
                    substring[i] = word[start + i];
                }
                substring[len] = '\0';
                myTree.insert(substring);
            }
        }

        //null char is substring of any word
        myTree.insert("\0");

        //get and run through vocab aand count
        int count = 0;
        while(std::getline(inputfile2, line2)) {
            word = line2.c_str();

            if(myTree.search(word)) {
                count++;
            }
        }
        std::cout << count << std::endl;

        //Reset reading of vocab file
        inputfile2.clear();
        inputfile2.seekg(0, std::ios::beg);
    }
}