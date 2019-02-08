#include <iostream>

using namespace std;

int increasing(int n, int A[])  //function return 1 if the sequence increase
{
    bool state = true;
    int tmp=0;
    for(int j=1; j<n; ++j)
    {
         if(A[j-1]<A[j])
         {
             state = true;
         }
         else 
         {
            state = false;
            return tmp;
         }
    }
    state==true ? tmp = 1: tmp = 0;
    return tmp;
}

int decreasing(int n, int A[])  //function return 1 if the sequence decrease
{
    bool state = true;
    int tmp=0;
    for(int j=0; j<n-1; ++j)
    {
         if(A[j]>A[j+1])
         {
             state = true;
         }
         else
         {
            state = false;
            return tmp;
         }
    }
    state==true ? tmp = 1: tmp = 0;
    return tmp;
}

int main()
{
    bool state = true;
    int tmp=0, n=4, inc=0, dec=0;
    int A[4][4] = {{3, 4, 5, 6}, {3, 2, 1, 0}, {3, 1, 2, 0}, {7, 9, 12, 15}};
    int B[n][n];        //new array
    for(int i=0; i<n;++i)
    {
        dec = decreasing(n,A[i]);
        inc = increasing(n,A[i]);
        if(inc==1 || dec==1)
        {
            for(int j=0;j<n;++j)
            {
                B[i][j]=A[i][j];
                cout<<B[i][j]<<" ";
            }
            cout<<"\n";
        }
    }    
}
