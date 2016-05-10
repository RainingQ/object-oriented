#ifndef SCAN_H
#define SCAN_H
#include<iostream>
#include<queue>
#include<string>
using namespace std;

class Scan
{
	public:
		queue<string> ToStringQueue(string input);
		void checkNumberLen(string input);
	private:
		queue<string> m_q;
};

#endif
