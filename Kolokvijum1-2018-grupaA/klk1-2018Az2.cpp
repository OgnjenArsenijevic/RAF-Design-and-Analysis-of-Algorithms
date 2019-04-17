///Kolokvijum 1 - 2017/18 grupa A z2
///Author: Ognjen Arsenijevic
///Time Complexity: O(n)
///Additional Space: O(n)
#include <iostream>

using namespace std;

int n,m,dp[1005],flag[1005];

int main()
{
    ios_base::sync_with_stdio(0);
    cin>>n>>m;
    for(int i=0;i<m;i++)
    {
        int a,b;
        cin>>a>>b;
        flag[a]=-1;
        flag[b]=a;
    }
    dp[0]=1;
    dp[1]=1;
    for(int i=2;i<=n;i++)
    {
        for(int j=1;j<7;j++)
        {
            if(i-j>=0 && flag[i-j]!=-1)
                dp[i]+=dp[i-j];
        }
        if(flag[i]>0)
            dp[i]+=dp[flag[i]];
    }
    cout<<dp[n];
    return 0;
}
