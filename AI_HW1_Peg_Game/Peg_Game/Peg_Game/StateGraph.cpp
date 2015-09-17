
#include "StateGraph.h"



StateGraph:: StateGraph()
{
	int startArr[]={0,0},endArr[]={0,0}, n=3;
	cout <<" What nth sized Peg game would you like to play ?";
	cin>> n; // for test purposes value will be fixed;
	//n = 3;
	cout<< "Please input the start coordinates of the empty spot as x and y: ";
	cin >>startArr[0];
	//startArr[0]=0;
	cin >> startArr[1];
	//startArr[1] = 0;
	cout<< "Please input the end coordinates of the empty spot as x and y: ";
	cin >>endArr[0];
	//endArr[0] = 0;
	cin >> endArr[1];
	//endArr[1] = 0;

	// inquire for the necessary input for building the board;
	//	NEED IMPLEMENTATION;
	//
	endState = buildBoard(n, endArr);
	stateNode= buildBoard(n,startArr);
	next=stateNode;
	rootState = stateNode;
	


}

/** This function addG(State) adds a state to the graph
 *
 * @param State
 * @return State
 * @precondition  State has been properly defined;
 */
State * StateGraph:: addG(State * vst)
{
		
		return vst;
}

State * StateGraph:: getCurrentNode()
{
	return this->stateNode;
}

State * StateGraph::getNext()
{

	return this->next;
}

void StateGraph::setNext(State * s)
{
	this->next = s;

}

void StateGraph::setCurrentState(State * s)
{
	this->stateNode = s;

}
/** This fucntion checks for end state; it traverses the adjacency array linearly,
* checking for the peg data. If it is not equal to the what the end state is supposed
* to look like, then it returns false;
*
* @param void
* @return null
* @precondition  Windows operating system.

*/
bool StateGraph::checkEndState()
{
	// end state must then be a state where all pegs are false except the one peg in 
	// its desired position;
	int i = 0;
	int n = sizeof(getCurrentNode()->getAdjList());
	while (i < n)
	{
		if (getCurrentNode()->getAdjList()[i].getPegData() != endState->getAdjList()[i].getPegData() )
		{
			return false;
		}

		i++;
	}
	return true;
}