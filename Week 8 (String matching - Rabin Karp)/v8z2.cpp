///v8z2
///Author: Ognjen Arsenijevic
///Time Complexity: O(n)
#include <iostream>
#include <string>
#define MOD 1000000009
using namespace std;
typedef long long ll;

string s;
int k;
ll prefHash[10005],suffHash[10005],savePrefDeg[10005],saveSuffDeg[10005];

int solve()
{
    int ans=0;
    for(int i=k;i<=s.size();i++)
    {
        if(((prefHash[i]-prefHash[i-k]+MOD)*saveSuffDeg[i+1])%MOD == ((suffHash[i-k+1]-suffHash[i+1]+MOD)*savePrefDeg[i-k])%MOD)
            ans++;
    }
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin>>s;
    cin>>k;
    prefHash[0]=0;
    savePrefDeg[0]=1;
    ll deg=37LL;
    for(int i=1;i<=s.size();i++)
    {
        prefHash[i]=(prefHash[i-1]+s[i-1]*deg)%MOD;
        savePrefDeg[i]=deg;
        deg=(deg*37LL)%MOD;
    }
    suffHash[s.size()+1]=0;
    saveSuffDeg[s.size()+1]=1;
    deg=37LL;
    for(int i=s.size();i>0;i--)
    {
        suffHash[i]=(suffHash[i+1]+s[i-1]*deg)%MOD;
        saveSuffDeg[i]=deg;
        deg=(deg*37LL)%MOD;
    }
    cout<<solve();
    return 0;
}
