
//
// Created by alexij on 29.04.2017.
//

#ifndef WOLVESISLANDCOURSEWORK_ANIMAL_H
#define WOLVESISLANDCOURSEWORK_ANIMAL_H

class Animal {
    public:
        Animal(){};

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

        virtual ~Animal(){};

    protected:
        int X,
            Y;
};

#endif //WOLVESISLANDCOURSEWORK_ANIMAL_H
