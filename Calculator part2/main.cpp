#include "scan.h"
#include "calculation.h" 
#include<iostream>
#include<string>
#include<queue>
using namespace std;

int main(int argc, char* argv[])
{
	Scan in;
	
	Calculation cal;

	string input;
	
	//将传入表达式值赋给input 
	if(argv[1] == "-a")
	{
		cout << argv[2] << "= ";
		input = argv[2];
	} 
	else
	{
		input = argv[1];
	}
	
	//首先判断输入字符串中数字串长度不超过10位
	if (!in.checkNumberLen(input))
	{
		return 0;
	}
	
	cal.getQueue(in.ToStringQueue(input));

	return 0;
}

