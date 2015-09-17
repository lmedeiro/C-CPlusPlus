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
		i++;
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

Peg & Peg:: operator=(Peg other)
{
	unsigned short i = 0;
	while (i < 2)
	{
		succ[i] = other.succ[i];
		pred[i] = other.pred[i];
		neighb[i] = other.neighb[i];
		i++;
	}
	pegData = other.pegData;
	return *this;
}