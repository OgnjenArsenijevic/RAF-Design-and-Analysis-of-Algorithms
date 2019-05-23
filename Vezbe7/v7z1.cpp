///v7z1
///Author: Ognjen Arsenijevic
///Time Complexity: O(n!)
#include <iostream>
#include <string>
#include <cstring>

using namespace std;

int n;
char mat[100][100];

bool attacked(int ii, int jj)
{
    for(int i=0;i<n;i++)
    {
        if(i!=ii && mat[i][jj]=='X')
            return true;
    }
    for(int j=0;j<n;j++)
    {
        if(j!=jj && mat[ii][j]=='X')
            return true;
    }
    for(int i=ii+1,j=jj+1;i<n && j<n;i++,j++)
    {
        if(mat[i][j]=='X')
            return true;
    }
    for(int i=ii+1,j=jj-1;i<n && j>=0;i++,j--)
    {
        if(mat[i][j]=='X')
            return true;
    }
    for(int i=ii-1,j=jj+1;i>=0 && j<n;i--,j++)
    {
        if(mat[i][j]=='X')
            return true;
    }
    for(int i=ii-1,j=jj-1;i>=0 && j>=0;i--,j--)
    {
        if(mat[i][j]=='X')
            return true;
    }
    return false;
}

bool solve(int currRow)
{
    if(currRow==n)
        return true;
    for(int i=0;i<n;i++)
    {
        if(!attacked(currRow,i))
        {
            mat[currRow][i]='X';
            if(solve(currRow+1))
                return true;
            mat[currRow][i]='O';
        }
    }
    return false;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin>>n;
    memset(mat,'O',sizeof(mat));
    if(solve(0))
    {
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
                cout<<mat[i][j];
            cout<<"\n";
        }
    }
    else
        cout<<"Impossible\n";
    return 0;
}
