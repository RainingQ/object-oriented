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
	//���ڴ�ű�����������������������������
	double num1;
	
	//���ڴ�ż���������������������
	double num2;
	
	//���ڴ���������ȼ���С������ʱ�ȵ�����ֵ���Լ�ѹջʱ����ʱ���� 
	double tempNum;	
	
	//���ڴ���������ȼ���С������ʱ�ȵ�������������Լ�ѹջʱ����ʱ���� 
	string tempOper;
		
	while(!m_q.empty())
	{		
		//m_q.front()Ϊ��������ж�ѹջ��ȥ���� 
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
						m_staOper.pop();	//����������
						m_q.pop();  		//���������� 
					}
					
					else if(m_staOper.top() != "(")
					{
						m_q.pop();			//����������
						num2 = m_staNum.top();
						m_staNum.pop();
						num1 = m_staNum.top();
						m_staNum.pop();
						tempOper = m_staOper.top();
						
						calculate(tempOper, num1, num2);
						
						m_staOper.pop();	//����������������
						m_staOper.pop();	//����������
					}
				}
				
				//m_q.front()Ϊ�Ӽ��˳������ 
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
		
		//m_q.front()Ϊ��ֵ,ת��Ϊdouble��ѹջ 
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
	//�õ������������ 
	
	//��һ������õ����մ� 
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
