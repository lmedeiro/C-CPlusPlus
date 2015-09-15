#include <iostream>
#include "StateGraph.h"
using namespace std;

#ifndef GameProcessorClass
#define GameProcessorClass
// const


/** This class GameProcessor. The game processor represents the 
 * computational form in which the graph is being traversed and 
 * processed. Thus one may choose to traverse via various Graph
 * algorithms. In the case of the current version of this program,
 * only DFS will be implemented. 
 *
 * @param void
 * @return null
 * @precondition  Windows operating system.
 */
class GameProcessor
	{
		
		StateGraph * G;
		//State * rootState;
		State * nextState;
		//int nPeg,startX,startY,endX,endY;	// coordinates to be filled by user input;
		
		int time;

		public:
			GameProcessor();
			//GameProcessor(StateGraph);
			bool DFS();	// the DFS algo;
			bool visit_next(StateGraph *,State *);
			
			
		private:
		
		
	};
	
	
#endif	
