///v3z3
///Author: Ognjen Arsenijevic
///Time Complexity: O(logn)
///Additional space: O(1)
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n;

void matMultiply(int a[2][2], int b[2][2])
{
    int c[2][2];
    for(int i=0;i<2;i++)
    {
        for(int j=0;j<2;j++)
            c[i][j]=a[i][0]*b[0][j]+a[i][1]*b[1][j];
    }
    for(int i=0;i<2;i++)
    {
        for(int j=0;j<2;j++)
            a[i][j]=c[i][j];
    }
    return;
}

void matFastPow(int a[2][2],int n)
{
    int res[2][2]={{1,0},{0,1}};
    while(n>0)
    {
        if(n&1)
            matMultiply(res,a);
        matMultiply(a,a);
        n>>=1;
    }
    for(int i=0;i<2;i++)
    {
        for(int j=0;j<2;j++)
            a[i][j]=res[i][j];
    }
    return;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin>>n;
    if(n==1)
    {
        cout<<"1";
        return 0;
    }
    if(n==2)
    {
        cout<<"2";
        return 0;
    }
    int mat[2][2]={{1,1},{1,0}};
    int mulMat[2][2]={{2,0},{1,0}};
    matFastPow(mat,n-2);
    matMultiply(mat,mulMat);
    cout<<mat[0][0];
    return 0;
}
