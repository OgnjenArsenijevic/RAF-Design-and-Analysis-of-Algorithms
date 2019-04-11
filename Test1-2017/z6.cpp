///z6
///Author: Ognjen Arsenijevic
///Time Complexity: O(log n)
#include <iostream>

using namespace std;

void matMultiply(int a[3][3],int b[3][3])
{
    int c[3][3];
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
            c[i][j]=a[i][0]*b[0][j]+a[i][1]*b[1][j]+a[i][2]*b[2][j];
    }
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
            a[i][j]=c[i][j];
    }
}

void matFastPow(int a[3][3], int n)
{
    int res[3][3]={{1,0,0},{0,1,0},{0,0,1}};
    while(n>0)
    {
        if(n&1)
            matMultiply(res,a);
        matMultiply(a,a);
        n>>=1;
    }
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
            a[i][j]=res[i][j];
    }
}

int n;

int main()
{
    ios_base::sync_with_stdio(0);
    cin>>n;
    int mat[3][3]={{1,2,3},{1,0,0},{0,1,0}};
    int mul[3][3]={{4,0,0},{2,0,0},{1,0,0}};
    if(n==1)
    {
        cout<<1<<"\n";
        return 0;
    }
    if(n==2)
    {
        cout<<2<<"\n";
        return 0;
    }
    if(n==3)
    {
        cout<<3<<"\n";
        return 0;
    }
    matFastPow(mat,n-3);
    matMultiply(mat,mul);
    cout<<mat[0][0]<<"\n";
    return 0;
}
