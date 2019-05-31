///v8z3
///Author: Ognjen Arsenijevic
///Time Complexity: O(n^2)
#include <iostream>
#include <string>
#include <unordered_set>
#define MOD 1000000009

using namespace std;
typedef long long ll;

unordered_set<ll> st;
string s;
ll prefHash[10005];
ll saveDeg[10005];

int main()
{
    ios_base::sync_with_stdio(0);
    cin>>s;
    prefHash[0]=0;
    ll deg=37LL;
    saveDeg[0]=1LL;
    for(int i=1;i<=s.size();i++)
    {
        prefHash[i]=(prefHash[i-1]+s[i-1]*deg)%MOD;
        saveDeg[i]=deg;
        deg=(deg*37LL)%MOD;
    }
    for(int i=1;i<=s.size();i++)
    {
        for(int j=i;j<=s.size();j++)
            st.insert(((prefHash[j]-prefHash[i-1]+MOD)*saveDeg[s.size()-i])%MOD);
    }
    cout<<st.size();
    return 0;
}
