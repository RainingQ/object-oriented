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
		stack<double> m_staNum;		//用于存储数值 
		stack<string> m_staOper;	//用于存储运算符
};

#endif
