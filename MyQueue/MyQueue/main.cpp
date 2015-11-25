#include "MyQueue.h"
#include <iostream>

int main(int argc, char** argv)
{
	MyQueue<int> q;
	q.pushback(0);
	q.pushback(1);
	
	int n = 0;

	q.popfront(n);
	q.popfront(n);
	q.pushback(3);

	getchar();
	return 0;
}