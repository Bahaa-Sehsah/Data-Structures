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
	mystack(void)
	{
		arr = new int[12];
		top = 0;
		maxsize = 12;
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
	bool isfull(void)
	{
        // return(top == maxsize); similar to the bellow if else condition.

		if (top == maxsize)		return true;
		else					return false;
	}
	bool isempty(void)
	{
		// return(top == 0);   similar to the bellow if else condition.

		if (top == 0)		return true;
		else				return false;
	}
	int get_nuumber_of_elements(void)
	{
		return top;
	}
	int get_max_size(void)
	{
		return maxsize;
	}
	void doublesize(void)
	{
		int *arr2;
		arr2 = new int[maxsize * 2];
		for (int k = 0; k < maxsize; k++)   arr2[k] = arr[k];
		delete arr;
		arr = arr2;
		maxsize *= 2;
	}
};





int main()
{
    mystack x;
    int temp;
    int Arr[12][3] = { {0,6,2} ,
                       {1,-1,1},
                       {2,5,3},
                       {3,1,3},
                       {4,5,1},
                       {5,1,1},
                       {6,5,2},
                       {7,6,1},
                       {8,10,1},
                       {9,3,1},
                       {10,1,2},
                       {11,3,2}};
    int order[4];
    for(int i=0 ; i<12 ; i++)
    {
        if(Arr[i][1]==-1)
        {
            temp =Arr[i][0];
            x.push(temp);
            break;
        }
    }
    cout<<"Depth first search for this tree : "<<endl;
    while(!x.isempty())
    {
        temp=x.pop();
        cout<<temp<<endl;
        int counter = 0;
        for(int i=0 ; i<12 ; i++)
        {
            if(Arr[i][1] == temp)
            {
                order[Arr[i][2]] = Arr[i][0];
                counter++;
            }
        }
        for(int i=counter ; i>0 ; i--)      x.push(order[i]);
    }
}
