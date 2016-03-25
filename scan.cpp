#include "scan.h"
#include<iostream>
#include<string>
#include<queue>
using namespace std;

bool Scan::checkNumberLen(string input)
{
	int numberLen = 0; 
	
	for (int i = 0; i < input.size(); i++)
	{
		if (input[i] == 45 || input[i] == 47 || (input[i] < 44 && input[i] > 39))
		{
			numberLen = 0;
		}

		else if (input[i] > 47 && input[i] < 58)	//С���㲻�������
		{
			numberLen++;
			
			//���������ִﵽ10λʱ�����˳�
			if (numberLen > 10)
			{
				cout << "[ERROR]The length of number out of ten!" << endl;
				
				return false;
				break;
			}
		}
	}
	
	return true;
}

queue<string> Scan::ToStringQueue(string input)
{
	int numberLen = 0;

	string numbers;		//numbers���ڴ洢���������ַ�
	string operators;	//operatoes���ڴ洢�����ַ�

	for (int i = 0; i < input.size(); i++)
	{
		if (input[i] == 45 || input[i] == 47 || (input[i] < 44 && input[i] > 39))
		{
			
			//���������˳������֣�������һ�����������Ѿ���������ʱ��������ִ��������� 
			if (input[i-1] > 47 && input[i-1] < 58)
			{
				for (int j = i - 1; numberLen > 0; j--, numberLen--)
				{
					numbers = input[j] + numbers;    //����������ַ����һ���������ַ���
				}

				m_q.push(numbers);
				numbers.clear();	//������ַ���numbers
				numberLen = 0;		//��������ִ�����numberLen
			}

			operators = input[i];
			m_q.push(operators);
		}

		else if (input[i] > 47 && input[i] < 58)   //��ASCII�����б�ʾ���ֵķ�Χ
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
