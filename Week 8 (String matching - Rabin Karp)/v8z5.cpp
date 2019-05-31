///v8z5
///Author: Ognjen Arsenijevic
///Time Complexity: O(mlogSize)
#include <iostream>
#include <string>
#define MOD 1000000009

using namespace std;
typedef long long ll;

int m;
ll prefA[10005],prefB[10005],saveA[10005],saveB[10005];
string a;
string b;

bool can(int val, int x, int y)
{
    if(x+val<=a.size()+1 && y+val<=b.size()+1)
    {
        if(((prefA[x+val-1]-prefA[x-1]+MOD)*saveB[y-1])%MOD == ((prefB[y+val-1]-prefB[y-1]+MOD)*saveA[x-1])%MOD)
            return true;
    }
    return false;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin>>a;
    cin>>b;
    prefA[0]=0;
    prefB[0]=0;
    saveA[0]=1LL;
    saveB[0]=1LL;
    ll deg=37LL;
    for(int i=1;i<=a.size();i++)
    {
        prefA[i]=(prefA[i-1]+a[i-1]*deg)%MOD;
        saveA[i]=deg;
        deg=(deg*37LL)%MOD;
    }
    deg=37LL;
    for(int i=1;i<=b.size();i++)
    {
        prefB[i]=(prefB[i-1]+b[i-1]*deg)%MOD;
        saveB[i]=deg;
        deg=(deg*37LL)%MOD;
    }
    cin>>m;
    while(m--)
    {
        int x,y;
        cin>>x>>y;
        int maxA=a.size()-x+1;
        int maxB=b.size()-y+1;
        int low=0, high=min(maxA,maxB);
        while(low<high)
        {
            int mid=low+(high-low+1)/2;
            if(can(mid,x,y))
                low=mid;
            else
                high=mid-1;
        }
        cout<<low<<"\n";
    }

    return 0;
}
