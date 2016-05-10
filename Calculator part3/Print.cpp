#include "Print.h"
#include "Scan.h"
#include "Calculation.h"
#include<fstream>
#include<iostream>
#include<stdlib.h>
#include<string>
using namespace std;

Scan in;
Calculation cal;

string input;

void Print::getResult1(string input)
{
	cout << input << "= " << cal.getQueue(in.ToStringQueue(input)) << endl;
}

void Print::getResult2(char* argv1, char* argv2)
{
	ifstream infile(argv1, ios::in | ios::trunc);
	if(!infile)
	{
		cerr << "Open infile error!" << endl;
		exit(2);
	}
	
	ofstream outfile(argv2, ios::out | ios::trunc);
	if(!outfile)
	{
		cerr << "Open outfile error!" << endl;
		exit(2);
	}
	
	while (getline(infile, input))
	{	
		outfile << cal.getQueue(in.ToStringQueue(input)) << endl;
		cout << cal.getQueue(in.ToStringQueue(input)) << endl;
	}
	
	infile.close();
	outfile.close();
}

void Print::getResult3()
{
	cout << cal.getQueue(in.ToStringQueue(input)) << endl;
}
