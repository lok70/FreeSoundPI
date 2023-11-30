#include <iostream>
#include "queue.h"

using namespace std;

int main()
{
	setlocale(0, "");
	Queue<int> q;
	q.enqueue(3);
	q.enqueue(4);
	q.enqueue(6);

	Queue<int> q2;
	q2 = q;

	cout << q << "\n";

	q.dequeue();

	cout << q << "\n";

	cout << q2 << "\n";


}