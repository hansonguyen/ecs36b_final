#ifndef AUTOMOBILE_H
#define AUTOMOBILE_H
#include <string>
#include "ecs36b_Common.h"

using namespace std;

class Automobile {
    private:   
        string model;
        string warning;
        string cargo;
        int passengers;
        double safetyRating;
        double value;

    public:

        Automobile(string m, string w, string c, int p, double s, double v);

        Automobile();

        void setModel(string m);
        void setWarning(string w);
        void setCargo(string c);
        void setPassengers(int p);
        void setSafetyRating(double s);
        void setValue(double v);

        string getModel();
        string getWarning();
        string getCargo();
        int getPassengers();
        double getSafetyRating();
        double getValue();

        Json::Value dump2JSON();

        bool JSON2Object(Json::Value);
};
#endif