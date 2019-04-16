///v5z4
///Author: Ognjen Arsenijevic
///Time Complexity: O(nsqrt(n))
///Additional space: O(n)
#include <iostream>
#include <cmath>

using namespace std;

int n,dp[1005];

int main()
{
    ios_base::sync_with_stdio(0);
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        dp[i]=i;
        for(int j=1;j<=sqrt(i);j++)
            dp[i]=min(dp[i],dp[i-j*j]+1);
    }
    cout<<dp[n];
    return 0;
}
