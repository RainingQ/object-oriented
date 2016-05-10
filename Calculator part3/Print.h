#ifndef PRINT_H
#define PRINT_H
#include<string>
using namespace std;

class Print
{
	public:
		void getResult1(string input/*, double result*/);
		void getResult2(char* argv1, char* argv2);
		void getResult3(/*double result*/);
		friend class Scan;
		friend class Calculator;
};

#endif
