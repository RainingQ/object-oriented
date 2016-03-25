#include "print.h"
#include<iostream>
#include <cstdlib>
#include<string>
#include<queue>
using namespace std;

void Print::printQueue(queue<string> m_q)
{
	while(!m_q.empty())	//调用<queue>中自带的函数，将元素弹出，直至队列为空
	{
		cout << m_q.front() << endl;
		m_q.pop();
	}
}
