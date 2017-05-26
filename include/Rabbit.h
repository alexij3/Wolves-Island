//
// Created by alexij on 29.04.2017.
//

#ifndef WOLVESISLANDCOURSEWORK_RABBIT_H
#define WOLVESISLANDCOURSEWORK_RABBIT_H

#include <vector>
#include "Animal.h"

using std::vector;

class Rabbit : public Animal{
    public:
        Rabbit(char[][25]);
        Rabbit(int, int, char[][25]);

        void setX(int _x){
            X = _x;
        }

        void setY(int _y){
            Y = _y;
        }

        int getX(){
            return X;
        }

        int getY(){
            return Y;
        }

        void doStep(const vector<Rabbit>&, char[][25]);

        bool isReadyToGiveLife;
        bool life;

        ~Rabbit();
};


#endif //WOLVESISLANDCOURSEWORK_RABBIT_H
