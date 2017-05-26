//
// Created by alexij on 29.04.2017.
//

#include "Rabbit.h"
#include <iostream>
#include <cstdlib>

using std::cout;
using std::endl;

Rabbit::Rabbit(char island[][25]){
    do
    {
        X = rand()%20+1;
        Y = rand()%20+1;
    }while(island[X][Y] != '.');

    cout << "X = " << X << ", Y = " << Y << endl;

    island[X][Y] = 'r';
    isReadyToGiveLife = false;
}

Rabbit::Rabbit(int x, int y, char island[][25]){
    X = x;
    Y = y;

    cout << "X = " << X << ", Y = " << Y << "\n";

    island[X][Y] = 'r';
    isReadyToGiveLife = false;
}

bool freeR(char island[][25], int X, int Y){
    if (island[X][Y] == 'r' || island[X][Y] == 'C' || island[X][Y] == 'A' || island[X][Y] == 'K') return false;

    else return true;
}

void Rabbit::doStep(const vector<Rabbit> &rabbits, char island[][25]) {
    int r;
    bool flag = true;
    r = rand() % 9;
    if (r < 1) {
        while (flag) {
            r = rand() % 8;
            switch (r) {
                case 0: {
                    if (X != 2 && Y != 2 && freeR(island, X-1, Y-1)) {
                        if (island[X][Y] == 'K') {
                            cout << "kekik (K - > W), " << X << ' ' << Y << " to " << X-1 << ' ' << Y-1 << "\n";
                            island[X][Y] = 'w';
                        }
                        else if (island[X][Y] == 'C') island[X][Y] = 'f';
                        else if (island[X][Y] == 'A') island[X][Y] = 'B';
                        else island[X][Y] = '.';
                        cout << "From " << X << "  " << Y << " to ";
                        X = X - 1, Y = Y - 1;
                        cout << X << "  " << Y << "\n";
                        if (island[X][Y] == 'w'){
                            cout << "kekik (W - > K), " << X << ' ' << Y << " from " << X+1 << ' ' << Y+1 << "\n";
                            island[X][Y] = 'K';
                        }
                        else if (island[X][Y] == 'f') {cout << "Rabbit to wolfess\n"; island[X][Y] = 'C';}
                        else if (island[X][Y] == 'B') island[X][Y] = 'A';
                        else island[X][Y] = 'r';
                        flag = false;
                        break;
                    } else break;
                }
                case 1: {
                    if (X != 2 && freeR(island, X-1, Y)) {
                        if (island[X][Y] == 'K') {
                            cout << "kekik (K - > W), " << X << ' ' << Y << " to " << X-1 << ' ' << Y << "\n";
                            island[X][Y] = 'w';
                        }
                        else if (island[X][Y] == 'C') island[X][Y] = 'f';
                        else if (island[X][Y] == 'A') island[X][Y] = 'B';
                        else island[X][Y] = '.';
                        cout << "From " << X << "  " << Y << " to ";
                        X = X - 1;
                        cout << X << "  " << Y << "\n";
                        if (island[X][Y] == 'w'){
                            cout << "kekik (W - > K), " << X << ' ' << Y << " from " << X+1 << ' ' << Y << "\n";
                            island[X][Y] = 'K';
                        }
                        else if (island[X][Y] == 'f') {cout << "Rabbit to wolfess\n"; island[X][Y] = 'C';}
                        else if (island[X][Y] == 'B') island[X][Y] = 'A';
                        else island[X][Y] = 'r';
                        flag = false;
                        break;
                    } else break;
                }
                case 2: {
                    if (X != 2 && Y != 21 && freeR(island, X-1, Y+1)) {
                        if (island[X][Y] == 'K') {
                            cout << "kekik (K - > W), " << X << ' ' << Y << " to " << X-1 << ' ' << Y+1 << "\n";
                            island[X][Y] = 'w';
                        }
                        else if (island[X][Y] == 'C') island[X][Y] = 'f';
                        else if (island[X][Y] == 'A') island[X][Y] = 'B';
                        else island[X][Y] = '.';
                        cout << "From " << X << "  " << Y << " to ";
                        X = X - 1, Y = Y + 1;
                        cout << X << "  " << Y << "\n";
                        if (island[X][Y] == 'w'){
                            cout << "kekik (W - > K), " << X << ' ' << Y << " from " << X+1 << ' ' << Y-1 << "\n";
                            island[X][Y] = 'K';
                        }
                        else if (island[X][Y] == 'f') {cout << "Rabbit to wolfess\n"; island[X][Y] = 'C';}
                        else if (island[X][Y] == 'B') island[X][Y] = 'A';
                        else island[X][Y] = 'r';
                        flag = false;
                        break;
                    } else break;
                }
                case 3: {
                    if (Y != 21 && freeR(island, X, Y+1)) {
                        if (island[X][Y] == 'K') {
                            cout << "kekik (K - > W), " << X << ' ' << Y << " to " << X << ' ' << Y+1 << "\n";
                            island[X][Y] = 'w';
                        }
                        else if (island[X][Y] == 'C') island[X][Y] = 'f';
                        else if (island[X][Y] == 'A') island[X][Y] = 'B';
                        else island[X][Y] = '.';
                        cout << "From " << X << "  " << Y << " to ";
                        Y = Y + 1;
                        cout << X << "  " << Y << "\n";
                        if (island[X][Y] == 'w'){
                            cout << "kekik (W - > K), " << X << ' ' << Y << " from " << X << ' ' << Y-1 <<"\n";
                            island[X][Y] = 'K';
                        }
                        else if (island[X][Y] == 'f') {cout << "Rabbit to wolfess\n"; island[X][Y] = 'C';}
                        else if (island[X][Y] == 'B') island[X][Y] = 'A';
                        else island[X][Y] = 'r';
                        flag = false;
                        break;
                    } else break;
                }
                case 4: {
                    if (X != 21 && Y != 21 && freeR(island, X+1, Y+1)) {
                        if (island[X][Y] == 'K') {
                            cout << "kekik (K - > W), " << X << ' ' << Y << " to " << X+1 << ' ' << Y+1 << "\n";
                            island[X][Y] = 'w';
                        }
                        else if (island[X][Y] == 'C') island[X][Y] = 'f';
                        else if (island[X][Y] == 'A') island[X][Y] = 'B';
                        else island[X][Y] = '.';
                        cout << "From " << X << "  " << Y << " to ";
                        X = X + 1, Y = Y + 1;
                        cout << X << "  " << Y << "\n";
                        if (island[X][Y] == 'w'){
                            cout << "kekik (W - > K), " << X << ' ' << Y << " from " << X-1 << ' ' << Y-1 <<"\n";
                            island[X][Y] = 'K';
                        }
                        else if (island[X][Y] == 'f') {cout << "Rabbit to wolfess\n"; island[X][Y] = 'C';}
                        else if (island[X][Y] == 'B') island[X][Y] = 'A';
                        else island[X][Y] = 'r';
                        flag = false;
                        break;
                    } else break;
                }
                case 5: {
                    if (X != 21 && freeR(island, X+1, Y)) {
                        if (island[X][Y] == 'K') {
                            cout << "kekik (K - > W), " << X << ' ' << Y << " to " << X+1 << ' ' << Y << "\n";
                            island[X][Y] = 'w';
                        }
                        else if (island[X][Y] == 'C') island[X][Y] = 'f';
                        else if (island[X][Y] == 'A') island[X][Y] = 'B';
                        else island[X][Y] = '.';
                        cout << "From " << X << "  " << Y << " to ";
                        X = X + 1;
                        cout << X << "  " << Y << "\n";
                        if (island[X][Y] == 'w'){
                            cout << "kekik (W - > K), " << X << ' ' << Y << " from " << X-1 << ' ' << Y <<"\n";
                            island[X][Y] = 'K';
                        }
                        else if (island[X][Y] == 'f') {cout << "Rabbit to wolfess\n"; island[X][Y] = 'C';}
                        else if (island[X][Y] == 'B') island[X][Y] = 'A';
                        else island[X][Y] = 'r';
                        flag = false;
                        break;
                    } else break;
                }
                case 6: {
                    if (X != 21 && Y != 2 && freeR(island, X+1, Y-1)) {
                        if (island[X][Y] == 'K') {
                            cout << "kekik (K - > W), " << X << ' ' << Y << " to " << X+1 << ' ' << Y-1 << "\n";
                            island[X][Y] = 'w';
                        }
                        else if (island[X][Y] == 'C') island[X][Y] = 'f';
                        else if (island[X][Y] == 'A') island[X][Y] = 'B';
                        else island[X][Y] = '.';
                        cout << "From " << X << "  " << Y << " to ";
                        X = X + 1, Y = Y - 1;
                        cout << X << "  " << Y << "\n";
                        if (island[X][Y] == 'w'){
                            cout << "kekik (W - > K), " << X << ' ' << Y << " from " << X-1 << ' ' << Y+1 <<"\n";
                            island[X][Y] = 'K';
                        }
                        else if (island[X][Y] == 'f') {cout << "Rabbit to wolfess\n"; island[X][Y] = 'C';}
                        else if (island[X][Y] == 'B') island[X][Y] = 'A';
                        else island[X][Y] = 'r';
                        flag = false;
                        break;
                    } else break;
                }
                case 7: {
                    if (Y != 2 && freeR(island, X, Y-1)) {
                        if (island[X][Y] == 'K') {
                            cout << "kekik (K - > W), " << X << ' ' << Y << " to " << X << ' ' << Y-1 << "\n";
                            island[X][Y] = 'w';
                        }
                        else if (island[X][Y] == 'C') island[X][Y] = 'f';
                        else if (island[X][Y] == 'A') island[X][Y] = 'B';
                        else island[X][Y] = '.';
                        cout << "From " << X << "  " << Y << " to ";
                        Y = Y - 1;
                        cout << X << "  " << Y << "\n";
                        if (island[X][Y] == 'w'){
                            cout << "kekik (W - > K), " << X << ' ' << Y << " from " << X << ' ' << Y+1 <<"\n";
                            island[X][Y] = 'K';
                        }
                        else if (island[X][Y] == 'f') {cout << "Rabbit to wolfess\n"; island[X][Y] = 'C';}
                        else if (island[X][Y] == 'B') island[X][Y] = 'A';
                        else island[X][Y] = 'r';
                        flag = false;
                        break;
                    } else break;
                }
            }
        }
    }
    r = rand() % 10;
    if (r > 0) {
        isReadyToGiveLife = false;
        return;
    } else isReadyToGiveLife = true;

}

Rabbit::~Rabbit(){cout << "dRabbit dies on " << X << " " << Y << "\n";};
