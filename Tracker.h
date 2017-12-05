#pragma once
#include "Map.h"
#include "LLStack.h"

class Tracker
{
public:
	Tracker();
	~Tracker();
	void findPath(Map& themap);
private:
	Cell* p_currentcell;
	LLStack <Cell*> trail;
	string selectDirection();
	void next();
	void backTrack();
};