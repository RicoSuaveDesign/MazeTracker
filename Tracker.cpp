#include "Tracker.h"

Tracker::Tracker()
{
	p_currentcell = 0;
}
void Tracker::findPath(Map& themap)
{
	p_currentcell = themap.getStart();
	while(p_currentcell ->getType() != "E")
	{
		next();
	}
	// ....is. is that it????? I don't need to relate the dead? 

}
string Tracker::selectDirection()
{
	string retVal;
	retVal = "North";
	for(int i=0; i<4; i++)
	{
		if((p_currentcell -> get(retVal) == 0) || (p_currentcell -> get(retVal) -> isBlocked()) || (p_currentcell -> get(retVal) -> isTraversed()))
		{
			if(retVal == "North")
				retVal = "South";
			else if(retVal == "South")
				retVal = "East";
			else if(retVal == "East")
				retVal = "West";
			else if(retVal == "West")
				retVal = "No";
		}
		else
			break;
	}
	return retVal;
}
void Tracker::next()
{
	string selectedDirection;
	selectedDirection = selectDirection();
	//cout << selectedDirection;
	if(selectedDirection != "No")
	{
		p_currentcell -> traverse();
		trail.push(p_currentcell);
		p_currentcell = p_currentcell -> get(selectedDirection);
		cout << "Going " << selectedDirection << " X: "  << p_currentcell ->getX() << " Y: " << p_currentcell -> getY()
			<< " Type: " << p_currentcell ->getType() << endl;
	}
	else if(selectedDirection == "No")
	{
		backTrack();
	}

}
void Tracker::backTrack()
{
	Cell* bachelor; // please just let me have this band reference Mark. this cell is where the popped top of the trail will be stored.
	trail.pop(bachelor);
	bachelor -> die(); // THE DEATH OF A BACHELOR. but no really, the trail is dead so gotta mark it as such
	trail.top(p_currentcell);
	cout << "Backtracking from: X: " << bachelor -> getX() << " Y: " << bachelor ->getY() << " Type: " << bachelor ->getType() <<
		" to: X: " << p_currentcell -> getX() << " Y: " << p_currentcell -> getY() << " Type: " << p_currentcell ->getType() << endl;
}
Tracker::~Tracker()
{
	p_currentcell = 0;
}