#include "scan.h"
#include "print.h"
#include<iostream>
#include<string>
#include<queue>
using namespace std;

int main()
{
	Scan in;
	
	Print out;

	string input;
	cin >> input;

	//首先判断输入字符串中数字串长度不超过10位
	if (!in.checkNumberLen(input))
	{
		return 0;
	}
	
	out.printQueue(in.ToStringQueue(input));

	return 0;
}
