///v7z2
///Author: Ognjen Arsenijevic
///Time Complexity: O(n!)
#include <iostream>
#include <string>
#include <cstring>

using namespace std;

int n;
char mat[100][100],ansCnt;

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

void solve(int currRow)
{
    if(currRow==n)
    {
        ansCnt++;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
                cout<<mat[i][j];
            cout<<"\n";
        }
        cout<<"\n";
        return;
    }
    for(int i=0;i<n;i++)
    {
        if(!attacked(currRow,i))
        {
            mat[currRow][i]='X';
            solve(currRow+1);
            mat[currRow][i]='O';
        }
    }
    return;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin>>n;
    memset(mat,'O',sizeof(mat));
    solve(0);
    if(ansCnt==0)
        cout<<"Impossible\n";
    return 0;
}
