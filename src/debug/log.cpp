#include <iostream>
#include "log.h"

//creates the header for debug logging
void logHeader(std::string input){
    std::cout << "-----------" << input << "-----------" << std::endl;
}

//creates the body for debug logging
void log(std::string input){
    std::cout << input << std::endl;
}


//creates the ending footer for debug logging
void logFooter(){
    std::cout << "-----------end-----------" << std::endl;
}

//first variable is the header, followed by the body. The log footer is automatically generated
void logAuto(std::string header, std::string input){
    logHeader(header);
    log(input);
    logFooter();
}

//prints, then throws a generic exception! Use when prototyping only!
//this is not the proper way of dumping a crash message!
void logCrash(std::string input){
    log("\n\n\n");
    logHeader("A CRASH HAS HAPPENED!");
    log("\n\nCrash Reason:");
    log(input);
    log("\n\n");
    logFooter();
    log("A generic exception:");
    throw std::exception();

}