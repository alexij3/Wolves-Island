
// Created by alexij on 29.04.2017.
//
#ifndef WOLVESISLANDCOURSEWORK_WOLF_H
#define WOLVESISLANDCOURSEWORK_WOLF_H

#include <vector>
#include <string>
#include "Rabbit.h"
#include "TheWolves.h"

using std::string;

class Wolfess;

class Wolf : public TheWolves{
    public:
        Wolf();
        Wolf(char[][25]);
        Wolf(int, int, char[][25]);
        void eat(){
            Points += 10;
        }

        bool isReadyToGiveLife;

        void doStep(vector<Rabbit>&, vector<Wolfess>&, char [][25]);
        void doMove(char [][25]);
        ~Wolf();
};


#endif //WOLVESISLANDCOURSEWORK_WOLF_H/
