#ifndef AUTOMOBILE_H
#define AUTOMOBILE_H
#include <string>
#include "ecs36b_Common.h"

using namespace std;

class Automobile {
    private:   
        int id;
        string model;
        string warning;
        string cargo;
        int passengers;
        double safetyRating;
        double value;
        double collisionScore;

    public:

        Automobile(int i, string m, string w, string c, int p, double s, double v, double col);

        Automobile();

        // Getters and Setters
        void setID(int i);
        void setModel(string m);
        void setWarning(string w);
        void setCargo(string c);
        void setPassengers(int p);
        void setSafetyRating(double s);
        void setValue(double v);
        void setCollisionScore(double c);

        int getID();
        string getModel();
        string getWarning();
        string getCargo();
        int getPassengers();
        double getSafetyRating();
        double getValue();
        double getCollisionScore();

        void sendWarning();
        void calculate();

        Json::Value dump2JSON();

        bool JSON2Object(Json::Value);
};
#endif