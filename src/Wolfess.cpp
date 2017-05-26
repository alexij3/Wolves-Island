#include "Wolfess.h"
#include <iostream>
#include <cstdlib>
#include <conio.h>

using namespace std;

Wolfess::Wolfess(char island[][25])
{
    do {
        X = rand() % 21+2;
        Y = rand() % 21+2;
        Points = 10;
        ReproductionAbility = 10;
    }while(island[X][Y] != '.');
    cout << "X = " << X << ", Y = " << Y << endl;
    island[X][Y] = 'f';
    isReadyToGiveLife = false;
}

Wolfess::Wolfess(int x, int y, char island[][25]){
    X = x;
    Y = y;
    Points = 10;
    ReproductionAbility = 10;

    isReadyToGiveLife = false;
    island[X][Y] = 'f';
}


bool freeW(char island[][25], int X, int Y){
    if (island[X][Y] == 'f' || island[X][Y] == 'A' || island[X][Y] == 'B' || island[X][Y] == 'C' || island[X][Y] == 'K') return false;

    else return true;
}

void Wolfess::doMove(char island[][25]){
        if (getPoints() > 1) {
        int r;      // «Ã≤ÕÕ¿ ƒÀﬂ «¡≈–≤√¿ÕÕﬂ ¬»œ¿ƒ Œ¬Œ√Œ "Õ¿œ–ﬂÃ ”"
        bool flag = true;
        while (flag) {
            flag = true;
            r = rand() % 8;
            switch (r) {
                case 0: {
                    //cout << "another cell: " << island[X-1][Y-1] << endl;
                    if (X != 2 && Y != 2 && freeW(island, X-1, Y-1)) {
                        starve();
                        if (island[X][Y] == 'A') island[X][Y] = 'K';
                        else if (island[X][Y] == 'B') island[X][Y] = 'w';
                        else island[X][Y] = '.';
                        X = X - 1, Y = Y - 1;
                        if (island[X][Y] == 'w') island[X][Y] = 'B';
                        else island[X][Y] = 'f';
                        flag = false;
                        break;
                    } else break;
                }
                case 1: {
                    //cout << "another cell: " << island[X-1][Y] << endl;
                    if (X != 2 && freeW(island, X-1, Y)) {
                        starve();
                        if (island[X][Y] == 'A') island[X][Y] = 'K';
                        else if (island[X][Y] == 'B') island[X][Y] = 'w';
                        else island[X][Y] = '.';
                        X = X - 1;
                        if (island[X][Y] == 'w') island[X][Y] = 'B';
                        else island[X][Y] = 'f';
                        flag = false;
                        break;
                    } else break;
                }
                case 2: {
                    //cout << "another cell: " << island[X-1][Y+1] << endl;
                    if (X != 2 && Y != 21 && freeW(island, X-1, Y+1)) {
                        starve();
                        if (island[X][Y] == 'A') island[X][Y] = 'K';
                        else if (island[X][Y] == 'B') island[X][Y] = 'w';
                        else island[X][Y] = '.';
                        X = X - 1, Y = Y + 1;
                        if (island[X][Y] == 'w') island[X][Y] = 'B';
                        else island[X][Y] = 'f';
                        flag = false;
                        break;
                    } else break;
                }
                case 3: {
                    //cout << "another cell: " << island[X][Y+1] << endl;
                    if (Y != 21 && freeW(island, X, Y+1)) {
                        starve();
                        if (island[X][Y] == 'A') island[X][Y] = 'K';
                        else if (island[X][Y] == 'B') island[X][Y] = 'w';
                        else island[X][Y] = '.';
                        Y = Y + 1;
                        if (island[X][Y] == 'w') island[X][Y] = 'B';
                        else island[X][Y] = 'f';
                        flag = false;
                        break;
                    } else break;
                }
                case 4: {
                    //cout << "another cell: " << island[X+1][Y+1] << endl;
                    if (X != 21 && Y != 21 && freeW(island, X+1, Y+1)) {
                        starve();
                        if (island[X][Y] == 'A') island[X][Y] = 'K';
                        else if (island[X][Y] == 'B') island[X][Y] = 'w';
                        else island[X][Y] = '.';
                        X = X + 1, Y = Y + 1;
                        if (island[X][Y] == 'w') island[X][Y] = 'B';
                        else island[X][Y] = 'f';
                        flag = false;
                        break;
                    } else break;
                }
                case 5: {
                    //cout << "another cell: " << island[X+1][Y] << endl;
                    if (X != 21 && freeW(island, X+1, Y)) {
                        starve();
                        if (island[X][Y] == 'A') island[X][Y] = 'K';
                        else if (island[X][Y] == 'B') island[X][Y] = 'w';
                        else island[X][Y] = '.';
                        X = X + 1;
                        if (island[X][Y] == 'w') island[X][Y] = 'B';
                        else island[X][Y] = 'f';
                        flag = false;
                        break;
                    } else break;
                }
                case 6: {
                    //cout << "another cell: " << island[X+1][Y-1] << endl;
                    if (X != 21 && Y != 2 && freeW(island, X+1, Y-1)) {
                        starve();
                        if (island[X][Y] == 'A') island[X][Y] = 'K';
                        else if (island[X][Y] == 'B') island[X][Y] = 'w';
                        else island[X][Y] = '.';
                        X = X + 1, Y = Y - 1;
                        if (island[X][Y] == 'w') island[X][Y] = 'B';
                        else island[X][Y] = 'f';
                        flag = false;
                        break;
                    } else break;
                }
                case 7: {
                    //cout << "another cell: " << island[X][Y-1] << endl;
                    if (Y != 2 && freeW(island, X, Y-1)) {
                        starve();
                        if (island[X][Y] == 'A') island[X][Y] = 'K';
                        else if (island[X][Y] == 'B') island[X][Y] = 'w';
                        else island[X][Y] = '.';
                        Y = Y - 1;
                        if (island[X][Y] == 'w') island[X][Y] = 'B';
                        else island[X][Y] = 'f';
                        flag = false;
                        break;
                    } else break;
                }
            }
        }
    }
    else starve();
}

void Wolfess::doStep(vector<Rabbit> &rabbits, vector<Wolf>&wolves, char island[][25]) {
    if (getReproductionAbility() < 10)
            ReproductionAbility += 1;

    for (int i = 0; i < rabbits.size(); i++){
        if (rabbits[i].getX() == this->X && rabbits[i].getY() == this->Y) {
            eat();
            cout << "eating...\n";
            if (island[X][Y] == 'A'){
                    island[X][Y] = 'B';
            }
            else island[X][Y] = 'f';
            rabbits.erase(rabbits.begin() + i);
            return;
        }
    }

    if (ReproductionAbility == 10){
    for (int i = 0; i < wolves.size(); i++){
        if (wolves[i].getX() == this->X && wolves[i].getY() == this->Y && wolves[i].getReproductionAbility() == 10){
                    isReadyToGiveLife = true;
                    ReproductionAbility = 0;
                    wolves[i].setRepAbToZero();
                    return;
                }
        }
    }

    for (int i = 0; i < rabbits.size(); i++) {
        if (rabbits[i].getX() == this->X - 1 && rabbits[i].getY() == this->Y - 1 && freeW(island, X-1, Y-1)) {
            island[X][Y] = '.';
            X = rabbits[i].getX(), Y = rabbits[i].getY();
            island[X][Y] = 'C';
            return;
        } else if (rabbits[i].getX() == this->X - 1 && rabbits[i].getY() == this->Y && freeW(island, X-1, Y)) {
            island[X][Y] = '.';
            X = rabbits[i].getX(), Y = rabbits[i].getY();
            island[X][Y] = 'C';
            return;
        } else if (rabbits[i].getX() == this->X - 1 && rabbits[i].getY() == this->Y + 1 && freeW(island, X-1, Y+1)) {
            island[X][Y] = '.';
            X = rabbits[i].getX(), Y = rabbits[i].getY();
            island[X][Y] = 'C';
            return;
        } else if (rabbits[i].getX() == this->X && rabbits[i].getY() == this->Y + 1 && freeW(island, X, Y+1)) {
            island[X][Y] = '.';
            X = rabbits[i].getX(), Y = rabbits[i].getY();
            island[X][Y] = 'C';
            return;
        } else if (rabbits[i].getX() == this->X + 1 && rabbits[i].getY() == this->Y + 1 && freeW(island, X+1, Y+1)) {
            island[X][Y] = '.';
            X = rabbits[i].getX(), Y = rabbits[i].getY();
            island[X][Y] = 'C';
            return;
        } else if (rabbits[i].getX() == this->X + 1 && rabbits[i].getY() == this->Y && freeW(island, X+1, Y)) {
            island[X][Y] = '.';
            X = rabbits[i].getX(), Y = rabbits[i].getY();
            island[X][Y] = 'C';
            return;
        } else if (rabbits[i].getX() == this->X + 1 && rabbits[i].getY() == this->Y - 1 && freeW(island, X+1, Y-1)) {
            island[X][Y] = '.';
            X = rabbits[i].getX(), Y = rabbits[i].getY();
            island[X][Y] = 'C';
            return;
        } else if (rabbits[i].getX() == this->X && rabbits[i].getY() == this->Y - 1 && freeW(island, X, Y-1)) {
            island[X][Y] = '.';
            X = rabbits[i].getX(), Y = rabbits[i].getY();
            island[X][Y] = 'C';
            return;
        }
    }
        //cout << "Coords " << X << " " << Y << endl;
        doMove(island);

}

Wolfess::~Wolfess(){}
