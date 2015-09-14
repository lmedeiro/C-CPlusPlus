#include "main.h"


using namespace std;


	
	
	/** This portion runs the program. It is the main function; 
	 *
	 * @param void
	 * @return int;
	 * @precondition  Windows operating system.
	 */
	// Main flow of the program;
int main ()
{
	GameProcessor * runGame= new GameProcessor (); // starting the processing Unit of the game;
	// this is a generalization, so multiple forms of processing the same game may be implemented
	// For this version, only DFS will be implemented;
	//StateGraph STG= new StateGraph();	// initializing the new state graph;
	/*
	State game= new State();
	game.buildBoard();// By default there is first move;
	// the previous function also inquires for the initial variables: n,ns_xy[],nf_xy[]; 
	int time =0; // time keeper; 
	int i=0; // iterator;
	int * numOfPossibleMoves= new int [2]; // starting a tracker for the number of possible moves;
	// This is just for experimental purposes at t	he moment;
		
	STG.initiateGame(game);	// start the game; Pass the created puzzle game to the State Graph
	// the STG is the playing machine;
		
	
	runGame.DFS(STG);	// starting the game ;
	*/
	helloFunc();
	int * pa= new int[2];
	*pa=10;
	*(pa+1)=20;
	cout <<"value of pa[0] "<<*pa<<endl;
	cout <<"value of pa[1] "<<*(pa+1)<<endl;
	getchar();
	return 0;
		
}
