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
    myCar.setWarning("Crashing");
    myCar.setCargo("Food");
    myCar.setPassengers(2);
    myCar.setSafetyRating(8.04);
    myCar.setValue(3.6);
    myCar.calculate();
    cout << "Car Information:" << endl << myCar.dump2JSON().toStyledString() << endl;


    // Client for Left Motorcycle
    HttpClient httpclient("http://127.0.0.1:7374");
    hw5Client myClient(httpclient, JSONRPC_CLIENT_V2);
    Json::Value myv;
    Json::Value gps;
    gps["location"] = "left motorcycle";

    // Send Car info (including warning message)) to left motorcycle
    try {
    myv = myClient.move("move", "Car",
            myCar.dump2JSON(),
            gps,
            "Hanson's Car");
    cout << "Sending Hanson's Car Info to Left Motorcycle Server..." << endl;
    } catch (JsonRpcException &e) {
    cerr << e.what() << endl;
    }
    
    // Switch to Client for Right Motorcycle
    HttpClient httpclient2("http://127.0.0.1:7375");
    hw5Client myClient2(httpclient2, JSONRPC_CLIENT_V2);
    Json::Value myv2;
    Json::Value gps2;
    gps2["location"] = "right motorcycle";

    // Send Car info to left motorcycle
    try {
    myv2 = myClient2.move("move", "Car",
            myCar.dump2JSON(),
            gps2,
            "Hanson's Car");
    cout << "Sending Hanson's Car Info to Right Motorcycle Server..." << endl;
    } catch (JsonRpcException &e) {
    cerr << e.what() << endl;
    }

    //Run Car Server
    HttpServer httpserver(7373);
    Myhw5Server s(httpserver, JSONRPC_SERVER_V1V2, "Car");
    s.StartListening();

    // Run when done moving objects
    Json::Value done;
    try {
    done = myClient.end();
    } catch (JsonRpcException &e) {
    cerr << e.what() << endl;
    }
    
    try {
    done = myClient2.end();
    } catch (JsonRpcException &e) {
    cerr << e.what() << endl;
    }

    // Wait to receive data from left and right motorcycles
    while (!s.isDone) {
        s.StartListening();
    }

    // Access everything in Motorcycle map
    for (auto it = s.Motorcycle_Map.begin(); it != s.Motorcycle_Map.end(); it++) {
        // Change this to collect motorcycle data
        cout << "Collision score for motorcycle " << s.Motorcycle_Map[it->first]->getID()  << ": " << s.Motorcycle_Map[it->first]->getCollisionScore() << endl;
    }

    /* TODO
        Once for loop finishes and you store the data from the motorcycles in variables, implement car's decision making here based on the data. Afterwards, maybe send data back to the motorcycle we want choose to crash into to warn again (?)
    */

    // Wait for character input to stop server
    cout << "Press enter to stop server" << endl;
    getchar();
    s.StopListening();

    return 0;
}