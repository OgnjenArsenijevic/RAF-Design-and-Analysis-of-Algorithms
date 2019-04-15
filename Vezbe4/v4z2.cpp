///v4z2
///Author: Ognjen Arsenijevic
///Time Complexity: O(n)
///Additional space: O(n)
#include <iostream>

using namespace std;

int n,dp[10005];

int main()
{
    iostream::sync_with_stdio(0);
    cin>>n;
    dp[1]=1;
    dp[2]=1;
    dp[3]=1;
    dp[4]=2;
    for(int i=5;i<=n;i++)
        dp[i]=dp[i-1]+dp[i-4];
    cout<<dp[n];
    return 0;
}
