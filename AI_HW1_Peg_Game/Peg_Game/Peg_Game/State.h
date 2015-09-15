
#include <iostream>
#include "Peg.h"
using namespace std;

#ifndef StateClass
#define StateClass
// const


/** This class State will define all of the rules of the 
 * game that will be played. In this case, we are playing a game
 * which is a peg puzzle. 
 * Rules, essential pointers to the game, and essential data will
 * be manipulated and stored through this class;
 *
 * @param void
 * @return null
 * @precondition  Windows operating system.
 */
class State
	{
			State * next;
			short int color;	// 0=white;1=gray;2=black;
			int time;
			int d;
			int ft;
			static int moveIt;
			State * predecessor;
			State * finalState; // model for the final state;
			Peg * peg0,* currPeg, *nextPeg;	// this will be the linked list that will comprise the board;
			
		public:
			State();
			State(int n, int start[], int end[]);
			State * makeMove();
			State * buildBoard(int,int start [],int end []);	// n peg game, start vector, end vector
			void setTime(int);
			short int getColor();
			void setColor(short int);
			void setFT(int);
			void setD(int);
			
		private:
			
		
	};
	
	
#endif
	