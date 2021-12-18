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

void logAuto(std::string header, std::string input){
    logHeader(header);
    log(input);
    logFooter();
}