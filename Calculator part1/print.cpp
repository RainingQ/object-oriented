#include "print.h"
#include<iostream>
#include <cstdlib>
#include<string>
#include<queue>
using namespace std;

void Print::printQueue(queue<string> m_q)
{
	while(!m_q.empty())		//����<queue>���Դ��ĺ�������Ԫ�ص�����ֱ������Ϊ��
	{
		cout << m_q.front() << endl;
		m_q.pop();
	}
}
