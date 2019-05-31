///Kolokvijum 1 - 2017/18 grupa B z2
///Author: Ognjen Arsenijevic
///Time Complexity: O(n)
///Additional Space: O(n)
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int n,k,dp[1005];
string s;

int main()
{
    ios_base::sync_with_stdio(0);
    cin>>n>>k;
    cin>>s;
    int curr=1;
    dp[0]=0;
    for(int i=1;i<k-1;i++)
    {
        dp[i]=0;
        if(s[i]==s[i-1])
            curr++;
        else
            curr=1;
    }
    for(int i=k-1;i<n;i++)
    {
        if(s[i]==s[i-1])
            curr++;
        else
            curr=1;
        if(curr==k)
        {
            curr--;
            dp[i]=0;
        }
        else
            dp[i]=dp[i-k]+1;
    }
    cout<<*max_element(dp,dp+n)*k;
    return 0;
}
