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
int MinSTree[dim][dim];

class Tree
{
    public:
    void Print2DArray(int A[dim][dim])
    {
        for(int i = 0 ; i<dim ; i++)
        {
            for(int j = 0 ; j<dim ; j++)
            {
                cout<<A[i][j]<<"\t";
            }
            cout<<endl;
        }
    }
    void AllToAllShortestPath()
    {
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
                    else{}
                }
            }
        }
    }
    void ShortestPath(int S , int D)
    {
        cout<<"Path is : ";
        int z[dim][3], Min, TempS;
        for(int i=0 ; i<dim ; i++)
        {
            z[i][0] = -1;
            z[i][1] = inf;
            z[i][2] = 0;
        }
        TempS = S;
        Min = weight[TempS][TempS];
        z[S][0] = S;
        z[S][1] = 0;
        z[S][2] = 1;
        do
        {
            for(int i=0 ; i<dim ; i++)
            {
                if( (z[i][2]==0) && (z[i][1] > (weight[TempS][i]+Min)) )
                {
                    z[i][1] = weight[TempS][i]+Min;
                    z[i][0] = TempS;
                }
            }
            Min   = inf;
            TempS = -1;
            for(int i=0 ; i<dim ; i++)
            {
                if( (z[i][2]==0) && (z[i][1] < Min) )
                {
                    TempS = i;
                    Min   = z[i][1];
                }
            }
            z[TempS][2] = 1;
        }while(TempS != D);

        int i = D;
        cout<<D<<"\t";
        while(i != S)
        {
            i = z[i][0];
            cout<<i<<"\t";
        }
        cout<<"\nWeight = "<<Min;
    }
    void MinimumSpanningTree()
    {
        //TempS refers to temporary source, while TempD refers to temporary destination.
        int z[dim][3], Min, TempS,TempD,TotalWeight=0;

        //Initializing the table which holds node data.
        for(int i=0 ; i<dim ; i++)
        {
            z[i][0] = -1;
            z[i][1] = inf;
            z[i][2] = 0;
        }

        //Initializing the 2D Array which holds Minimum spanning tree data.
        for(int i=0 ; i<dim ; i++)
        {
            for(int j=0 ; j<dim ; j++)
            {
                if(i==j)    MinSTree[i][j] = 0;         //Diagonal values equal zero.
                else        MinSTree[i][j] = inf;       //Remaining values equal inf which is equal 99.
            }
        }

        TempS = 0;                      //Initializing temporary source with the first node which is zero.
        Min = weight[TempS][TempS];     //Initializing Minimum with zero, As any diagonal value equals zero.
        z[TempS][0] = 0; z[TempS][1] = 0;	z[TempS][2] = 1;
        do
        {
            //Updating "z" table values.
            for(int i=0 ; i<dim ; i++)
            {
                //"z[i][2] == 0"                To make sure that this node not in the recent path.
                //"z[i][1]>weight[TempS][i]"    To make sure that node weight in "z" table is smaller than node weight in weight table.
                if(z[i][2] == 0 && (z[i][1]>weight[TempS][i]))
                {
                    //Update "z" table values.
                    z[i][1] = weight[TempS][i];
                    z[i][0] = TempS;
                }
            }
            Min = inf;          //Initializing Min with high value to avoid wrong guessing.
            TempD = -1;         //Initializing TempD with not found node.
            //See the best node to go through in our tree from "z" table.
            for(int i=0 ; i<dim ; i++)
            {
                if(z[i][2] == 0 && (Min>z[i][1]))
                {
                    Min   = z[i][1];
                    TempS = z[i][0];
                    TempD = i;
                }
            }
            if(Min == inf)  break;      //If there is no node found.
            //Setting the weight in the two corresponding MinSTree Array cells equal to the weight of the link between TempS & TempD.
            MinSTree[TempS][TempD] = MinSTree[TempD][TempS] = weight[TempS][TempD];
            //TotalWeight which indicate the cost of creating the minimum spanning tree network.
            TotalWeight+=Min;
            //The last destination is our new source to iterate this process for all the nodes as our source.
            TempS = TempD;
            //Mark the status of our destination to be 1 (Means that this node is connected).
            z[TempS][2]=1;
        }while(TempS != -1);
        ///TempS will be -1 if TempD remains -1 after Seeing the best node to go through
        ///in our tree from "z" table and did not find any node so Minimum spanning tree was achieved .
    }
};
int main()
{
    Tree t;
    /*
    //All to all shortest Path
    cout<<"Weight Before All to all shortest path:"<<endl;
    t.Print2DArray(weight);
    t.AllToAllShortestPath();
    cout<<"Weight After All to all shortest path:"<<endl;
    t.Print2DArray(weight);
    */
    //Shortest Path
    int S , D;
    cout<<"Enter source:";
    cin>>S;
    cout<<"Enter destination:";
    cin>>D;
    t.ShortestPath(S,D);
    t.MinimumSpanningTree();
    cout<<"\nMinimum Spanning Tree:"<<endl;
    t.Print2DArray(MinSTree);

}
