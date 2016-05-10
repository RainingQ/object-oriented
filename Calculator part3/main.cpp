#include "Scan.h"
#include "Calculation.h"
#include "Print.h"
#include<iostream>
#include<fstream>
#include<string>
#include<string.h>
#include<stdlib.h>
#include<queue>
using namespace std;

int main(int argc, char* argv[])
{
	Print out;
	
	string input;
	if (strcmp(argv[1], "-a") == 0)
	{
		input = argv[2];
		out.getResult1(input);
	} 
	
	else if (strcmp(argv[1], "-f") == 0)
	{		
		out.getResult2(argv[2], argv[3]);
	} 
	
	else
	{
		input = argv[1];
		out.getResult3();
	}
	return 0;
}
