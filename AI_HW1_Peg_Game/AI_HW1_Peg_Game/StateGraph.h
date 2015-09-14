#include <iostream>
#include "State.h"
using namespace std;

#ifndef StateGraphClass
#define StateGraphClass
// const


/** This class StateGraph describes the State graphs of the game.
 * Thus this class will bring about the description containing 
 * the result of each move. A move leads to a certain state.
 * A certain state must be described.
 * Thus, this is the graph itself, when looked from any analytical 
 * standpoint.
 * Vertices of the graphs signify a state resulting from a move. 
 * Edges are the links between the each state; 
 *
 * @param void
 * @return null
 * @precondition  Windows operating system.
 */
class StateGraph: public State
	{

		State * next;
		State * stateNode;	// Node simulating the game state nodes;
		State * predecessor;

		public:
			StateGraph();
			State addG(State);
			State * getCurrentNode();
		
		private:
		
		
	};
	
	
#endif
