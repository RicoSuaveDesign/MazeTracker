#include "Cell.h"

Cell::Cell()
{
	x = 0;
	y = 0;
	p_north = 0;
	p_south = 0;
	p_east = 0;
	p_west = 0;
	dead = false;
	traversed = false;
	cType = "lol idk";
}
int Cell::getX()
{
	return x;
}
string Cell::getType()
{
	return cType;
}
void Cell::setX(int& newX)
{
	x = newX;
}
int Cell::getY()
{
	int retVal = y;
	return y;
}
void Cell::setY(int& newY)
{
	y = newY;
}
Cell* Cell::get(string direction)
{
	Cell* retVal; 
	if(direction == "North" || direction == "north")
		retVal = p_north;
	else if(direction == "South" || direction == "south")
		retVal = p_south;
	else if(direction == "East" || direction == "east")
		retVal = p_east;
	else if(direction == "West" || direction == "west")
		retVal = p_west;
	else
		retVal = p_north; // set to north by default so I don't get returned an empty, nonexistent cell by making a typo... 
	return retVal; // .... having a pointer here and not nulling it before it falls out of scope is making me uncomfortable tbh
}
bool Cell::isBlocked()
{
	bool retVal = false;
	if(cType == "B")
		retVal = true;
	return retVal;
}
bool Cell::isTraversed()
{
	return traversed;
}
bool Cell::isDead()
{
	return dead;
}
bool Cell::isEnd()
{
	bool retVal = false;
	if(cType == "E")
		retVal = true;
	return retVal;
}
void Cell::die()
{
	dead = true; 
}
void Cell::traverse()
{
	traversed = true;
}
void Cell::setType(string type)
{
	cType = type;
}
void Cell::setDirection(Cell* dir, string direction)
{
	if(direction == "North")
		p_north = dir; 
	else if(direction == "South")
		p_south = dir;
	else if(direction == "East")
		p_east = dir;
	else if(direction == "West")
		p_west = dir; // you know if this function was misused it could SERIOUSLY fuck shit up, this is probs a memory leak waiting to happen
}
