/**
 *  @file    Queue.cpp
 *  @author  Bahaa Mohamed Abd El-GHANY Mohamed Sehsah.
 *  @section 2
 *  @date    14/10/2016
 *
 *  @brief Data structure and algorithms course, Queue implementation.
 *
 *  @section DESCRIPTION
 *  Implementation of dynamic circular queue to store
 *  the data into two queues expressed by even and odd
 *  queue, in which even integers stored in even queue
 *  and vise versa.
 */

#include <iostream>
#include <stdlib.h>

using namespace std;

class myqueue
{
private:
	int *arr, front, rear, maxsize, counter;
public:
	myqueue(int k)
	{
		arr = new int[k];
		front = rear = counter = 0;
		maxsize = k;
	}
	myqueue(void)
	{
		arr = new int[10];
		front = rear = counter = 0;
		maxsize = 10;
	}
	void enqueue(int d)
	{
		if (counter == maxsize)     doublesize();
		arr[rear] = d;
		rear = (rear + 1) % maxsize;
		counter++;
	}
	int dequeue(void)
	{
		int temp;
		if (counter == 0)           exit(0);
		temp = arr[front];
		front = (front + 1) % maxsize;
		counter--;
        return temp;
	}
	bool isfull(void)
	{
		return(counter == maxsize);
	}
	bool isempty(void)
	{
		return(counter == 0);
	}
	int get_nuumber_of_elements(void)
	{
		return counter;
	}
	int get_max_size(void)
	{
		return maxsize;
	}
    void doublesize(void)
	{
		int *arr2;
		arr2 = new int[maxsize * 2];
		for (int k = 0; k < maxsize; k++)
        {
            arr2[k] = arr[front];
            front = (front + 1) % maxsize;
        }
		delete arr;
		arr = arr2;
		front=0;
		rear=maxsize;
		maxsize = maxsize * 2;
	}
};

int main(void)
{
    int choice , Size , num , k=0;
    do{
        cout<<"Please enter array size:";
        cin>>Size;
    }while(Size<2);
    myqueue  odd(Size/2), even(Size/2);
    while(1)
    {
        do
        {
            cout<<"\nPlease choose an operation:"<<endl;
            cout<<"Enter 1 to enqueue:"<<endl;
            cout<<"Enter 2 to dequeue even:"<<endl;
            cout<<"Enter 3 to dequeue odd:"<<endl;
            cout<<"Enter 4 to print the even queue:"<<endl;
            cout<<"Enter 5 to print the odd queue:"<<endl;
            cout<<"Enter 6 to print all:"<<endl;
            cout<<"Enter 0 to exit:"<<endl;
            cin>>choice;
            cout<<endl;
        }while(choice<0 && choice>5);
        if(choice==0)           exit(0);
        else if(choice==1)
        {
            cout << "Number[" << k+1 << "] = ";
            cin  >> num;
            if (num % 2 == 0)   even.enqueue(num);
            else                odd.enqueue(num);
            k++;
        }
        else if(choice==2)
        {
            if(even.isempty() == false)     cout << even.dequeue()<<endl;
            else                            cout<<"Even Queue is empty."<<endl;
        }
        else if(choice==3)
        {
            if(odd.isempty() == false)      cout << odd.dequeue()<<endl;
            else                            cout<<"Odd Queue is empty."<<endl;
        }
        else if(choice==4)
        {
            if(even.isempty() == false)
            {
                cout << "Even numbers are: \n";
                while (even.isempty() == false)     cout << even.dequeue() << "\t";
                cout <<endl;
            }
            else    cout<<"Even Queue is empty."<<endl;
        }
        else if(choice==5)
        {
            if(odd.isempty() == false)
            {
                cout << "\nOdd numbers are: \n";
                while (odd.isempty() == false)      cout << odd.dequeue() << "\t";
                cout <<endl;
            }
            else    cout<<"Odd Odd is empty."<<endl;
        }
        else if(choice==6)
        {
            cout << "----------------------------------------------------------\n";
            cout << "Even numbers are: \n";
            while (even.isempty() == false)     cout << even.dequeue() << "\t";
            cout <<endl;
            cout << "\nOdd numbers are: \n";
            while (odd.isempty() == false)      cout << odd.dequeue() << "\t";
            cout <<endl;
        }
    }
}
