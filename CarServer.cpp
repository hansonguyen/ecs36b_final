// for Json::value
#include <json/json.h>
#include <json/reader.h>
#include <json/writer.h>
#include <json/value.h>
#include <string>

// for JsonRPCCPP
#include <iostream>
#include "hw5server.h"
#include <jsonrpccpp/server/connectors/httpserver.h>
// #include "hw5client.h"
#include <jsonrpccpp/client/connectors/httpclient.h>
#include <stdio.h>

// ecs36b
#include <time.h>
#include "hw5server.cpp"
#include "hw5client.h"

using namespace jsonrpc;
using namespace std;

int main() {
    // Create Initial Objects
    Car myCar;
    myCar.setModel("Toyota");
    myCar.setWarning("Watch out!");
    myCar.setCargo("Food");
    myCar.setPassengers(2);
    myCar.setSafetyRating(3.5);
    myCar.setValue(3);
    cout << myCar.dump2JSON().toStyledString() << endl;

    // Client for Left Motorcycle
    HttpClient httpclient("http://127.0.0.1:7374");
    hw5Client myClient(httpclient, JSONRPC_CLIENT_V2);
    Json::Value myv;
    Json::Value gps;
    gps["location"] = "left motorcycle";

    // Move Truck's warning object
    try {
    myv = myClient.move("move", "Car",
            myCar.dump2JSON(),
            gps,
            "Hanson's Car");
    } catch (JsonRpcException &e) {
    cerr << e.what() << endl;
    }
    cout << "Moving Hanson's Car Info to Left Motorcycle Server..." << endl;
    
    // Run when done moving objects
    Json::Value done;
    try {
    done = myClient.end();
    } catch (JsonRpcException &e) {
    cerr << e.what() << endl;
    }

    //Run Car Server
    HttpServer httpserver(7373);
    Myhw5Server s(httpserver, JSONRPC_SERVER_V1V2, "Car");
    s.StartListening();
    std::cout << "Hit enter to stop the server" << endl;
    getchar();

    s.StopListening();

    return 0;
}