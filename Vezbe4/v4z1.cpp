///v4z1
///Author: Ognjen Arsenijevic
///Time Complexity: O(n)
///Additional space: O(1)
#include <iostream>
#include <string>

using namespace std;

string s;
int dp[3];

int main()
{
    ios_base::sync_with_stdio(0);
    cin>>s;
    dp[0]=1;
    if(s[0]=='0')
    {
        cout<<0<<"\n";
        return 0;
    }
    dp[1]=1;
    for(int i=1;i<s.size();i++)
    {
        if(s[i]=='0' && s[i-1]!='1' && s[i-1]!='2')
        {
            cout<<0<<"\n";
            return 0;
        }
        dp[2]=dp[1]+((s[i-1]=='1' || (s[i-1]=='2' && s[i]>='0' && s[i]<='6')) ? dp[0] : 0);
        dp[0]=dp[1];
        dp[1]=dp[2];
    }
    cout<<dp[2]<<"\n";
    return 0;
}
