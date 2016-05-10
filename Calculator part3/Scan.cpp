#include "Scan.h"
#include<iostream>
#include<stdlib.h>
#include<string>
#include<queue>
using namespace std;

void Scan::checkNumberLen(string input)
{
	int numberLen = 0; 
	
	for (int i = 0; i < input.size(); i++)
	{
		if (input[i] == 45 || input[i] == 47 || (input[i] < 44 && input[i] > 39))
		{
			numberLen = 0;
		}

		else if (input[i] > 47 && input[i] < 58)	//小数点不参与计数
		{
			numberLen++;
			
			if (numberLen > 10)
			{
				cout << "[ERROR]The length of number out of ten!" << endl;
			}
			exit(3);
		}
	}
}

queue<string> Scan::ToStringQueue(string input)
{
	checkNumberLen(input);
	
	string numbers;	
	string operators;
	
	//特别处理第一个数字是负数的情况 
	int numberLen = 0;
	int i = 0; 
	if(input[0] == '-')
	{
		numberLen++;
		i++;
		
		//特别处理-(-的情况 （一）
		if(input[1] == '(' && input[2] == '-')
		{
			numberLen--;
			i+=2;
		}
	} 

	for (; i < input.size(); i++)
	{
		if (input[i] == 45 || input[i] == 47 || (input[i] < 44 && input[i] > 39))
		{	
			//运算符左端出现数字，则上一串数字序列已经结束，把这个数字串推入序列 
			if (input[i-1] > 47 && input[i-1] < 58)
			{
				for (int j = i - 1; numberLen > 0; j--, numberLen--)
				{
					numbers = input[j] + numbers;
				}

				m_q.push(numbers);
				numbers.clear();
				numberLen = 0;
			}
			
			operators = input[i];
			m_q.push(operators);
			
			if(input[i+1] == '-')
			{
				numberLen++;
				i++; 
				
				//特别处理-(-的情况（二） 
				if(input[i+2] == '(' && input[i+3] == '-')
				{
					numberLen--;
					i+=2;
				}
			}

		}

		else if (input[i] > 47 && input[i] < 58 || input[i] == '.') 
		{
			numberLen++;

			if (i == input.size() - 1)
			{
				for (int j = i; numberLen > 0; j--, numberLen--)
				{
					numbers = input[j] + numbers;
				}

				m_q.push(numbers);
				numbers.clear();
			}
		}
	}
	
	return m_q;
}
