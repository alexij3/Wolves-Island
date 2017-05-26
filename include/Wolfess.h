
// Created by alexij on 29.04.2017.
//

#ifndef WOLVESISLANDCOURSEWORK_WOLFESS_H
#define WOLVESISLANDCOURSEWORK_WOLFESS_H

#include <vector>
#include "TheWolves.h"
#include "Wolf.h"

class Wolfess : public TheWolves{
    public:
        Wolfess(){};
        Wolfess(char[][21]);
        Wolfess(int, int, char[][21]);

        bool isReadyToGiveLife;

        void doStep(vector<Rabbit>&, vector<Wolf>&, char[][21]);
        void doMove(char[][21]);

        ~Wolfess();
};


#endif //WOLVESISLANDCOURSEWORK_WOLFESS_H
