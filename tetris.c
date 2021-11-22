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
    int rot;
};

int gameState[200] = {0};
int score = 0;

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

bool check_block(){
    if(b1.x < 0 || b1.x >= width || b2.x < 0 || b2.x >= width || b3.x < 0 || b3.x >= width || b4.x < 0 || b4.x >= width){
        return false;
    }
    if(b1.y < 0 || b1.y >= height || b2.y < 0 || b2.y >= height || b3.y < 0 || b3.y >= height || b4.y < 0 || b4.y >= height){
        return false;
    }
    int newb1 = gameState[b1.x + width*b1.y];
    int newb2 = gameState[b2.x + width*b2.y];
    int newb3 = gameState[b3.x + width*b3.y];
    int newb4 = gameState[b4.x + width*b4.y];
    if(newb1 != 0 || newb2 != 0 || newb3 != 0 || newb4 != 0){
        return false;
    }
    return true;
}

void drawGame(){
    printf("%c", '\n');
    printf("--------Score = '%d'-------------------------------", score);
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

//updates current falling block; return 1 = stay on current block / 0 = switch to new block
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
            b1.x = 4; b1.y = 0;
            b2.x = 4; b2.y = 1;
            b3.x = 4; b3.y = 2;
            b4.x = 4; b4.y = 3;
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
    b1.rot = 0; b2.rot = 0; b3.rot = 0; b4.rot = 0;
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

bool rotateBlock(int block){
    struct Block tb1, tb2, tb3, tb4;
    memcpy(&b1, &tb1, sizeof b1);
    memcpy(&b2, &tb2, sizeof b2);
    memcpy(&b3, &tb3, sizeof b3);
    memcpy(&b4, &tb4, sizeof b4);
    switch(block){
        case 0: //T
            switch(b2.rot){
                case 0:
                    b4.x = b2.x;
                    b4.y = b2.y - 1;
                    break;
                case 1:
                    b3.x = b2.x + 1;
                    b3.y = b2.y;
                    break;
                case 2:
                    b1.x = b2.x;
                    b1.y = b2.y + 1;
                    break;
                case 3:
                    b1.x = b2.x-1;
                    b1.y = b2.y;
                    b3.x = b2.x;
                    b3.y = b2.y+1;
                    b4.x = b2.x+1;
                    b4.y = b2.y;
                    break;
            }
            break;
        case 1: //S
            switch(b2.rot){
                case 0:
                    b4.y += 1;
                    b1.x = b4.x; b1.y = b4.y + 1;
                    break;
                case 1:
                    b4.y -= 1;
                    b1.x = b2.x - 1; b1.y = b2.y;
                    break;
                case 2:
                    b4.y += 1;
                    b1.x = b4.x; b1.y = b4.y + 1;
                    break;
                case 3:
                    b4.y -= 1;
                    b1.x = b2.x - 1; b1.y = b2.y;
                    break;
            }
        case 2: //L
            switch(b2.rot){
                case 0:
                    b1.x = b2.x + 1; b1.y = b2.y;
                    b3.x = b2.x - 1; b3.y = b2.y;
                    b4.x = b3.x; b4.y = b2.y + 1;
                    break;
                case 1:
                    b1.x = b2.x; b1.y = b2.y + 1;
                    b3.x = b2.x; b3.y = b2.y - 1;
                    b4.x = b3.x - 1; b4.y = b3.y;
                    break;
                case 2:
                    b1.x = b2.x -1; b1.y = b2.y;
                    b3.x = b2.x + 1; b3.y = b2.y;
                    b4.x = b3.x; b4.y = b3.y -1;
                    break;
                case 3:
                    b1.x = b2.x; b1.y = b2.y - 1;
                    b3.x = b2.x; b3.y = b2.y + 1;
                    b4.x = b2.x + 1; b4.y = b3.y;
                    break;
            }
            break;
        case 3: //I
            switch(b2.rot){
                case 0:
                    b1.x = b2.x - 1; b1.y = b2.y;
                    b3.x = b2.x + 1; b3.y = b2.y;
                    b4.x = b2.x + 2; b4.y = b2.y;
                    break;
                case 1:
                    b1.x = b2.x; b1.y = b2.y - 1;
                    b3.x = b2.x; b3.y = b2.y + 1;
                    b4.x = b2.x; b4.y = b2.y + 2;
                    break;
                case 2:
                    b1.x = b2.x - 1; b1.y = b2.y;
                    b3.x = b2.x + 1; b3.y = b2.y;
                    b4.x = b2.x + 2; b4.y = b2.y;
                    break;
                case 3:
                    b1.x = b2.x; b1.y = b2.y - 1;
                    b3.x = b2.x; b3.y = b2.y + 1;
                    b4.x = b2.x; b4.y = b2.y + 2;
                    break;
            }
            break;
        case 4: //SQ
            break;
        case 5: //Z
            switch(b2.rot){
                case 0:
                    b1.x = b2.x; b1.y = b2.y - 1;
                    b3.x = b2.x - 1; b3.y = b2.y;
                    b4.x = b3.x; b4.y = b2.y + 1;
                    break;
                case 1:
                    b1.x = b2.x + 1; b1.y = b2.y;
                    b3.x = b2.x; b3.y = b2.y - 1;
                    b4.x = b2.x - 1; b4.y = b3.y;
                    break;
                case 2:
                    b1.x = b2.x; b1.y = b2.y + 1;
                    b3.x = b2.x + 1; b3.y = b2.y;
                    b4.x = b3.x; b4.y = b2.y - 1;
                    break;
                case 3:
                    b1.x = b2.x - 1; b1.y = b2.y;
                    b3.x = b2.x; b3.y = b2.y + 1;
                    b4.x = b2.x + 1; b4.y = b3.y;
                    break;
            }
            break;
        case 6: //BL
            switch(b2.rot){
                case 0:
                    b1.x = b2.x + 1; b1.y = b2.y;
                    b3.x = b2.x - 1; b3.y = b2.y;
                    b4.x = b3.x; b4.y = b2.y - 1;
                    break;
                case 1:
                    b1.x = b2.x; b1.y = b2.y + 1;
                    b3.x = b2.x; b3.y = b2.y - 1;
                    b4.x = b2.x + 1; b4.y = b3.y;
                    break;
                case 2:
                    b1.x = b2.x - 1; b1.y = b2.y;
                    b3.x = b2.x + 1; b3.y = b2.y;
                    b4.x = b3.x; b4.y = b2.y + 1;
                    break;
                case 3:
                    b1.x = b2.x; b1.y = b2.y - 1;
                    b3.x = b2.x; b3.y = b2.y + 1;
                    b4.x = b2.x - 1; b4.y = b3.y;
                    break;
            }
            break;
    }
    if(!check_block()){
        memcpy(&tb1, &b1, sizeof b1);
        memcpy(&tb2, &b2, sizeof b2);
        memcpy(&tb3, &b3, sizeof b3);
        memcpy(&tb4, &b4, sizeof b4);
        return false;
    }
    b1.rot = (b1.rot + 1) % 4; b2.rot = (b2.rot + 1) % 4; b3.rot = (b3.rot + 1) % 4; b4.rot = (b4.rot + 1) % 4;
    removeBlocksFromState();
    updateState();
    return true;
}

void updateScore(){
    for(int i = 0; i < height; i++){
        int line = 0;
        for(int j = 0; j < width; j++){
            if(gameState[j+width*i] == 0){
                break;
            }
            line++;
        }
        if(line == width){
            for(int k = ((i+1)*width)-1; k >= width; k--){
                gameState[k] = gameState[k-width];
                gameState[k-width] = 0;
            }
            score+=width;
        }
    }
}

bool game_start(){
    int randBlock;
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
        // }else if(chr == 'w'){
        //     rotateBlock(randBlock);
        }else{
            dir = 0;
        }
        if(currBlock == 0){
            updateScore();
            randBlock = rand() % 7;
            if(!placeBlock(randBlock)){
                printf("game over");
                break;
            }
        }
        currBlock = updateBlock(dir);
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