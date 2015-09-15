
#include "StateGraph.h"



StateGraph:: StateGraph()
{
	int startArr[]={0,0},endArr[]={0,0}, n=3;
	cout <<" What nth sized Peg game would you like to play ?";
	cin>> n;
	cout<< "Please input the start coordinates of the empty spot as x and y: ";
	cin >>startArr[0];
	cin >> startArr[1];
	cout<< "Please input the end coordinates of the empty spot as x and y: ";
	cin >>endArr[0];
	cin >> endArr[1];

	// inquire for the necessary input for building the board;
	//	NEED IMPLEMENTATION;
	//
	stateNode= buildBoard(n,startArr,endArr);
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