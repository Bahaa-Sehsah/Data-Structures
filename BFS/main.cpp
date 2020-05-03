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
            arr2[k] = arr[((front)%maxsize)];
            front++;
        }
		delete arr;
		arr = arr2;
		front=0;
		rear=maxsize;
		maxsize = maxsize * 2;
	}
};

int main()
{
    myqueue x;
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
                       {11,3,2},};
    int order[4];
    for(int i=0 ; i<12 ; i++)
    {
        if(Arr[i][1]==-1)
        {
            temp =Arr[i][0];
            x.enqueue(temp);
            break;
        }
    }
    cout<<"Breadth first search for this tree : "<<endl;
    while(!x.isempty())
    {
        temp=x.dequeue();
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
        for(int i=1 ; i<=counter ; i++)     x.enqueue(order[i]);
    }
}
