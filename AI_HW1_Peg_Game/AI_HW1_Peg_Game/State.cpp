
#include "State.h"


State:: State()
{
	color=0;
	predecessor= 0;

}

State * State:: buildBoard(int n,int start [],int end [])
{
	State * s= new State();
	return s;
}

State * State::  makeMove(State s)
{
	State * ss= new State();
	return ss;
}

void State:: setTime(int t)
{
	this->time=t;
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