#include "Map.h"
#include <iostream>
#include <cmath>
#include "Tracker.h"
using namespace std;

Map::Map(string filepath)
{
	ifstream fin(filepath.c_str());
	if(fin.good())
	{
		length = 0;
		string place;
		int count = 0; // CONCEPT I USE MY LINKED LIST BECAUSE while it will be slower, my safearray leaks even when I just push back
		while(fin.good())
		{
			Cell* spot = new Cell; //FUCKING POINTERS SLAY ME AND THROW ME IN THE GOD DAMNED LAKE ^_^ 
			count++;
			//cout << count;
			fin >> place;
			//cout << place;
			spot -> setType(place);
			//cout << spot -> getType();
			cells.insertAtRear(spot); // Right now, linkedlist of cells that only have set types
			if(spot->getType() == "S")
				setStart(spot);
		}
		//cout << count;
		length = count;
		length = sqrt((float)length); // length of a side
		//magic:
		//cells.at(0) -> setDirection(cells[1], "East");
		for(int i=0; i<count; i++)
		{
			if(i > 0)
			{
				int yCoord = (i/length);
				int xCoord = (i%length);
				cells[i] ->setY(yCoord);
				cells[i] ->setX(xCoord);
//				cout << cells[i] ->getX();
//				cout << cells[i]->getY() << endl;
			}
			//cout << cells[i] -> getType();
			if(i < count && ((i+1) % length) != 0)
			{
				//cout << i;
				cells[i] -> setDirection(cells[i+1], "East");
				//cout << cells[i] -> getType();
				cells[i+1] -> setDirection(cells[i], "West");
				//cout << cells[i+1] ->getType(); // this is gonna take 10ever im so sorry
			}
			if(i/length < 1 && i+length < count)
			{

				cells[i] -> setDirection(cells[i+length], "South");
			}
			else if(i+length >= count)
			{
				cells[i] -> setDirection(cells[i-length], "North");
			}
			else
			{
				cells[i] -> setDirection(cells[i-length], "North");
				cells[i] -> setDirection(cells[i+length], "South");
			}
		}
	}
}
void Map::printCells()
{
	for (int i =0; i< (length * length); i++)
	{
		cout << cells[i] -> getType() << " ";
		if((i%length) == (length-1))
			cout << endl;
	}
}
void Map::setStart(Cell* new_start)
{
	p_start = new_start;
}
Cell* Map::getStart()
{
	return p_start;
}
void Map::printRoute()
{
	cout << endl;
	for (int i =0; i< (length * length); i++)
	{
		if(cells[i] ->isTraversed() && !cells[i]->isDead())
		{
			cout << "O" << " ";
		}
		else
		{
			cout << "X" << " ";
		}
		if((i%length) == (length-1))
			cout << endl;
	}
	cout << "Completed! \\^o^/" << endl;
}
Map::~Map()
{
	for(int i=0; i<(length*length); i++)
	{
		delete cells[i];
		cells[i] = 0;
	}

}