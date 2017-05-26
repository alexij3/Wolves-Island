#ifndef THEWOLVES_H
#define THEWOLVES_H
#include "Rabbit.h"
#include "Animal.h"

class TheWolves : public Animal
{
    public:
        TheWolves(){};

        void eat(){
            Points += 10;
        }

        void starve(){
            Points -= 1;
        }

        short int getPoints(){
            return Points;
        }

        void setRepAbToZero(){
            ReproductionAbility = 0;
        }

        short int getReproductionAbility(){
            return ReproductionAbility;
        }

        virtual ~TheWolves(){};

    protected:
        short int Points;
        short int ReproductionAbility;
};


#endif // THEWOLVES_H
