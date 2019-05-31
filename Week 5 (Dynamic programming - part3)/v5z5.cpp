///v5z5
///Author: Ognjen Arsenijevic
///Time Complexity: O(s1.size() * s2.size())
///Additional space: O(s1.size() * s2.size())
#include <iostream>
#include <string>

using namespace std;

string s1;
string s2;
string s3;
bool dp[1005][1005];

int main()
{
    ios_base::sync_with_stdio(0);
    cin>>s1>>s2>>s3;
    if(s1.size()+s2.size()!=s3.size())
        cout<<"false\n";
    bool dp[s1.size()+1][s2.size()+1];
    for(int i=0;i<=s1.size();i++)
    {
        for(int j=0;j<=s2.size();j++)
        {
            if(i==0 && j==0)
                dp[i][j]=true;
            else
            {
                if(i==0)
                    dp[i][j]=(dp[i][j-1] && s2[j-1]==s3[j-1]);
                else
                {
                    if(j==0)
                        dp[i][j]=(dp[i-1][j] && s1[i-1]==s3[i-1]);
                    else
                        dp[i][j]=((dp[i-1][j] && s1[i-1]==s3[i+j-1]) || (dp[i][j-1] && s2[j-1]==s3[i+j-1]));
                }
            }
        }
    }
    cout<<(dp[s1.size()][s2.size()]==true ? "true\n" : "false\n");
    return 0;
}
