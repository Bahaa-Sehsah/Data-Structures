#include <iostream>

using namespace std;

#define dim 7
#define inf 99

int weight[dim][dim] = { {  0 ,  1 , inf, inf, inf,  2 , inf },
                         {  1 ,  0 ,  8 , inf, inf, inf, inf },
                         { inf,  8 ,  0 ,  4 , inf,  3 , inf },
                         { inf, inf,  4 ,  0 ,  2 , inf, inf },
                         { inf, inf, inf,  2 ,  0 ,  1 , inf },
                         {  2 , inf,  3 , inf,  1 ,  0 ,  2  },
                         { inf, inf, inf, inf, inf,  2 ,  0  } };


int main()
{
    cout<<"Weight Before All to all shortest path:"<<endl;
    for(int i = 0 ; i<dim ; i++)
    {
        for(int j = 0 ; j<dim ; j++)
        {
            cout<<weight[i][j]<<"\t";
        }
        cout<<endl<<endl;
    }
    for(int i = 0 ; i<dim ; i++)
    {
        for(int j = 0 ; j<dim ; j++)
        {
            for(int k = 0 ; k<dim ; k++)
            {
                if(weight[i][j] > (weight[i][k]+weight[k][j]))
                {
                    weight[i][j] = weight[i][k]+weight[k][j];
                }
            }
        }
    }
    cout<<"Weight After All to all shortest path:"<<endl;
    for(int i = 0 ; i<dim ; i++)
    {
        for(int j = 0 ; j<dim ; j++)
        {
            cout<<weight[i][j]<<"\t";
        }
        cout<<endl;
    }
}
