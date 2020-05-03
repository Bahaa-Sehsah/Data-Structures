//Write a program to read 10 integer numbers from
//the user. Store even numbers in a stack, and odd
//numbers in another stack. After entering 10 numbers,
//print contents of each stack separately. Set size of each
// stack = 3. If even stack becomes full, increase its size.
// If odd stack becomes full, print a message to the user.

#include <iostream>
#include <stdlib.h>

using namespace std;

class mystack
{
private:
	int *arr, top, maxsize;
public:
	mystack(int k)
	{
		arr = new int[k];
		top = 0;
		maxsize = k;
	}
	mystack()
	{
		arr = new int[10];
		top = 0;
		maxsize = 10;
	}
	void push(int d)
	{
		if (top == maxsize)   doublesize();
		arr[top] = d;
		top++;
	}
	int pop(void)
	{
		if (top == 0)		  exit(1);
		top--;
		return arr[top];
	}
	bool isfull()
	{
        // return(top == maxsize); similar to the bellow if else condition.
		if (top == maxsize)		return true;
		else					return false;
	}
	bool isempty()
	{
		// return(top == 0);   similar to the bellow if else condition.

		if (top == 0)		return true;
		else				return false;
	}
	int get_nuumber_of_elements()
	{
		return top;
	}
	int get_max_size()
	{
		return maxsize;
	}
	void doublesize()
	{
		int *arr2;
		arr2 = new int[maxsize*2];
		for (int k = 0; k < maxsize; k++)   arr2[k] = arr[k];
		delete arr;
		arr = arr2;
		maxsize *= 2;
	}
};

int main(void)
{
	mystack  odd(5), even(5);
	int num;
	for (int k = 0; k < 10; k++)
	{
		cout << "Number[" << k+1 << "] = ";
		cin >> num;
		if (num % 2 == 0)
		{
            //  if (even.isfull() == false)
            //  else cout << "Even stack is full\n";
			even.push(num);
		}
		else
		{
			//if (odd.isfull() == false)
			//else  cout << "Odd stack is full\n";
			odd.push(num);
		}
	}
	cout << "Even numbers are: \n";
	while (even.isempty() == false) cout << even.pop() << "\t";

    cout << "\nOdd numbers are: \n";
	while (odd.isempty() == false)  cout << odd.pop() << "\t";
}
