
#include <iostream>
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
			//State * next;
			short int color;	// 0=white;1=gray;2=black;
			int time;
			int d;
			int ft;
			static int moveIt;
			State * predecessor;

			
		public:
			State();
			State * makeMove(State);
			State * buildBoard(int,int start [],int end []);	// n peg game, start vector, end vector
			void setTime(int);
			void setColor(short int);
			void setFT(int);
			void setD(int);
			
		private:
			
		
	};
	
	
#endif
	