#include <fstream>
#include "pqueue.h"
using namespace std;

int main()
{
	PQUEUE myQueue;
	ifstream input;
	int cmd, argument, ret;
    node* frontNode = NULL;
	input.open("cmd.txt");

    // while there is something to read from the file, read
	while (input >> cmd)
	{
        // switch on the command we read from the file
		switch (cmd)
		{
        // if the cmd requires a parameter, read it from the file and call the
        // associated function
		case 1:
			input >> argument;
			myQueue.enq(argument);
            cout << "Added " << argument << " to the queue\n";
			break;
		case 2:
			if(myQueue.deq())
            {
                cout << "Removed front of queue\n";
            }
            else
            {
                cout << "Nothing to remove from the queue\n";
            }
			break;
		case 3:
            frontNode = myQueue.getFront();
            if(NULL == frontNode)
            {
                cout << "Nothing is in the queue\n";
            }
            else
            {
                cout << "Front of the queue contains " << frontNode->val << endl;
            }
            break;
        case 4:
            if(myQueue.isEmpty())
            {
                cout << "Queue is empty\n";
            }
            else
            {
                cout << "Queue has data\n";
            }
            break;
        case 5:
            myQueue.printq();
            break;
        }
	}
	input.close();

	return 0;
}
