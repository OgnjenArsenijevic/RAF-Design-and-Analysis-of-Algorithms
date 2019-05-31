///v2z7
///Author: Ognjen Arsenijevic
///Time Complexity: O(numberOfDigits)
#include <iostream>
#include <string>
#include <stack>
#include <algorithm>

using namespace std;

string s;
int k,cnt;
stack<int> st;

int main()
{
    ios_base::sync_with_stdio(0);
    cin>>s;
    cin>>k;
    for(int i=0;i<s.size();i++)
    {
        int num=(s[i]-'0');
        if(st.empty())
            st.push(num);
        else
        {
            bool bb=!st.empty();
            while(!st.empty() && st.top()>num && cnt<k)
            {
                st.pop();
                cnt++;
            }
            st.push(num);
        }
    }
    while(!st.empty() && cnt<k)
    {
        st.pop();
        cnt++;
    }
    string ans="";
    while(!st.empty())
    {
        ans+=(char)(st.top()+'0');
        st.pop();
    }
    reverse(ans.begin(),ans.end());
    cout<<ans;
    return 0;
}
