// queue.cpp -- Queue and Customer methods

#include "queue.h"
#include <cstdlib>

// Queue methods

Queue::Queue(int qs) : qsize(qs)
{
	front = rear = NULL;
	items = 0;
}

Queue::~Queue()
{
	Node* tmp;
	while(front != NULL)
	{
		tmp = front;
		front = front->next;
		delete tmp;
	}
}

bool Queue::isempty() const
{
	return items == 0;
}

bool Queue::isfull() const
{
	return items == qsize;
}

int Queue::queuecount() const
{
	return items;
}

bool Queue::enqueue(const Item & item)
{
	if(isfull())
		return false;

	Node* add = new Node;
	add->item = item;
	add->next = NULL;

	items++;

	if(front == NULL)
		front = add;
	else
		rear->next = add;

	rear = add;

	return true;
}

bool Queue::dequeue(Item & item)
{
	if(front == NULL)
		return false;

	item = front->item;
	Node* tmp = front;

	front = front->next;
	delete tmp;

	if(front == NULL)
		rear = NULL;

	return true;
}

// customer method

// when is the time at which the customer arrives
// the arrival time is set to when and the processing
// time set to a random value in the range 1 - 3

void Customer::set(long when)
{
	processtime = std::rand() % 3 + 1;
	arrive = when;
}
