#include "Peg.h"

Peg::Peg()
{
	// This is the initialization of each peg; By default everything is set to 0;
	// The program using this should manipulate the pegs accordingly so to 
	// create the boundaries necessary
	unsigned short i= 0;
	while (i < 2)
	{
		succ[i] = 0;
		pred[i] = 0;
		neighb[i] = 0;
	}
	pegData = true;

}

bool Peg::getPegData()
{
	return pegData;
}

void Peg::setPegData(bool p)
{
	pegData = p;
}