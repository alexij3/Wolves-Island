#ifndef FUNCTIONS_H_INCLUDED
#define FUNCTIONS_H_INCLUDED

#include <SFML/Graphics.hpp>
#include <vector>

using std::vector;
using namespace sf;

bool freeCell(char island[][25], int X, int Y, int choice){
    if (choice == 0){
        if (island[X][Y] == 'r' || island[X][Y] == '.') return true;
        else return false;
    }

    if (choice == 1){
        if (island[X][Y] == 'f' || island[X][Y] == 'r' || island[X][Y] == 'C' || island[X][Y] == '.') return true;
        else return false;
    }

    return 0;
}

bool isThereAFreeCell(char island[][25], int X, int Y, int choice) {
    if (choice == 0){
        if (X != 2 && Y != 2 && freeCell(island, X-1, Y-1, choice)) return true;

        else if (X != 2 && freeCell(island, X-1, Y, choice)) return true;
        else if (X != 2 && Y != 21 && freeCell(island, X-1, Y+1, choice)) return true;
        else if (Y != 21 && freeCell(island, X, Y+1, choice)) return true;
        else if (X != 21 && Y != 21 && freeCell(island, X+1, Y+1, choice)) return true;
        else if (X != 21 && freeCell(island, X+1, Y, choice)) return true;
        else if (X != 21 && Y != 2 && freeCell(island, X+1, Y-1, choice)) return true;
        else if (Y != 2 && freeCell(island, X, Y-1, choice)) return true;
    }

    if (choice == 1) {
        if (X != 2 && Y != 2 && freeCell(island, X-1, Y-1, choice)) return true;

        else if (X != 2 && freeCell(island, X-1, Y, choice)) return true;
        else if (X != 2 && Y != 21 && freeCell(island, X-1, Y+1, choice)) return true;
        else if (Y != 21 && freeCell(island, X, Y+1, choice)) return true;
        else if (X != 21 && Y != 21 && freeCell(island, X+1, Y+1, choice)) return true;
        else if (X != 21 && freeCell(island, X+1, Y, choice)) return true;
        else if (X != 21 && Y != 2 &&freeCell(island, X+1, Y-1, choice)) return true;
        else if (Y != 2 && freeCell(island, X, Y-1, choice)) return true;

    }
    else if (choice == 2){
        if (X != 2 && Y != 2 && (island[X-1][Y-1] == 'f' || island[X-1][Y-1] == 'w')) return true;

        else if (X != 2 && (island[X-1][Y] == 'f' || island[X-1][Y] == 'w' || island[X-1][Y] == '.')) return true;
        else if (X != 2 && Y != 21 && (island[X-1][Y+1] == 'f' || island[X-1][Y+1] == 'w' || island[X-1][Y+1] == '.')) return true;
        else if (Y != 21 && (island[X][Y+1] == 'f' || island[X][Y+1] == 'w' || island[X][Y+1] == '.')) return true;
        else if (X != 21 && Y != 21 && (island[X+1][Y+1] == 'f' || island[X+1][Y+1] == 'w' || island[X+1][Y+1] == '.')) return true;
        else if (X != 21 && (island[X+1][Y] == 'f' || island[X+1][Y] == 'w' || island[X+1][Y] == '.')) return true;
        else if (X != 21 && Y != 2 && (island[X+1][Y-1] == 'f' || island[X+1][Y-1] == 'w' || island[X+1][Y-1] == '.')) return true;
        else if (Y != 2 && (island[X][Y-1] == 'f' || island[X][Y-1] == 'w' || island[X][Y-1] == '.')) return true;

    }

    else if (choice == 3){
        if (X != 2 && Y != 2 && island[X-1][Y-1] == '.') return true;

        else if (X != 2 && island[X-1][Y] == '.') return true;
        else if (X != 2 && Y != 21 && island[X-1][Y+1] == '.') return true;
        else if (Y != 21 && island[X][Y+1] == '.') return true;
        else if (X != 21 && Y != 21 && island[X+1][Y+1] == '.') return true;
        else if (X != 21 && island[X+1][Y] == '.') return true;
        else if (X != 21 && Y != 2 && island[X+1][Y-1] == '.') return true;
        else if (Y != 2 && island[X][Y-1] == '.' ) return true;
    }

    return false;
}

void Born(vector <Rabbit> &rabbits, char island[][25], int number){
    for (int i = 0; i < number; i++){
        rabbits.push_back(Rabbit(island));
    }
}

void Born(vector <Wolf> &wolves, char island[][25], int number){
    for (int i = 0; i < number; i++){
        wolves.push_back(Wolf(island));
    }
}

void Born(vector <Wolfess> &wolfess, char island[][25], int number){
    for (int i = 0; i < number; i++){
        wolfess.push_back(Wolfess(island));
    }
}

void Birth(vector <Rabbit> &rabbits, char island[][25], int X, int Y){
    int r;
    while (true) {
        r = rand()%8;
        switch(r) {
            case 0: {
                if (X != 2 && Y != 2 && island[X-1][Y-1] == '.'){
                    rabbits.push_back(Rabbit(X-1, Y-1, island));
                    return;
                }
                else break;
            }
            case 1: {
                if (X != 2 && island[X-1][Y] == '.'){
                    rabbits.push_back(Rabbit(X-1, Y, island));
                    return;
                }
                else break;
            }
            case 2: {
                if (X != 2 && Y != 21 && island[X-1][Y+1] == '.'){
                    rabbits.push_back(Rabbit(X-1, Y+1, island));
                    return;
                }
                else break;
            }
            case 3: {
                if (Y != 21 && island[X][Y+1] == '.'){
                    rabbits.push_back(Rabbit(X, Y+1, island));
                    return;
                }
                else break;
            }
            case 4: {
                if (X != 21 && Y != 21 && island[X+1][Y+1] == '.'){
                    rabbits.push_back(Rabbit(X+1, Y+1, island));
                    return;
                }
                else break;
            }
            case 5: {
                if (X != 21 && island[X+1][Y] == '.'){
                    rabbits.push_back(Rabbit(X+1, Y, island));
                    return;
                }
                else break;
            }
            case 6: {
                if (X != 21 && Y != 2 && island[X+1][Y-1] == '.'){
                    rabbits.push_back(Rabbit(X+1, Y-1, island));
                    return;
                }
                else break;
            }
            case 7: {
                if (Y != 2 && island[X][Y-1] == '.'){
                    rabbits.push_back(Rabbit(X, Y-1, island));
                    return;
                }
                else break;
            }
        }
    }
}

void Birth(vector <Wolfess> &wolfess, vector <Wolf>&wolves, char island[][25], int X, int Y){
    int r;
    while (true) {
        r = rand()%8;
        switch(r) {
            case 0: {
                if (X != 2 && Y != 2 && island[X-1][Y-1] == '.'){
                    r = rand()%2;
                    if (r == 0) wolfess.push_back(Wolfess(X-1, Y-1, island));
                    else wolves.push_back(Wolf(X-1, Y-1, island));
                    return;
                }
                else break;
            }
            case 1: {
                if (X != 2 && island[X-1][Y] == '.'){
                    r = rand()%2;
                    if (r == 0) wolfess.push_back(Wolfess(X-1, Y, island));
                    else wolves.push_back(Wolf(X-1, Y, island));
                    return;
                }
                else break;
            }
            case 2: {
                if (X != 2 && Y != 21 && island[X-1][Y+1] == '.'){
                    r = rand()%2;
                    if (r == 0) wolfess.push_back(Wolfess(X-1, Y+1, island));
                    else wolves.push_back(Wolf(X-1, Y+1, island));
                    return;
                }
                else break;
            }
            case 3: {
                if (Y != 21 && island[X][Y+1] == '.'){
                    r = rand()%2;
                    if (r == 0) wolfess.push_back(Wolfess(X, Y+1, island));
                    else wolves.push_back(Wolf(X, Y+1, island));
                    return;
                }
                else break;
            }
            case 4: {
                if (X != 21 && Y != 21 && island[X+1][Y+1] == '.'){
                    r = rand()%2;
                    if (r == 0) wolfess.push_back(Wolfess(X+1, Y+1, island));
                    else wolves.push_back(Wolf(X+1, Y+1, island));
                    return;
                }
                else break;
            }
            case 5: {
                if (X != 21 && island[X+1][Y] == '.'){
                    r = rand()%2;
                    if (r == 0) wolfess.push_back(Wolfess(X+1, Y, island));
                    else wolves.push_back(Wolf(X+1, Y, island));
                    return;
                }
                else break;
            }
            case 6: {
                if (X != 21 && Y != 2 && island[X+1][Y-1] == '.'){
                    r = rand()%2;
                    if (r == 0) wolfess.push_back(Wolfess(X+1, Y-1, island));
                    else wolves.push_back(Wolf(X+1, Y-1, island));
                    return;
                }
                else break;
            }
            case 7: {
                if (Y != 2 && island[X][Y-1] == '.'){
                    r = rand()%2;
                    if (r == 0) wolfess.push_back(Wolfess(X, Y-1, island));
                    else wolves.push_back(Wolf(X, Y-1, island));
                    return;
                }
                else break;
            }
        }
    }
}

void refreshMap(Sprite &sMap){
    for (int i = 0; i < HEIGHT; i++){
        for (int j = 0; j < WIDTH; j++){
            if (island[i][j] == '.') sMap.setTextureRect(IntRect(224, 0, 32, 32));
            else if (island[i][j] == 'W') sMap.setTextureRect(IntRect(256, 0, 32, 32));
            else if (island[i][j] == 'S') sMap.setTextureRect(IntRect(288, 0, 32, 32));
            else if (island[i][j] == 'w') sMap.setTextureRect(IntRect(0, 0, 32, 32));
            else if (island[i][j] == 'f') sMap.setTextureRect(IntRect(32, 0, 32, 32));
            else if (island[i][j] == 'r') sMap.setTextureRect(IntRect(64, 0, 32, 32));
            else if (island[i][j] == 'B') sMap.setTextureRect(IntRect(96, 0, 32, 32));
            else if (island[i][j] == 'K') sMap.setTextureRect(IntRect(128, 0, 32, 32));
            else if (island[i][j] == 'C') sMap.setTextureRect(IntRect(160, 0, 32, 32));
            else if (island[i][j] == 'A') sMap.setTextureRect(IntRect(192, 0, 32, 32));

            sMap.setPosition(j*32, i*32);
            window.draw(sMap);
        }
    }
}


#endif // FUNCTIONS_H_INCLUDED
