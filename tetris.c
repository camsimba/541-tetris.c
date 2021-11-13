#include <stdio.h>
#include <stdbool.h>
//#include <iostream>
//#include "utils.h"
#include <string.h>
//#include <Windows.h>
#include <stdlib.h>

struct Block b1, b2, b3, b4;

int width = 10;
int height = 20;

struct Block {
    int x;
    int y;
};

int gameState[200] = {0};

//updates the array that stores info on block locations
int updateState(){
    gameState[b1.x + width*b1.y] = 1;
    gameState[b2.x + width*b2.y] = 1;
    gameState[b3.x + width*b3.y] = 1;
    gameState[b4.x + width*b4.y] = 1;
}

//removes current blocks from game state
int removeBlocksFromState(){
    gameState[b1.x + width*b1.y] = 0;
    gameState[b2.x + width*b2.y] = 0;
    gameState[b3.x + width*b3.y] = 0;
    gameState[b4.x + width*b4.y] = 0;
}

//checks if downward movement is blocked
bool check_down(){
    if(b1.y == height - 1 || b2.y == height - 1 || b3.y == height - 1 || b4.y == height - 1){
        return false;
    }
    int newb1 = gameState[b1.x + width*(b1.y + 1)];
    int newb2 = gameState[b2.x + width*(b2.y + 1)];
    int newb3 = gameState[b3.x + width*(b3.y + 1)];
    int newb4 = gameState[b4.x + width*(b4.y + 1)];
    if(newb1 != 0 || newb2 != 0 || newb3 != 0 || newb4 != 0){
        return false;
    }
    return true;
}

bool check_left(){
    if(b1.x == 0 || b2.x == 0 || b3.x == 0 || b4.x == 0){
        return false;
    }
    int newb1 = gameState[b1.x + width*b1.y - 1];
    int newb2 = gameState[b2.x + width*b2.y - 1];
    int newb3 = gameState[b3.x + width*b3.y - 1];
    int newb4 = gameState[b4.x + width*b4.y - 1];
    if(newb1 != 0 || newb2 != 0 || newb3 != 0 || newb4 != 0){
        return false;
    }
    return true;
}

bool check_right(){
    if(b1.x == width - 1 || b2.x == width - 1 || b3.x == width - 1 || b4.x == width - 1){
        return false;
    }
    int newb1 = gameState[b1.x + width*b1.y + 1];
    int newb2 = gameState[b2.x + width*b2.y + 1];
    int newb3 = gameState[b3.x + width*b3.y + 1];
    int newb4 = gameState[b4.x + width*b4.y + 1];
    if(newb1 != 0 || newb2 != 0 || newb3 != 0 || newb4 != 0){
        return false;
    }
    return true;
}

void drawGame(){
    printf("%c", '\n');
    printf("----------------------------------------");
    printf("%c", '\n');
    for(int i = 0; i < width*height; i++){
        if(i%width == 0){
            printf("%c", '\n');
        }
        if(gameState[i] == 0){
            printf("[ ]");
        }else{
            printf("[%d]", gameState[i]);
        }
    }
    return;
}

//updates current falling block; 1 = stay on current block / -1 = game over / 0 = switch to new block
int updateBlock(int dir){
    //dir --> 0 = down; 1 = left; 2 = right;
    removeBlocksFromState();
    switch(dir){
        case 0: //down
            if(!check_down()){
                updateState();
                return 0;
            }
            b1.y += 1; b2.y += 1; b3.y += 1; b4.y += 1;
            break;
        case 1: //left
            if(!check_left()){
                updateState();
                return 1;
            }
            b1.x -= 1; b2.x -= 1; b3.x -= 1; b4.x -= 1;
            break;
        case 2: //right
            if(!check_right()){
                updateState();
                return 1;
            }
            b1.x += 1; b2.x += 1; b3.x += 1; b4.x += 1;
            break;
    }
    updateState();
    return 1;
}

//initializes new blocks at top
bool placeBlock(int block){
    printf("%d", block);
    switch(block){
        case 0: //T
            b1.x = 4;
            b2.x,b4.x = 5;
            b3.x = 6;
            b1.y,b2.y,b3.y = 0;
            b4.y = 1;
            break;
        case 1: //S
            b1.x = 4; b1.y = 1;
            b2.x = 5; b2.y = 1;
            b3.x = 5; b3.y = 0;
            b4.x = 6; b4.y = 0;
            break;
        case 2: //L
            b1.x = 4; b1.y = 0;
            b2.x = 4; b2.y = 1;
            b3.x = 4; b3.y = 2;
            b4.x = 5; b4.y = 2;
            break;
        case 3: //I
            b1.x,b2.x,b3.x,b4.x = 4;
            b1.y = 0;
            b2.y = 1;
            b3.y = 2;
            b4.y = 3;
            break;
        case 4: //SQ
            b1.x = 4; b1.y = 0;
            b2.x = 5; b2.y = 0;
            b3.x = 4; b3.y = 1;
            b4.x = 5; b4.y = 1;
            break;
        case 5: //Z
            b1.x = 4; b1.y = 0;
            b2.x = 5; b2.y = 0;
            b3.x = 5; b3.y = 1;
            b4.x = 6; b4.y = 1;
            break;
        case 6: //BL
            b1.x = 4; b1.y = 2;
            b2.x = 5; b2.y = 0;
            b3.x = 5; b3.y = 1;
            b4.x = 5; b4.y = 2;
            break;
    }
    int newb1 = gameState[b1.x + width*b1.y];
    int newb2 = gameState[b2.x + width*b2.y];
    int newb3 = gameState[b3.x + width*b3.y];
    int newb4 = gameState[b4.x + width*b4.y];
    if(newb1 != 0 || newb2 != 0 || newb3 != 0 || newb4 != 0){
        return false;
    }
    updateState();
    return true;
}

bool game_start(){
    int randBlock, randRot;
    int currBlock = 0;
    while(1){
        drawGame();
        //sleep(1);
        char chr;
        int dir = 0;
        scanf("%c", &chr);
        if(chr == 'a'){
            dir = 1;
        }else if(chr == 's'){
            dir = 0;
        }else if(chr == 'd'){
            dir = 2;
        }else{
            dir = 0;
        }
        if(currBlock == 0){
            randBlock = rand() % 7;
            //randRot = rand() % 4;
            if(!placeBlock(randBlock)){
                printf("game over");
                break;
            }
        }
        currBlock = updateBlock(dir);
        if(currBlock == -1){
            printf("game over");
            break;
        }
    }
    return true; //exit game
}

int main( int argc, char** argv ) {
	while(1){
        bool exitGame = false;
        // if(!game_initialize()){
        //     printf("failed to initialize");
        //     break;
        // }
        exitGame = game_start();
        if(exitGame){
            break;
        }
    }
}