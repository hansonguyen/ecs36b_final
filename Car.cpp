#include <string>
#include "Car.h"

using namespace std;

Car::Car(string n) {
    this->name = n;
}

Car::Car() {
    this->name = "";
}

void Car::setName(string n) {this->name = n;}

string Car::getName() {return this->name;}

void Car::calculate() {
    /* TODO
        Edit function to properly calculate collision score for cars
    */
    double score = this->getSafetyRating() * this->getValue();
    this->setCollisionScore(score);
}