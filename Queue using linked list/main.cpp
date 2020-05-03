/**
 *  @file    Queue using linked list.cpp
 *  @author  Bahaa Mohamed Abd El-GHANY Mohamed Sehsah.
 *  @section 2
 *  @date    25/10/2016
 *
 *  @brief Data structure and algorithms course, Queue simulation using linked list.
 *
 *  @section DESCRIPTION
 *  Implementation of dynamic queue to store the data
 *  into two queues expressed by even and odd queue,
 *  in which even integers stored in the even queue
 *  and vise versa, by using linked list method
 *  to create each queue.
 */

#include <iostream>
#include <stdlib.h>     //to use exit function.

using namespace std;

struct data
{
	int num;
    data *next;
};

class myqueue
{
private:
    data *Front;        //Pointer to the 1st  element of the queue from type data.
    data *Rear;         //Pointer to the last element of the queue from type data.
public:
	myqueue(void)
	{
		Front = NULL;
		Rear  = NULL;
	}
	void enqueue(int n)
	{
        data *temp = new data;
        temp->num = n;
        temp->next = NULL;
        if(Front == NULL)
        {
            Front = temp;
        }
        else
        {
            Rear->next = temp;
        }
        Rear = temp;
	}
	int dequeue(void)
	{
        int n;
        data *temp;
		if (Front == NULL)      cout << "Empty Queue\n";
		else
        {
            temp = Front;
            n = temp->num;
            Front = Front->next;
            delete temp;
            return n;
        }
	}
	bool isempty(void)
	{
		return (Front == NULL);
	}
	int get_size(void)
	{
        data *temp;
		int counter = 0;
		for (temp = Front; temp != NULL ; temp = temp->next) counter++;
		return counter;
	}
	void print_queue(void)
	{
        data *temp;
		for (temp = Front; temp != NULL ; temp = temp->next)
        cout << temp->num << "\t";
		cout << "\n";
	}
	void Clear(void)
	{
        data *temp;
		while (Front != NULL)
		{
			temp = Front;
			Front = Front->next;
			delete temp;
		}
	}
};

int main(void)
{
	int choice , Size , num , k=0;
    myqueue  odd, even;
    while(1)
    {
        cout << "----------------------------------------------------------\n";
        cout<<"Please choose an operation:"<<endl;
        cout<<"Enter  1  to enqueue:"<<endl;
        cout<<"Enter  2  to dequeue even:"<<endl;
        cout<<"Enter  3  to dequeue odd:"<<endl;
        cout<<"Enter  4  to print the even queue:"<<endl;
        cout<<"Enter  5  to print the odd queue:"<<endl;
        cout<<"Enter  6  to print all:"<<endl;
        cout<<"Enter  7  to get odd queue number of elements:"<<endl;
        cout<<"Enter  8  to get even queue number of elements:"<<endl;
        cout<<"Enter  9  to clear odd queue:"<<endl;
        cout<<"Enter  10 to clear even queue:"<<endl;
        cout<<"Enter  0 to exit:"<<endl;
        cout<<"Your Choice is :";
        cin>>choice;
        cout<<endl;

        if(choice==0)           exit(0);
        else if(choice==1)
        {
            //Enqueue.
            cout << "Number[" << k+1 << "] = ";
            cin  >> num;
            if (num % 2 == 0)   even.enqueue(num);
            else                odd.enqueue(num);
            k++;
        }
        else if(choice==2)
        {
            //Dequeue even element.
            if(even.isempty() == false)
            cout<<"Even element = "<<even.dequeue()<<endl<<endl;
            else                        cout<<"Even Queue is empty.\n"<<endl;
        }
        else if(choice==3)
        {
            //Dequeue odd element.
            if(odd.isempty() == false)
            cout<<"Odd element = "<<odd.dequeue()<<endl<<endl;
            else                        cout<<"Odd Queue is empty.\n"<<endl;
        }
        else if(choice==4)
        {
            //Print the even queue.
            if(even.isempty() == false)
            {
                cout << "Even numbers are:\n";
                while (even.isempty() == false)     cout << even.dequeue() << "\t";
                cout <<endl;
            }
            else    cout<<"Even Queue is empty.\n"<<endl;
        }
        else if(choice==5)
        {
            //Print the odd queue.
            if(odd.isempty() == false)
            {
                cout << "\nOdd numbers are:\n";
                while (odd.isempty() == false)      cout << odd.dequeue() << "\t";
                cout <<endl;
            }
            else    cout<<"Odd Queue is empty.\n"<<endl;
        }
        else if(choice==6)
        {
            //Print both queues.
            cout << "----------------------------------------------------------\n";
            cout << "Even numbers are: \n";
            if(even.isempty() == true)                  cout<<"Even Queue is empty.";
            else    while (even.isempty() == false)     cout << even.dequeue() << "\t";
            cout <<endl;
            cout << "\nOdd numbers are: \n";
            if(odd.isempty() == true)                   cout<<"Odd Queue is empty.";
            else    while (odd.isempty() == false)      cout << odd.dequeue() << "\t";
            cout <<endl;
        }
        else if(choice==7)
        {
            //Get odd queue size.
            cout<<"Odd Queue size = "<<odd.get_size()<<endl<<endl;
        }
        else if(choice==8)
        {
            //Get even queue size.
           cout<<"Even Queue size = "<<even.get_size()<<endl<<endl;
        }
        else if(choice==9)
        {
            //Clear odd queue.
            odd.Clear();
            cout<<"Odd Queue was cleared."<<endl<<endl;
        }
        else if(choice==10)
        {
            //Clear even queue.
            even.Clear();
           cout<<"Even Queue was cleared."<<endl<<endl;
        }
        else
        {
            //In case of invalid choice taken from the user.
            cout<<"Please enter invalid choice !!!"<<endl;
        }
    }
}
