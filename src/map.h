#ifndef MAP_H
#define MAP_H

#include "position.h"
#include "object.h"

class Map{
public:
    Map( int w, int h, const std::string config = "default" );
    Map( std::string filename );
    ~Map();

    void printMap() const;
    void printStatus() const;

    int getWidth() const { return width; }
    int getHeight() const { return height; }
    Object* at( const Position& pos ) { return grid[pos.x][pos.y]; }
    Object* at( const int x, const int y ) { return grid[x][y]; }

    void defaultInitialization();
    void dfsInitialization();
    void dfs( const Position& pos );
    Position getAdjacent( const Position& pos, int r );

    bool inBound( const Position& pos ) const;
    bool isLegal( const Position& pos ) const;
    bool canMove( const Position& pos ) const;

    bool addObject( const Position& pos, Object *o );
    bool moveObject( const Position& currentPos, const Position& newPos );

private:
    Object*** grid;
    int width;
    int height;
};

#endif // MAP_H

