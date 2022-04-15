#include <iostream>
#define MAX 10
using namespace std;


class Queue
{
private:
	int arr[MAX];
	int front, rear;

public:
	Queue()
	{
		arr[0] = 0;
		front = rear = 0;
	}

	void clear()
	{
		front = rear;
	}

	int put(int key)
	{
		if ((rear + 1) % MAX == front)
			return -1;

		rear = ++rear % MAX;
		arr[rear] = key;
		return key;
	}

	int get()
	{
		if (rear == front)
			return -1;

		front = ++front % MAX;
		int t = arr[front];
		return t;
	}

	void print()
	{
		for (int i = front; i != rear; i = ++i % MAX)
		{
			int t = (i + 1) % MAX;
			cout << arr[t] << endl;
		}
	}
};

int main() 
{
	Queue q;

	for (int i = 1; i <= 10; i++)
		q.put(i);

	q.print();


	cout << endl;
	for (int i = 0; i < 3; i++)
		cout << q.get() << endl;

	cout << endl;
	q.print();

	cout << endl;

	q.clear();
	q.print();

	q.put(2);
	q.print();

	return 0;
}