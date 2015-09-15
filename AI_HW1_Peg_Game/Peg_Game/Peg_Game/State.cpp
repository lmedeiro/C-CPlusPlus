
#include "State.h"


State:: State()
{
	color=0;
	predecessor= 0;
	time = 0;
	d = 0;
	color = 0;
	next = 0;
	moveIt = 0;
	predecessor = 0;
	finalState = 0;
	next = 0;
	peg0 = 0;
	nextPeg = 0;


}
State::State(int n, int start[], int end[])
{
	color = 0;
	predecessor = 0;
	time = 0;
	d = 0;
	color = 0;
	next = 0;
	buildBoard(n, start, end);
	// build initial Board adjacency list according to these specs

	// create a final state According to these specs for comparison; 

}

State * State:: buildBoard(int n,int start [],int end [])
{
	int x = 0, y = 0, ix = 0, iy = 0;
	short int siz = (n*n + n) / 2;	// will always be an even number divided by an even number;
	peg0 = new Peg();

	// need to finish the algorithm
	while (y < n)
	{
		while (x < n)
		{
			currPeg->coord[0] = x;
			x++;
			// link up x coordinates according to a certain function
			// if x is 0, assuming y is not zero, then 
			// four pointers should be created;
			// else if x=0 and y=n-1, then 2 pointers should be 
			// created (to neighbor x and neighbor y-1; 
		}
		currPeg->coord[1] = y;
		y++;
		// if y=n-1 and x>0 and x<n-1, then four pointers 
		// should be created to the other 
		// Check on translating cartesian coordinates to one number or magnitude;
		
	}
	State * s= new State();
	return s;
}

State * State::  makeMove()
{
	// make move based on current state;
	// thus just take the current object pointer and consider the move;
	State * ss= new State();
	return ss;
}

void State:: setTime(int t)
{
	this->time=t;
}
short int State:: getColor()
{
	return this->color;
}
void State:: setColor(short int c)
{
	this->color=c;
}
void State::setFT(int FT)
{
	this->ft=FT;
}
void State:: setD(int D)
{
	this->d=D;
}