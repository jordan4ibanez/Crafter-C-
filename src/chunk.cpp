#include "chunk.h"
#include <iostream>
#include <array>
#include "debug/log.h"
#include <random>


//create random assigned data structure for testing
std::array<uint8_t, 128> aChunkOfData;

void testMyChunk(){
    std::random_device rd; // obtain a random number from hardware
    std::mt19937 gen(rd()); // seed the generator
    std::uniform_int_distribution<> distr(0, 255); // define the range

    //randomly disperse data values into the chunk array
    for (int i = 0; i < aChunkOfData.size(); i++){
        aChunkOfData[i] = distr(gen);
    }


    //create an info stream of dispersed data
    logHeader("Begin Chunk");

    std::string infoStream("");

    for (int i = 0; i < aChunkOfData.size(); i++){
        if (i != 0){
            infoStream += ",";
        }
        infoStream += std::to_string(aChunkOfData[i]);
    }

    log(infoStream);

    logFooter();
}