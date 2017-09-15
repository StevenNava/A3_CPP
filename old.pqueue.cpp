#include "pqueue.h"
using namespace std;

PQUEUE::PQUEUE()
{
    front = NULL;
    back = NULL;
}

PQUEUE::~PQUEUE()
{
	node* tmp = front;

	while (tmp != NULL)
	{
		node* tmp = front;
		front = front -> next;
		delete(tmp);
	}
}

void PQUEUE::enq(int num)
{
    node* newNode = new node;
    newNode->val = num;
    newNode->next = NULL;
    //if front is empty
    if (front == NULL)
    {
        //set both front and back equal to new node
        front = back = newNode;
    }
    //otherwise
    else
    {
        //append new node to the back of queue
        back->next = newNode;
        back = newNode;
    }
}

/*void PQUEUE::enq(int num)
{
    node* tmp = front;
	node* newNode = new node;
	newNode->val = num;
	newNode->next = NULL;

	if (front == NULL)
	{
		front = back = newNode;
		return;
	}

	if ((newNode->val) < (front->val))
	{
		front->previous = newNode;
        newNode->next = front;
        newNode->previous = NULL;
	    front = newNode;
    }
	else if (front == back)
    {
        back->next = newNode;
        newNode->previous = back;
        back = newNode;
    }
    else
	{
        while(tmp != back)
        {
            while ((tmp->val < newNode->val))
            {
                tmp = tmp->next;
            }
            newNode->previous = tmp->previous;
            newNode->next = tmp;
            tmp->previous = newNode;
            return;
        }
    }

    newNode->previous = back;
    back->next = newNode;
    back = newNode;
	return;
}
*/

bool PQUEUE::deq()
{
	node* tmp = front;

	if(front == NULL)
	{
		return false;
	}
}

void PQUEUE::printq()
{
	node* tmp = front;

	if (front == NULL)
	{
		cout << "FRONT: BACK" << endl;
		return;
	}

	cout << "FRONT:";
	while (tmp != NULL)
	{
		cout << tmp->val << " -> ";
		tmp = tmp->next;
	}
	cout << "BACK" << endl;
	return;
}

node* PQUEUE::getFront()
{
	return front;
}

bool PQUEUE::isEmpty()
{
	if (front == NULL)
	{
		return true;
	}
	return false;
}
