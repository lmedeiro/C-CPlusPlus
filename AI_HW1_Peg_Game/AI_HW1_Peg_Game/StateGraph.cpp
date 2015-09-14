
#include "StateGraph.h"



StateGraph:: StateGraph()
{
	
	
	int startArr[]={0,0},endArr[]={0,0}, n=3;
	// inquire for the necessary input for building the board;
	//	NEED IMPLEMENTATION;
	//
	stateNode= buildBoard(n,startArr,endArr);
	next=stateNode;
	


}

/** This function addG(State) adds a state to the graph
 *
 * @param State
 * @return State
 * @precondition  State has been properly defined;
 */
State StateGraph:: addG(State vst)
{
		
		return vst;
}

State * StateGraph:: getCurrentNode()
{
	return this->stateNode;
}