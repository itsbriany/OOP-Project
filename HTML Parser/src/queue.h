/*
 * queue.h
 *
 *  Created on: 2014-11-08
 *      Author: connor
 */

#ifndef QUEUE_H_
#define QUEUE_H_
#include <iostream>
using namespace std;

template <typename T> class queue
{
private:
	struct node
	{
		T data;
		node *next;
	} *front, *rear;


public:
	void make()
	{
		front = rear = NULL;
	}
	bool isEmpty()
	{
		return (front == NULL && rear == NULL);
	}
	bool isFull()
	{
		return false;
	}
	void enqueue(T x)
	{
		node *temp = new (node);
		temp->data = x;
		temp->next = NULL;

		if(isEmpty())
		{
			//cout << "Adding to empty list\n";
			front = rear = temp;
		}
		else
		{
			//cout << "Adding to non-empty list\n";
			rear->next = temp;
			rear = temp;
		}
	}
	T dequeue()
	{
		if(isEmpty())
		{
			cout << "Empty Queue\n";
			return -1;
		}
		else
		{
			T return_data;
			node *temp = new (node);
			temp = front;
			return_data = temp->data;

			if(front->next == NULL) //Only one element in list
			{
				front = rear = NULL;
				delete (temp);
				return return_data;

			}
			else
			{
				front = front->next;
				delete(temp);
				return return_data;
			}

		}
	}
	void printQueue()
	{
		node *temp = new (node);
		temp = front;

		for(int i=0; i<3; i++)
		{
			cout << temp->data << endl;
			temp = temp->next;
		}
	}
};




#endif /* QUEUE_H_ */
