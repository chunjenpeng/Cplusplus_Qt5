//#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>

#include "car.h"
#include "map.h"
#include "agent.h"

using std::cout; using std::endl; using std::vector; 

Agent::Agent(size_t _id, const Position& _pos, const std::string &_name, const std::string &_plate) {
    id = _id; 
    agentPos = _pos;
    name = _name;
    car = new Car(_name, _plate);
}

Agent::~Agent() {
    delete car;
}

vector<Position> Agent::getLegalMoves( const Map *map ) {

    // Difference between constructor, reserve(), resize() 
    Position possiblePos( agentPos.x, agentPos.y );
    vector<Position> legalMoves;
    legalMoves.reserve(8);

    if( map->isLegal(possiblePos) ) {
        legalMoves.push_back( possiblePos );
    }

    possiblePos = Position( agentPos.x+1, agentPos.y );
    if( map->isLegal(possiblePos) ) {
        legalMoves.push_back( possiblePos );
    }

    possiblePos = Position( agentPos.x-1, agentPos.y );
    if( map->isLegal(possiblePos) ) {
        legalMoves.push_back( possiblePos );
    }

    possiblePos = Position( agentPos.x, agentPos.y-1 );
    if( map->isLegal(possiblePos) ) {
        legalMoves.push_back( possiblePos );
    }

      
    possiblePos = Position( agentPos.x, agentPos.y+1 );
    if( map->isLegal(possiblePos) ) {
        legalMoves.push_back( possiblePos );
    }

    return legalMoves;
}

Position Agent::getNextPosition( const Map *map ) {
    vector<Position> legalMoves = getLegalMoves( map );
    int r = rand() % legalMoves.size();
    
//    for( Position& p : legalMoves )
//        cout << "legalMove: (" << p.x << ", " << p.y << ")" << endl;
//    cout << "choseMove: (" << legalMoves.at(r).x << ", " << legalMoves.at(r).y << ")" << endl;

    return legalMoves.at(r);
}

void Agent::printStatus() const {
    cout << "{" << endl
         << "\t name: " << name << endl
         << "\t id: " << id << endl
         << "\t position: (" << agentPos.x << ", " << agentPos.y << ")" << endl
         << "}" << endl;
}