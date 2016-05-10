#ifndef CALCULATION_H
#define CALCULATION_H
#include<iostream>
#include<queue>
#include<stack>
#include<sstream>
#include<string>
using namespace std;

class Calculation
{
	public:
		double getQueue(queue<string> m_q);
		string priority(string oper1, string oper2);
		void calculate(string oper, double num1, double num2);		
	private:
		stack<double> m_staNum;		//���ڴ洢��ֵ 
		stack<string> m_staOper;	//���ڴ洢�����
};

#endif
