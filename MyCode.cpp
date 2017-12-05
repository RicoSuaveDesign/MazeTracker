#include <iostream>
#include "DoublyLinkedList.h"
#include "LLStack.h"
#include "Cell.h"
#include "Map.h"
#include "SafeArray.h"
#include <string>
#include "Tracker.h"
using namespace std;

int main()
 {
    //create a map from a file
    Map map("20x20map.txt");

    //create a tracker capable of traversing through a map
    Tracker tracker;

    //send the tracker to find a path through the map
    tracker.findPath(map);

    //print the original cells from the file
    map.printCells();

    //print an X/O map from the start to the end
    map.printRoute();

	system("pause");
	return 0;
}
//--
