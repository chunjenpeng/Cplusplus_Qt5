#include <chrono>
#include <cstdlib>
#include <iostream>
#include <vector>

#include "map.h"
#include "randomAgent.h"
#include "game.h"

using std::vector; using std::cout; using std::endl; using std::cin;

Game::Game(int w, int h) {
    //mapPtr = new Map(w, h);
    mapPtr = new Map(w, h);
    hasEnd = false;

     
    Agent* agent = new Agent( 2, Position(1,h-2), "agent", "plate" );
    mapPtr->addObject( agent->getPosition(), agent->getCar() );
    agents.push_back(agent);

    RandomAgent* agent2 = new RandomAgent( 2, Position(w-2,h-2), "agent", "plate" );
    mapPtr->addObject( agent2->getPosition(), agent2->getCar() );
    agents.push_back(agent2);
    
    kbAgent = new KeyboardAgent( 3, Position(1,1), "agent", "plate" );
    mapPtr->addObject( kbAgent->getPosition(), kbAgent->getCar() );
    agents.push_back(kbAgent);
    
}

Game::~Game() {
    delete mapPtr;
}

void Game::run() {

    for( Agent* agent : agents ) {
        moveAgent(agent);
    }

}

bool Game::moveAgent( Agent* agent ) {

    bool moved = false;
    Position nextPos = agent->getNextPosition( mapPtr );
    Position currentPos = agent->getPosition();
    if( currentPos.x == nextPos.x && currentPos.y == nextPos.y ) {
        return false;
    }

    Type nextType = mapPtr->at(nextPos)->getType();
    switch( nextType ) {
        case EMPTY: {
            moved = mapPtr->moveObject( currentPos, nextPos );
            if( moved ) {
                agent->setPosition( nextPos );
            }
            break;
        }
        case WALL: {
            break;
        }
        case CAR: {
            break;
        }
        case PARK: {
            bool Parked = mapPtr->at(nextPos)->join( agent->getCar() );
            if( Parked ) {
                Position generationPoint = Position(1,1);
                moved = mapPtr->moveObject( currentPos, generationPoint );
                if( moved ) {
                    agent->setPosition( generationPoint );
                }
            }
            break;
        }
        default: {
            moved = false;
        }
    }
    return moved;
}


bool Game::shouldTerminate() {
    return hasEnd;
}

void Game::printStatus() const {
}
