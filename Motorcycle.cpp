#include <string>
#include "Motorcycle.h"

using namespace std;

Motorcycle::Motorcycle(string n) {
    this->name = n;
}

Motorcycle::Motorcycle() {
    this->name = "";
}

void Motorcycle::setName(string n) {this->name = n;}

string Motorcycle::getName() {return this->name;}

void Motorcycle::calculate() {
    /* TODO
        Edit function to properly calculate collision score for motorcycles
    */
    double score = this->getSafetyRating() * this->getValue();
    this->setCollisionScore(score);
}