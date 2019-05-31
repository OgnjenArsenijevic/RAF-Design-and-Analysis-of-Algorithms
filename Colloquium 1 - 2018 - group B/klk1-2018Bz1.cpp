///Kolokvijum 1 - 2017/18 grupa B z1
///Author: Ognjen Arsenijevic
///Time Complexity: O(n^2)
///Additional Space: O(1)
#include <iostream>

using namespace std;

int n,ans;
string mat[1005];
int main()
{
    ios_base::sync_with_stdio(0);
    cin>>n;
    for(int i=0;i<n;i++)
        cin>>mat[i];
    for(int i=0;i<n-2;i++)
    {
        for(int j=0;j<n-2;j++)
        {
            if(mat[i][j]=='0')
            {
                ans++;
                for(int k=i;k<i+3;k++)
                {
                    for(int r=j;r<j+3;r++)
                    {
                        if(mat[k][r]=='0')
                            mat[k][r]='1';
                        else
                            mat[k][r]='0';
                    }
                }
            }
        }
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(mat[i][j]=='0')
            {
                cout<<"-1";
                return 0;
            }
        }
    }
    cout<<ans;
    return 0;
}
