#pragma once
#include "Cell.h"
#include "DoublyLinkedList.h"
#include <fstream>
#include <string>
class Map
{
public:
	Map(string filepath);
	~Map();
	void printCells();
	void setStart(Cell* new_start);
	Cell* getStart();
	void printRoute();
private:
	DoublyLinkedList <Cell*> cells;
	int length;
	Cell* p_start;
};