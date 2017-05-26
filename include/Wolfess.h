
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
        Wolfess(char[][25]);
        Wolfess(int, int, char[][25]);

        bool isReadyToGiveLife;

        void doStep(vector<Rabbit>&, vector<Wolf>&, char[][25]);
        void doMove(char[][25]);

        ~Wolfess();
};


#endif //WOLVESISLANDCOURSEWORK_WOLFESS_H
