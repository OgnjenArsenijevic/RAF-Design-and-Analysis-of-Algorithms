///v3z8
///Author: Ognjen Arsenijevic
///Time Complexity: O(n^2)
///Additional space: O(n^2)
#include <iostream>
#include <algorithm>

using namespace std;

int n,mat[1005][1005],dp[1005][1005],ans;

int main()
{
    ios_base::sync_with_stdio(0);
    cin>>n;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
            cin>>mat[i][j];
    }
    dp[0][0]=1-mat[0][0];
    for(int i=1;i<n;i++)
    {
        dp[0][i]=1-mat[0][i];
        dp[i][0]=1-mat[i][0];
    }
    for(int i=1;i<n;i++)
    {
        for(int j=1;j<n;j++)
        {
            dp[i][j]=(mat[i][j]==1 ? 0 : min(min(dp[i-1][j-1],dp[i][j-1]),dp[i-1][j])+1);
            ans=max(ans,dp[i][j]);
        }
    }
    cout<<ans<<"x"<<ans;
    return 0;
}
