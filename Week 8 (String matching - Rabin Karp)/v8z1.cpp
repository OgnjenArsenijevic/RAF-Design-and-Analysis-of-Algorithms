///v8z1
///Author: Ognjen Arsenijevic
///Time Complexity: O(n+sumOfDivisors(n)) where n is length of string
#include <iostream>
#include <string>
#define MOD 1000000009

using namespace std;
typedef long long ll;

int n;
ll hashArr[10005];
ll saveDeg[10005];
string s;

int solve()
{
    for(int i=1;i<=n;i++)
    {
        if(n%i) continue;
        ll hashVal=hashArr[i];
        ll deg=1;
        int currIdx=i;
        bool flag=true;
        while(currIdx<=n)
        {
            if(((hashVal*deg)%MOD) != ((hashArr[currIdx]-hashArr[currIdx-i]+MOD)%MOD))
            {
                flag=false;
                break;
            }
            deg=saveDeg[currIdx];
            currIdx+=i;
        }
        if(flag)
            return n/i;
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin>>s;
    n=s.size();
    ll deg=37LL;
    hashArr[0]=0;
    saveDeg[0]=1LL;
    for(int i=1;i<=n;i++)
    {
        hashArr[i]=(hashArr[i-1]+s[i-1]*deg)%MOD;
        saveDeg[i]=deg;
        deg=(deg*37LL)%MOD;
    }
    cout<<solve();
    return 0;
}
