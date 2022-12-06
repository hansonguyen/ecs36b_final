#ifndef Motorcycle_H
#define Motorcycle_H
#include <string>
#include "ecs36b_Common.h"
#include "Automobile.h"
using namespace std;

class Motorcycle : public Automobile {
    private:   
        string name;

    public:

        Motorcycle(string n);

        Motorcycle();

        void setName(string n);

        string getName();

        Json::Value dump2JSON();

        bool JSON2Object(Json::Value);
};
#endif