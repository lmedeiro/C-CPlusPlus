
#include "GameProcessor.h"
#include <iostream>

GameProcessor:: GameProcessor()
{
	G= new StateGraph(); // starts all the colors of each vertex (state to white already) and predecessor to null;
	time=0;
}

bool GameProcessor::  DFS()
{
	// By the time this function has been called, everything has been initialized;
	while (G->getCurrentNode()!=0)
	{
		// THe following is a form of adding the nodes (states) as move along;
		 
		nextState = G->addG(G->getCurrentNode()->makeMove()); // this line is basically referring to the appropriate states.
		G->setNext(nextState);
		// You are basically getting the current node within the graph, and utilizing it to make a move according to this same node;
		// the results is a next state which is returned to the graph. It then utilized to as the argument to the addG() function, 
		// which then adds this state to the state graph adjacency list;
		// the same function addG returns the state it has added to the adj. list of the graph. 
		if (nextState->getColor() == 0)	// if color of the first neighbor is white, then visit that neighbor;
		{
			// the goal is then to visit the each subsequent state that is viable and check if it is the end state;
			// until there are no possibilities within this branch, then back track until there is a possibility for another branch.
			// continuously do this until the solution may be found;
			visit_next(G, G->getNext());
		}


	}
	return true;	
}

bool GameProcessor:: visit_next(StateGraph * STG, State * v)
{
	v->setColor(1);
	time = time + 1;
	v->setD(this->time);
	

	return true;
}
	

