#include "Calculation.h"
#include<iostream>
#include<string>
#include<stack>
#include<queue>
#include<sstream>
using namespace std;

string Calculation::priority(string oper1, string oper2)
{
	if((oper1 == "*" || oper1 == "/") && (oper2 == "+" || oper2 == "-"))
	{
		return oper1;
	}
	
	else if(oper2 == ")" || oper2 == "(")
	{
		return oper1;
	}
	
	else
	{
		return oper2;
	}
}

void Calculation::calculate(string oper, double num1, double num2)
{
	double result;
	
	if(oper == "+")
	{
		result = num1 + num2;
	}
	
	else if(oper == "-")
	{
		result = num1 - num2;
	}
	
	else if(oper == "*")
	{
		result = num1 * num2;
	}
	
	else if(oper == "/")
	{
		result = num1 / num2;
	}
	
	m_staNum.push(result);
} 

void Calculation::getQueue(queue<string> m_q) 
{
	//用于存放被加数、被减数、被乘数、被除数
	double num1;
	
	//用于存放加数、减数、乘数、除数
	double num2;
	
	//用于存放由于优先级较小，需暂时先弹出的值，以及压栈时的临时变量 
	double tempNum;	
	
	//用于存放由于优先级较小，需暂时先弹出的运算符，以及压栈时的临时变量 
	string tempOper;
		
	while(!m_q.empty())
	{		
		//m_q.front()为运算符，判断压栈，去括号 
		if(m_q.front() == "+" || m_q.front() == "-" || m_q.front() == "*"
		   ||m_q.front() == "/" || m_q.front() == ")" || m_q.front() == "(")
		{
			tempOper = m_q.front();
			
			if(m_staOper.empty())
			{
				m_staOper.push(tempOper);
				m_q.pop(); 
			}
		
			else if(!m_staOper.empty())
			{
				if(m_q.front() == "(")
				{
					m_staOper.push(tempOper);
					m_q.pop();  
				}
				
				else if(m_q.front() == ")")
				{				
					if(m_staOper.top() == "(")
					{
						m_staOper.pop();	//弹出左括号
						m_q.pop();  		//弹出右括号 
					}
					
					else if(m_staOper.top() != "(")
					{
						m_q.pop();			//弹出右括号
						num2 = m_staNum.top();
						m_staNum.pop();
						num1 = m_staNum.top();
						m_staNum.pop();
						tempOper = m_staOper.top();
						
						calculate(tempOper, num1, num2);
						
						m_staOper.pop();	//弹出运算过的运算符
						m_staOper.pop();	//弹出左括号
					}
				}
				
				//m_q.front()为加减乘除运算符 
				else
				{
					if(priority(tempOper, m_staOper.top()) == m_q.front())
					{
						m_staOper.push(tempOper);
						m_q.pop();
					}
					
					else if(priority(m_q.front(), m_staOper.top()) == m_staOper.top())
					{
						num2 = m_staNum.top();
						m_staNum.pop();
						num1 = m_staNum.top();
						m_staNum.pop();
						
						calculate(m_staOper.top(), num1, num2);
						
						m_staOper.pop();
					}
				}
			}
		} 
		
		//m_q.front()为数值,转化为double型压栈 
		else
		{
			stringstream strTodou;
			double num;
			
			strTodou << m_q.front();
			strTodou >> num;
			
			m_staNum.push(num);		
			m_q.pop();
		}
	}
	//得到简单算术表达数 
	
	//进一步运算得到最终答案 
	while(m_staNum.size() != 1)
	{
		if(m_staOper.top() == "(" || m_staOper.top() == ")")
		{
			m_staOper.pop();
		}
		
		else
		{
			tempOper = m_staOper.top();
			m_staOper.pop();
		
			if(m_staOper.empty()
			   || priority(tempOper, m_staOper.top()) == tempOper)
			{
				num2 = m_staNum.top();
				m_staNum.pop();
				num1 = m_staNum.top();
				m_staNum.pop();
				
				calculate(tempOper, num1, num2);
			}
			
			else if(!(m_staOper.empty())
			   		&& priority(tempOper, m_staOper.top()) == m_staOper.top())
			{
				tempOper = m_staOper.top();
				m_staOper.pop();
				tempNum = m_staNum.top();
				m_staNum.pop();
				num2 = m_staNum.top();
				m_staNum.pop();
				num1 = m_staNum.top();
				m_staNum.pop();
				
				calculate(m_staOper.top(), num1, num2);	
				
				m_staNum.push(tempNum);
				m_staOper.push(tempOper);			
			}
		}
	}
	cout << m_staNum.top() << endl;
}
