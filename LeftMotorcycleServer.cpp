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

using namespace jsonrpc;
using namespace std;

int main() {
    // Run Left Motorcycle Server
    HttpServer httpserver(7374);
    Myhw5Server s(httpserver, JSONRPC_SERVER_V1V2, "Left Motorcycle");
    while (!s.isDone) {
        s.StartListening();
    }
    s.StopListening();

    // Access everything in Truck map
    for (auto it = s.Car_Map.begin(); it != s.Car_Map.end(); it++) {
        cout << "Safety Rating: " << s.Car_Map[it->first]->getSafetyRating() << endl;
    }

    return 0;
}