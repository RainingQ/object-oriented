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

	//�����ж������ַ��������ִ����Ȳ�����10λ
	if (!in.checkNumberLen(input))
	{
		return 0;
	}
	
	out.printQueue(in.ToStringQueue(input));

	return 0;
}
