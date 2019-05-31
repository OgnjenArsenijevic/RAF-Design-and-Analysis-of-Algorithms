///v3z2
///Author: Ognjen Arsenijevic
///Time Complexity: O(nm)
///Additional space: O(m)
#include <iostream>
#include <algorithm>

using namespace std;

int n,m,mat[1005][1005],dp[2][1005];
int main()
{
    ios_base::sync_with_stdio(0);
    cin>>n>>m;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
            cin>>mat[i][j];
    }
    dp[0][0]=mat[0][0];
    for(int i=1;i<m;i++)
        dp[0][i]=dp[0][i-1]+mat[0][i];
    for(int i=1;i<n;i++)
    {
        dp[1][0]=dp[0][0]+mat[i][0];
        for(int j=1;j<m;j++)
            dp[1][j]=mat[i][j]+max(dp[1][j-1],dp[0][j]);
        for(int j=0;j<m;j++)
            dp[0][j]=dp[1][j];
    }
    cout<<dp[1][m-1];
    return 0;
}
