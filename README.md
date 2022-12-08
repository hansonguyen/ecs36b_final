# ECS36B Fall 2022 Final - Self-Driving Car
This program uses JSON-RPC to simulate multiple autonomous vehicles communicating with each other.
## Developers
Hanson Nguyen: 919227725  
Alfredo Nieto: 917137244  
Bryant Gonzalez: 918470625  
Aidan Tongco: 919388431
## How to run
Compile with make
```bash
make
```
Run servers in this order:
1. Left Motorcycle
```bash
./LeftMotorcycleServer
```
2. Right Motorcycle
```bash
./RightMotorcycleServer
```
3. Car
```bash
./CarServer
```
## TODO
1. Implement collision score formulas for Car and Motorcycles classes
    - Car.cpp and Motorcycle.cpp
    - This can be more complex when we account for things like cargo, number of passengers, etc.
2. Car decision making
    - CarServer.cpp
    - Need to finalize what the car should do when it makes a decision (maybe just print which way it would go?)
## Temporary Notes
- There is already some made-up data for a car with a warning and the two motorcycles. This can be changed as needed for testing purposes.