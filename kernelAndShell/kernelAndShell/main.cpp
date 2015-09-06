#include <iostream>

#include "kernel.h"
#include "Register.h"
#include "shell.h"
using namespace std;



int main()
{
	//Kernel kernel;
	Shell shell;
	shell.systemCall(8);
	shell.systemCall(1);
	shell.menu();
	getchar();
	return 0;
}