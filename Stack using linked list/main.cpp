#include <iostream>
#include <stdlib.h>
#include <time.h>

using namespace std;

//Write a class to simulate stack using linked list.
struct data
{
	int num;
	struct data *next;
};

class mystack
{
private:
    data *top;
public:
	mystack(void)
	{
		top = NULL;
	}
	void push(int n)
	{
        data *temp;
		temp = new struct data;
		if (temp == NULL)
		{
			cout << "Stack is FULL !!!!!!!!\n"; //Memory is full.
			exit (1);
		}
		temp->num = n;		    // (*temp).num = n;
		temp->next = top;		// (*temp).next = top;
		top = temp;
	}
	int pop()
	{
        data *temp;
		int n;
		if (top == NULL)
		{
			cout << "Empty stack\n";
			return 0;
		}
		n = top->num;			//	n = (*top).num;
		temp = top;
		top = top->next;			// top = (*top).next;
		delete temp;
		return n;
	}
	bool isempty(void)
	{
		return (top == NULL);
	}
	int get_size(void)
	{
		int counter = 0;
		for (data *temp = top; temp != NULL; temp = temp->next)   counter++;
		return counter;
	}
	void print_stack(void)
	{
        data *temp;
		for (temp = top; temp != NULL; temp = temp->next)
        {
            cout << temp->num << "\t";  //cout << (*temp).num << "\t";
        }
		cout << "\n";
	}

	void clear(void)
	{
        data *temp;
		while (top != NULL)
		{
			temp = top;
			top = top->next;
			delete temp;
		}
	}
};

int main(void)
{
	srand(time(NULL));
	mystack odd, even;
	int k, n;
	for (k = 1; k <= 100; k++)
	{
		n = rand() % 10;
		if (n % 2 == 0)		even.push(n);
		else				odd.push(n);
	}
	cout << "Size of odd stack = " << odd.get_size() << "\n";
	cout << "Size of even stack = " << even.get_size() << "\n";
	cout << "Data in odd stack are:\n";
	odd.print_stack();
	cout << "\nData in even stack are:\n";
	while(even.isempty() == false)   cout << even.pop() << "\t";
}
