
#include "State.h"


State:: State()
{
	color=0;
	predecessor= 0;
	time = 0;
	d = 0;
	color = 0;
	next = 0;
	//moveIt = 0;
	predecessor = 0;
	finalState = 0;
	next = 0;
	peg0 = 0;
	nextPeg = 0;
	


}
State::State(int n, int start[])
{
	color = 0;
	predecessor = 0;
	time = 0;
	d = 0;
	color = 0;
	next = 0;
	buildBoard(n, start);
	// build initial Board adjacency list according to these specs

	// create a final state According to these specs for comparison; 

}

/** This function does a lot of the heavy lifting; 
* Here we are building the board and all the links as we move along;
* thus we go linearly through the list and programmatically check for the 
* various links to be made according to the position where the pointer is located.
*
* @param nth size of the peg game, the start formation that is desired;
* @return * State
* @precondition  Set Peg function;
*/
State * State:: buildBoard(int n,int start [])
{
	short int x = 0, y = 0, ix = 1, iy = 1;
	short int siz = (n*n + n) / 2;	// will always be an even number divided by an even number;
	pegAdjList = new Peg[siz];
	short int i = 0;
	//Initializing the peg and it's adjancy list;
	// Here we are also initializing the 0th peg, which is a base case;
	peg0 = new Peg();
	peg0 = pegAdjList+0;
	if (n > 1)
		{
			pegAdjList[i].succ[0] = pegAdjList + 1;
			pegAdjList[i].succ[1] = pegAdjList + 2;

		}
	
	y = y + 1;	// second row;
	ix = ix + 1;	// incrementing to the second spot availability now;
	i = i + 1;
	// In order find to every position from the cartesian coordinates and vice versa, the 
	// the following equation may be used:
	// Element #= ((y-1)^2+(y-1))/2 +x, considering that x and y are >=1;
	// Thus consider that these indexes are calculated starting at 1;
	short int err = 0;
	while (y < n)
	{
		x = 0;
		while (x < ix && ix<n)
		{
			//currPeg->coord[0] = x;
			if (x == 0 && y > 0 && y < (n - 1))
			{
				pegAdjList[i].pred[0] = pegAdjList+getPegNum(x, y-1);
				pegAdjList[i].neighb[0] = pegAdjList+getPegNum(x+1, y);
				pegAdjList[i].succ[0] = pegAdjList + getPegNum(x + 1, y + 1);
				pegAdjList[i].succ[1] = pegAdjList + getPegNum(x, y + 1);
			}
			else if (x == 0 && y == n - 1)
			{
				pegAdjList[i].pred[0] = pegAdjList + getPegNum(x, y - 1);
				pegAdjList[i].neighb[0] = pegAdjList + getPegNum(x + 1, y);
			}
			else if (x > 0 && y>0 && y < n - 1 && x < ix)
			{
				pegAdjList[i].pred[0] = pegAdjList + getPegNum(x, y - 1);
				pegAdjList[i].pred[1] = pegAdjList + getPegNum(x-1 , y - 1);
				pegAdjList[i].neighb[0] = pegAdjList + getPegNum(x + 1, y);
				pegAdjList[i].neighb[1] = pegAdjList + getPegNum(x - 1, y);
				pegAdjList[i].succ[0] = pegAdjList + getPegNum(x + 1, y + 1);
				pegAdjList[i].succ[1] = pegAdjList + getPegNum(x, y + 1);
			}
			else if (x == ix && y > 0 && y < (n - 1))
			{
				pegAdjList[i].pred[0] = pegAdjList + getPegNum(x-1, y - 1);
				pegAdjList[i].neighb[0] = pegAdjList + getPegNum(x - 1, y);
				pegAdjList[i].succ[0] = pegAdjList + getPegNum(x + 1, y + 1);
				pegAdjList[i].succ[1] = pegAdjList + getPegNum(x, y + 1);
			}
			else if (x == ix && y == n - 1)
			{
				pegAdjList[i].pred[0] = pegAdjList + getPegNum(x-1, y - 1);
				pegAdjList[i].neighb[0] = pegAdjList + getPegNum(x - 1, y);
			}
			else
			{
				err++;
			}

			// link up x coordinates according to a certain function
			// if x is 0, assuming y is not zero, then 
			// four pointers should be created;
			// else if x=0 and y=n-1, then 2 pointers should be 
			// created (to neighbor x and neighbor y-1; 



			x++;
			ix++;
			i++;
		}
		//currPeg->coord[1] = y;
		
		
		y++;
		// if y=n-1 and x>0 and x<n-1, then four pointers 
		// should be created to the other 
		// Check on translating cartesian coordinates to one number or magnitude;
		
	}
	
	cout << "Build Board is finished. This many errors occured: " << err << endl;
	//State * s= new State();
	return this;
}

State * State::  makeMove()
{
	// make move based on current state;
	// thus just take the current object pointer and consider the move;
	// Need to implement this function;
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
void State::setPred(State * p)
{
	this->next->predecessor = p;

}
Peg * State::getAdjList()
{

	return pegAdjList;
}
short int State::getPegNum(short int x, short int y)
{
	// In order find to every position from the cartesian coordinates and vice versa, the 
	// the following equation may be used:
	// Element #= ((y-1)^2+(y-1))/2 +x, considering that x and y are >=1;
	// Thus consider that these indexes are calculated starting at 1;
	short int elemNum = ((y - 1)*(y-1) + (y - 1)) / 2 + x;

	return elemNum;
}