/*
Steven Nava
A2 Queue Example
Professor Mitzel
CSC300 D30

Below are the method definitions used in the queue example.
*/

#include "pqueue.h"
using namespace std;

//Constructor
PQUEUE::PQUEUE()
{
	front = NULL;
    back = NULL;
}

//Destructor
PQUEUE::~PQUEUE()
{
    while (front != NULL)
    {
        node* tmp = front;
        front = front->next;
        delete(tmp);
    }
}

//Adds item into queue at back (end) of queue
void PQUEUE::enq(int num)
{
    node* newNode = new node;
    newNode->val = num;
    newNode->previous = NULL;
    newNode->next = NULL;
    //if front is empty
    if (front == NULL)
    {
        //set both front and back equal to new node
        front = back = newNode;
        return;
    }
    //otherwise
    if (newNode->val <= front->val)
    {
        front->previous = newNode;
        newNode->next = front;
        front = newNode;
        return;
    }
    else if (newNode->val >= back->val)
    {
        newNode->previous = back;
        back->next = newNode;
        back = newNode;
        return;
   }
    else
    {
        node* tmp = front;
        while (tmp != back && tmp->val < newNode->val)
        {
            tmp = tmp->next;
        }
        newNode->previous = tmp->previous;
        tmp->previous->next = newNode;
        tmp->previous = newNode;
        newNode->next = tmp;
        return;
    }
}

//Deletes node from front of queue
bool PQUEUE::deq()
{
    //if front is empty
    if (front == NULL)
    {
        //there is nothing to delete
        return false;
    }
    //if front value equals back
    if (front == back)
    {
        //set both to null
        front = back = NULL;
    }
    //otherwise
    else
    {
        //delete the front of the list
        node* tmp = front;
        front = front->next;
        delete(tmp);
    }
    return true;
}

//Returns front pointer
node* PQUEUE::getFront()
{
    return front;
}

//Tells whether the queue is empty
bool PQUEUE::isEmpty()
{
    //if front is null
    if (front == NULL)
    {
        //queue is empty
        return true;
    }
    //if not, queue contains a value
    return false;
}

//Prints the queue to screen
void PQUEUE::printq()
{
    //if queue is empty
    if (front == NULL)
    {
        //print out 'FRONT: BACK' (i.e. Empty)
        cout << "FRONT: BACK" << endl;
        return;
    }
    //if not
    else
    {
        //prints out queue
        node* tmp = front;
        cout << "FRONT: ";
        while (tmp != NULL)
        {
            cout << tmp->val << " -> ";
            tmp = tmp->next;
        }
        cout << "BACK" << endl;
        return;
    }
}
