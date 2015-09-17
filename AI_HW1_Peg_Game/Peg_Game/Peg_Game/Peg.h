#include <iostream>

using namespace std;


/** This class takes care of arranging the information of each peg within the
* within the Peg game board;
*
* @param
* @return
* @precondition  Main has been properly defined;
*/

#ifndef PegClass
#define PegClass
class Peg
{
	
	bool pegData;


public:
	Peg * succ[2], *pred[2], *neighb[2]; // these are defined in the public so it 
	// easier for access. that way there is no need to create more accessor functions.
	// We have arrays of twos since there is no more than two pointers per peg;
	int coord[2];
	Peg();
	bool getPegData();
	void setPegData(bool);
	Peg & operator=(Peg other);
	

private:




};

#endif