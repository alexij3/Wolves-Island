#include <cstdlib>
#include <iostream>
#include "Wolf.h"
#include "Wolfess.h"
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <conio.h>
#include <windows.h>

using namespace std;
using namespace sf;

Wolf::Wolf(){};

Wolf::Wolf(char island[][21])
{
    do {
        X = rand() % 20;
        Y = rand() % 20;
        Points = 10;
        ReproductionAbility = 10;
    }while(island[X][Y] != '.');

    isReadyToGiveLife = false;

    island[X][Y] = 'w';
}

Wolf::Wolf(int x, int y, char island[][21]){
    X = x;
    Y = y;
    Points = 10;
    ReproductionAbility = 10;

    isReadyToGiveLife = false;

    island[X][Y] = 'w';
}

bool free(char island[][21], int X, int Y){
    if (island[X][Y] == 'K' || island[X][Y] == 'A' || island[X][Y] == 'B' || island[X][Y] == 'w' || island[X][Y] == 'C') return false;

    else return true;
}

void Wolf::doMove(char island[][21]){
    if (getPoints() > 1) {
        int r;      // �̲��� ��� ���в����� ����������� "��������"
        bool flag = true;
        while (flag) {
              //  cout << "kek\n";
            flag = true;
            r = rand() % 8;
            switch (r) {
                case 0: {
                    if (X != 0 && Y != 0 && island[X-1][Y-1] != 'f' && free(island, X-1, Y-1)) {
                        cout << "X = " << this->getX() << ", Y = " << this->getY() << endl;
                        starve();
                        if (island[X][Y] == 'B') island[X][Y] = 'f';
                        else island[X][Y] = '.';
                        X = X - 1, Y = Y - 1;
                        island[X][Y] = 'w';
                        flag = false;
                        break;
                    } else break;
                }
                case 1: {
                    if (X != 0 && island[X-1][Y] != 'f' && free(island, X-1, Y)) {
                            cout << "X = " << this->getX() << ", Y = " << this->getY() << endl;
                        starve();
                        if (island[X][Y] == 'B') island[X][Y] = 'f';
                        else island[X][Y] = '.';
                        X = X - 1;
                        island[X][Y] = 'w';
                        flag = false;
                        break;
                    } else break;
                }
                case 2: {
                    if (X != 0 && Y != 19 && island[X-1][Y+1] != 'f' && free(island, X-1, Y+1)) {
                            cout << "X = " << this->getX() << ", Y = " << this->getY() << endl;
                        starve();
                        if (island[X][Y] == 'B') island[X][Y] = 'f';
                        else island[X][Y] = '.';
                        X = X - 1, Y = Y + 1;
                        island[X][Y] = 'w';
                        flag = false;
                        break;
                    } else break;
                }
                case 3: {
                    if (Y != 19 && island[X][Y+1] != 'f' && free(island, X, Y+1)) {
                        cout << "X = " << this->getX() << ", Y = " << this->getY() << endl;
                        starve();
                        if (island[X][Y] == 'B') island[X][Y] = 'f';
                        else island[X][Y] = '.';
                        Y = Y + 1;
                        island[X][Y] = 'w';
                        flag = false;
                        break;
                    } else break;
                }
                case 4: {
                    if (X != 19 && Y != 19 && island[X+1][Y+1] != 'f' && free(island, X+1, Y+1)) {
                            cout << "X = " << this->getX() << ", Y = " << this->getY() << endl;
                        starve();
                        if (island[X][Y] == 'B') island[X][Y] = 'f';
                        else island[X][Y] = '.';
                        X = X + 1, Y = Y + 1;
                        island[X][Y] = 'w';
                        flag = false;
                        break;
                    } else break;
                }
                case 5: {
                    if (X != 19 && island[X+1][Y] != 'f' && free(island, X+1, Y)) {
                            cout << "X = " << this->getX() << ", Y = " << this->getY() << endl;
                        starve();
                        if (island[X][Y] == 'B') island[X][Y] = 'f';
                        else island[X][Y] = '.';
                        X = X + 1;
                        island[X][Y] = 'w';
                        flag = false;
                        break;
                    } else break;
                }
                case 6: {
                    if (X != 19 && Y != 0 && island[X+1][Y-1] != 'f' && free(island, X+1, Y-1)) {
                            cout << "X = " << this->getX() << ", Y = " << this->getY() << endl;
                        starve();
                        if (island[X][Y] == 'B') island[X][Y] = 'f';
                        else island[X][Y] = '.';
                        X = X + 1, Y = Y - 1;
                        island[X][Y] = 'w';
                        flag = false;
                        break;
                    } else break;
                }
                case 7: {
                    if (Y != 0 && island[X][Y-1] != 'f' && free(island, X, Y-1)) {
                            cout << "X = " << this->getX() << ", Y = " << this->getY() << endl;
                        starve();
                        if (island[X][Y] == 'B') island[X][Y] = 'f';
                        else island[X][Y] = '.';
                        Y = Y - 1;
                        island[X][Y] = 'w';
                        flag = false;
                        break;
                    } else break;
                }
            }
        }
    }
    else starve();
}

void Wolf::doStep(vector<Rabbit>&rabbits, vector <Wolfess>&wolfess, char island[][21]) {
    if (ReproductionAbility < 10) ReproductionAbility += 1;
       // ����������� �� ������� � �����ʲ�
    for (int i = 0; i < rabbits.size(); i++){
        if (rabbits[i].getX() == this->X && rabbits[i].getY() == this->Y) {
            eat();
            cout << "eating... " << i << ":  " << this->X << " " << this->Y << "\n";
            cout << "Rabbit dieskkk on " << rabbits[i].getX() << " " << rabbits[i].getY() << "\n";
            if (island[X][Y] == 'K') island[X][Y] = 'w';
            else if (island[X][Y] == 'A') island[X][Y] = 'B';
            rabbits.erase(rabbits.begin() + i);
            return;
        }
    }

    if (ReproductionAbility == 10){
    for (int i = 0; i < wolfess.size(); i++){
        if (wolfess[i].getX() == this->X && wolfess[i].getY() == this->Y && wolfess[i].getReproductionAbility() == 10){
                isReadyToGiveLife = true;
                ReproductionAbility = 0;
                wolfess[i].setRepAbToZero();
                return;
            }
        }
    }

    for (int i = 0; i < rabbits.size(); i++) {
        if (rabbits[i].getX() == this->X - 1 && rabbits[i].getY() == this->Y - 1 && free(island, X-1, Y-1)) {
            if (island[X][Y] == 'B') island[X][Y] = 'f';
            else island[X][Y] = '.';
            X = rabbits[i].getX(), Y = rabbits[i].getY();
            island[X][Y] = 'K';
            return;
        } else if (rabbits[i].getX() == this->X - 1 && rabbits[i].getY() == this->Y && free(island, X-1, Y)) {
            if (island[X][Y] == 'B') island[X][Y] = 'f';
            else island[X][Y] = '.';
            X = rabbits[i].getX(), Y = rabbits[i].getY();
            island[X][Y] = 'K';
            return;
        } else if (rabbits[i].getX() == this->X - 1 && rabbits[i].getY() == this->Y + 1 && free(island, X-1, Y+1)) {
            if (island[X][Y] == 'B') island[X][Y] = 'f';
            else island[X][Y] = '.';
            X = rabbits[i].getX(), Y = rabbits[i].getY();
            island[X][Y] = 'K';
            return;
        } else if (rabbits[i].getX() == this->X && rabbits[i].getY() == this->Y + 1 && free(island, X, Y+1)) {
            if (island[X][Y] == 'B') island[X][Y] = 'f';
            else island[X][Y] = '.';
            X = rabbits[i].getX(), Y = rabbits[i].getY();
            island[X][Y] = 'K';
            return;
        } else if (rabbits[i].getX() == this->X + 1 && rabbits[i].getY() == this->Y + 1 && free(island, X+1, Y+1)) {
            if (island[X][Y] == 'B') island[X][Y] = 'f';
            else island[X][Y] = '.';
            X = rabbits[i].getX(), Y = rabbits[i].getY();
            island[X][Y] = 'K';
            return;
        } else if (rabbits[i].getX() == this->X + 1 && rabbits[i].getY() == this->Y && free(island, X+1, Y)) {
            if (island[X][Y] == 'B') island[X][Y] = 'f';
            else island[X][Y] = '.';
            X = rabbits[i].getX(), Y = rabbits[i].getY();
            island[X][Y] = 'K';
            return;
        } else if (rabbits[i].getX() == this->X + 1 && rabbits[i].getY() == this->Y - 1 && free(island, X+1, Y-1)) {
            if (island[X][Y] == 'B') island[X][Y] = 'f';
            else island[X][Y] = '.';
            X = rabbits[i].getX(), Y = rabbits[i].getY();
            island[X][Y] = 'K';
            return;
        } else if (rabbits[i].getX() == this->X && rabbits[i].getY() == this->Y - 1 && free(island, X, Y-1)) {
            if (island[X][Y] == 'B') island[X][Y] = 'f';
            else island[X][Y] = '.';
            X = rabbits[i].getX(), Y = rabbits[i].getY();
            island[X][Y] = 'K';
            return;
        }
    }

    if (ReproductionAbility == 10){
    for (int i = 0; i < wolfess.size(); i++){
            if (wolfess[i].getX() == this->X - 1 && wolfess[i].getY() == this->Y - 1 && wolfess[i].getReproductionAbility() == 10 && free(island, X-1, Y-1)) {
                island[X][Y] = '.';
                X = wolfess[i].getX(), Y = wolfess[i].getY();
                island[X][Y] = 'B';
                return;
            } else if (wolfess[i].getX() == this->X - 1 && wolfess[i].getY() == this->Y && wolfess[i].getReproductionAbility() == 10 && free(island, X-1, Y)) {
                island[X][Y] = '.';
                X = wolfess[i].getX(), Y = wolfess[i].getY();
                island[X][Y] = 'B';
                return;
            } else if (wolfess[i].getX() == this->X - 1 && wolfess[i].getY() == this->Y + 1 && wolfess[i].getReproductionAbility() == 10 && free(island, X-1, Y+1)) {
                island[X][Y] = '.';
                X = wolfess[i].getX(), Y = wolfess[i].getY();
                island[X][Y] = 'B';
                return;
            } else if (wolfess[i].getX() == this->X && wolfess[i].getY() == this->Y + 1 && wolfess[i].getReproductionAbility() == 10 && free(island, X, Y+1)) {
                island[X][Y] = '.';
                X = wolfess[i].getX(), Y = wolfess[i].getY();
                island[X][Y] = 'B';
                return;
            } else if (wolfess[i].getX() == this->X + 1 && wolfess[i].getY() == this->Y + 1 && wolfess[i].getReproductionAbility() == 10 && free(island, X+1, Y+1)) {
                island[X][Y] = '.';
                X = wolfess[i].getX(), Y = wolfess[i].getY();
                island[X][Y] = 'B';
                return;
            } else if (wolfess[i].getX() == this->X + 1 && wolfess[i].getY() == this->Y && wolfess[i].getReproductionAbility() == 10 && free(island, X+1, Y)) {
                island[X][Y] = '.';
                X = wolfess[i].getX(), Y = wolfess[i].getY();
                island[X][Y] = 'B';
                return;
            } else if (wolfess[i].getX() == this->X + 1 && wolfess[i].getY() == this->Y - 1 && wolfess[i].getReproductionAbility() == 10 && free(island, X+1, Y-1)) {
                island[X][Y] = '.';
                X = wolfess[i].getX(), Y = wolfess[i].getY();
                island[X][Y] = 'B';
                return;
            } else if (wolfess[i].getX() == this->X && wolfess[i].getY() == this->Y - 1 && wolfess[i].getReproductionAbility() == 10 && free(island, X, Y-1)) {
                island[X][Y] = '.';
                X = wolfess[i].getX(), Y = wolfess[i].getY();
                island[X][Y] = 'B';
                return;
            }
        }
    }
    /**************************************
       ���� ��� � ����������� ��������,
       ���� �� ������� ������� �� �������
     *************************************/

        doMove(island);


    cout << "Points: " << getPoints() << endl;


}

Wolf::~Wolf(){}
