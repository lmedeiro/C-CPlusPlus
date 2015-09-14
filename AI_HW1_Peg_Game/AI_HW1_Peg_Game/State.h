
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
			State * next;
			bool color;
			int time;
			int d;
			int ft;
			static int moveIt;

			
		public:
			State();
			State * makeMove(State);
			State * buildBoard(int,int start [],int end []);	// n peg game, start vector, end vector
			
		private:
			
		
	};
	
	
#endif
	