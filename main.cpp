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
	
	//��������ʽֵ����input 
	if(argv[1] == "-a")
	{
		cout << argv[2] << "= ";
		input = argv[2];
	} 
	else
	{
		input = argv[1];
	}
	
	//�����ж������ַ��������ִ����Ȳ�����10λ
	if (!in.checkNumberLen(input))
	{
		return 0;
	}
	
	cal.getQueue(in.ToStringQueue(input));

	return 0;
}

