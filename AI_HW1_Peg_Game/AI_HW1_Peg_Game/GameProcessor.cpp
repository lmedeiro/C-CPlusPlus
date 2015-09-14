
#include "GameProcessor.h"
#include <iostream>

GameProcessor:: GameProcessor()
{
	G= new StateGraph(); // starts all the colors of each vertex (state to white already) and predecessor to null;
	TIME=0;
}

bool GameProcessor::  DFS()
{
	while (G->getCurrentNode()!=0)
	{
		
	}
	return true;	
}

bool GameProcessor:: visit_next(StateGraph * G, State * v)
{
	

	return true;
}
	

