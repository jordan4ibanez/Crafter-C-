#include <iostream>
#include <string>
#include <fstream>
#include "explicitIO.h"
#include "../debug/log.h"
#include <cstring>
#include <stdlib.h>

//this converts a file with shader code into a char array for GLFW and GLSL to understand
const char* importShader(std::string fileDirectory){

    std::fstream newfile;

    newfile.open(fileDirectory, std::ios::in);

    std::string realOutput;
    std::string ioReadOutput;

    int fileLines = 0;
    int fileCurrentLine = 0;

    //count the number of lines for carriage returning
    if (newfile.is_open()){
        //file counted line by line -> api does this automatically in while loop
        while(std::getline(newfile, ioReadOutput)){
            fileLines++;
        }
    }

    //reset the fstream back to the beginning
    newfile.clear();
    newfile.seekg(0);

    //transmute the actual file into a string
    if (newfile.is_open()){
        //read data from file line by line and put it into string -> api does this automatically in while loop
        while(std::getline(newfile, ioReadOutput)){

            //std::cout << ioReadOutput;

            //add data to string and count the line number
            realOutput += ioReadOutput;
            fileCurrentLine++;

            //only add a new line if not at the end
            if (fileCurrentLine < fileLines){
                realOutput += "\n";
            }
        }
        //done with file
        newfile.close();
    }


    //now we must transmute the std::string to a const static char* so glfw can understand it
    //basically turning your text into glsl shader code

    int stringLength = realOutput.size();

    //allocate memory to the heap
    char* charArray = (char*) malloc(stringLength * sizeof(char));

    //copy the contents of the string to char array
    std::strcpy(charArray, realOutput.c_str());
    //char* charPointer = charArray;
    //log(realOutput);

    return(charArray);
}