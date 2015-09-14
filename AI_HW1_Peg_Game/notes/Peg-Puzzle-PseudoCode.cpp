// Pseudo Code for N-Peg Game solution;
	
	
	
	/** This portion runs the program. It is the main function; 
	 *
	 * @param void
	 * @return int;
	 * @precondition  Windows operating system.
	 */
	// Main flow of the program;
	int main ()
	{
		StateGraph STG= new StateGraph();	// initializing the new state graph;
	
		State game= new State();
		game.buildBoard();// By default there is first move;
		// the previous function also inquires for the initial variables: n,ns_xy[],nf_xy[]; 
		int time =0; // time keeper; 
		int i=0; // iterator;
		int * numOfPossibleMoves= new int [2]; // starting a tracker for the number of possible moves;
		// This is just for experimental purposes at t	he moment;
		
		STG.initiateGame(game);	// start the game; Pass the created puzzle game to the State Graph
		// the STG is the playing machine;
		
		GameProcessor runGame=new GameProcessor (); // starting the processing Unit of the game;
		// this is a generalization, so multiple forms of processing the same game may be implemented
		// For this version, only DFS will be implemented;
		runGame.DFS(STG);	// starting the game ;
		
		
	}
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
class 
	class GameProcessor: public StateGraph
	{
		
		public:
			GameProcessor();
			//GameProcessor(StateGraph);
			bool DFS(StateGraph);	// the DFS algo;
			bool visit-next(StateGraph,PPuzzle);
			
			
		private:
		
		
	};
	
	
#endif	




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
class 
	class StateGraph: public PPuzzle
	{
		
		public:
			StateGraph addG(PPuzzle);
		
		private:
		
		
	};
	
	
#endif

#ifndef PPuzzleClass
#define PPuzzleClass
// const


/** This class PPuzzle will define all of the rules of the 
 * game that will be played. In this case, we are playing a game
 * which is a peg puzzle. 
 * Rules, essential pointers to the game, and essential data will
 * be manipulated and stored through this class;
 *
 * @param void
 * @return null
 * @precondition  Windows operating system.
 */
class 
	class PPuzzle
	{
			PPuzzle * next;
			
		public:
			PPuzzle makeMove();
			
		private:
			
		
	};
	
	
#endif
	
	
/*
	Begin implementation of classes;
	
*/
	
bool GameProcess::  DFS(StateGraph G)
{
	
	
}

bool GameProcess:: visit-next(StateGraph G, PPuzzle v)
{
	
	
}
	


PPuzzle StateGraph:: add(PPuzzle vst)
{
	
		return vst;
}



	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	