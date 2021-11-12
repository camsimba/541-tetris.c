#include <stdio.h>
#include <stdbool.h>
#include <iostream>
#include "utils.h"
#include <string.h>

struct Block b1, b2, b3, b4;

#define width = 10;
#define height = 20;

struct Block {
    int x;
    int y;
};

int main( int argc, char** argv ) {
	while(1){
        bool exitGame = false;
        if(!game_initialize()){
            printf("failed to initialize");
            break;
        }
        exitGame = game_start();
        if(exitGame){
            break;
        }
    }
}

bool game_start(){
    int randBlock, randRot;
    int currBlock = 0;
    while(1){
        if(currBlock == 0){
            randBlock = rand() % 4;
            randRot = rand() % 4;
            placeBlock(randBlock);
        }
        currBlock = updateBlock();
        if(currBlock == -1){
            break;
        }
    }
}

void placeBlock(int block){
    switch(block){
        case 0: //T
            b1.x = 4;
            b2.x,b4.x = 5;
            b3.x = 6;
            b1.y,b2.y,b3.y = 0;
            b4.y = 1;
            break;
        case 1: //S
        case 2: //L
        case 3: //I
    }
}

int updateBlock(){

}