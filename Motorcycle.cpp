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

Json::Value
Motorcycle::dump2JSON
() {
    Json::Value result {};
    result["name"] = this->name;
    return result;
}

bool Motorcycle::JSON2Object(Json::Value arg) {
    this->name = (arg["name"]).asString();
    return true;
}