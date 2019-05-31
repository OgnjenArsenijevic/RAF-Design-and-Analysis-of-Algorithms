///v4z6
///Author: Ognjen Arsenijevic
///Time Complexity: O(string.size()^2)
///Additional space: O(string.size()^2)
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

string s;
int dp[1005][1005];

int main()
{
    ios_base::sync_with_stdio(0);
    cin>>s; //racunamo da je unos jedna rec
    for(int i=0;i<s.size();i++)
        dp[i][i]=1;
    for(int len=1;len<s.size();len++)
    {
        for(int i=0;i<s.size()-len;i++)
        {
            int j=i+len;
            if(s[i]==s[j])
            {
                if(len==1)
                    dp[i][j]=2;
                else
                    dp[i][j]=dp[i+1][j-1]+2;
            }
            else
                dp[i][j]=max(dp[i][j-1],dp[i+1][j]);
        }
    }
    cout<<dp[0][s.size()-1];
    return 0;
}
