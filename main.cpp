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
	cin>>input;
	if(!in.checkNumberLen(input))
	{
		return 0;
	}//�����ж������ַ��������ִ����Ȳ�����10λ
	out.printQueue(in.ToStringQueue(input));
	
	return 0;
}
