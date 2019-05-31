///v7z7
///Author: Ognjen Arsenijevic
#include <iostream>
#include <cstring>

using namespace std;

int n=8,mat[8][8];
int korI[8]={2,1,-1,-2,-2,-1,1,2};
int korJ[8]={1,2,2,1,-1,-2,-2,-1};
//int korI[8]={-2,-2,2,2,-1,-1,1,1};
//int korJ[8]={-1,1,-1,1,-2,2,-2,2};


bool solve(int ii, int jj, int currIdx)
{
    if(currIdx==64)
        return true;
    for(int rr=0;rr<8;rr++)
    {
        int i=ii+korI[rr], j=jj+korJ[rr];
        if(i>=0 && j>=0 && i<n && j<n && mat[i][j]==-1)
        {
            mat[i][j]=currIdx;
            if(solve(i,j,currIdx+1))
                return true;
            mat[i][j]=-1;
        }
    }
    return false;
}

int main()
{
    ios_base::sync_with_stdio(0);
    memset(mat,-1,sizeof(mat));
    int ii,jj;
    cin>>ii>>jj;
    mat[ii][jj]=0;
    if(solve(ii,jj,1))
    {
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
                cout<<mat[i][j]<<" ";
            cout<<"\n";
        }
    }
    else
        cout<<"Impossible\n";
    return 0;
}
