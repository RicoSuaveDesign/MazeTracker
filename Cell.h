#pragma once
#include <string>
#include <iostream>
using namespace std;

class Cell
{
public:
	Cell();
	int getX();
	void setX(int& newX);
	int getY();
	void setY(int& newY);
	bool isBlocked();
	bool isEnd();
	void setType(string type);
	string getType();
	Cell* get(string direction);
	void setDirection(Cell* dir, string direction);
	bool isDead();
	void die();
	void traverse();
	bool isTraversed();

private:
	int x;
	int y;
	string cType;
	Cell* p_north;
	Cell* p_south;
	Cell* p_east;
	Cell* p_west; // north, the gates to paradise will open
	bool dead;
	bool traversed;
};