#include <string>
#include "Automobile.h"

using namespace std;

Automobile::Automobile(int i, string m, string w, string c, int p, double s, double v, double col) {
    this->id = i;
    this->model = m;
    this->warning = s;
    this->cargo = c;
    this->passengers = p;
    this->safetyRating = s;
    this->value = v;
    this->collisionScore = col;
}

Automobile::Automobile() {
    this->id = 1;
    this->model = "";
    this->warning = "";
    this->cargo = "";
    this->passengers = 0;
    this->safetyRating = 0;
    this->value = 0;
    this->collisionScore = 0;
}

void Automobile::setID(int i) {this->id = i;}

int Automobile::getID() {return this->id;}

void Automobile::setModel(string m) {this->model = m;}

string Automobile::getModel() {return this->model;}

void Automobile::setWarning(string w) {this->warning = w;}

string Automobile::getWarning() {return this->warning;}

void Automobile::setCargo(string c) {this->cargo = c;}

string Automobile::getCargo() {return this->cargo;}

void Automobile::setPassengers(int p) {this->passengers = p;}

int Automobile::getPassengers() {return this->passengers;}

void Automobile::setSafetyRating(double s) {this->safetyRating = s;}

double Automobile::getSafetyRating() {return this->safetyRating;}

void Automobile::setValue(double v) {this->value = v;}

double Automobile::getValue() {return this->value;}

void Automobile::setCollisionScore(double col) {this->collisionScore = col;}

double Automobile::getCollisionScore() {return this->collisionScore;}

Json::Value
Automobile::dump2JSON
() {
    Json::Value result {};
    result["id"] = this->id;
    result["model"] = this->model;
    result["warning"] = this->warning;
    result["cargo"] = this->cargo;
    result["passengers"] = this->passengers;
    result["safetyRating"] = this->safetyRating;
    result["value"] = this->value;
    result["collisionScore"] = this->collisionScore;
    return result;
}

bool Automobile::JSON2Object(Json::Value arg) {
    this->id = (arg["id"]).asInt();
    this->model = (arg["model"]).asString();
    this->warning = (arg["warning"]).asString();
    this->cargo = (arg["cargo"]).asString();
    this->passengers = (arg["passengers"]).asInt();
    this->safetyRating = (arg["safetyRating"]).asDouble();
    this->collisionScore = (arg["collisionScore"]).asDouble();
    return true;
}