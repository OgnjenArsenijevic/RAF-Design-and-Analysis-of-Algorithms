///v8z4
///Author: Ognjen Arsenijevic
///Time Complexity: O(nlogn)
#include <iostream>
#include <string>
#define MOD 1000000009
using namespace std;
typedef long long ll;

string s;
int k;
ll prefHash[10005],suffHash[10005],savePrefDeg[10005],saveSuffDeg[10005];

bool can(int k, bool flag)
{
    for(int i=k;i<=s.size();i++)
    {
        if(((prefHash[i]-prefHash[i-k]+MOD)*saveSuffDeg[i+1])%MOD == ((suffHash[i-k+1]-suffHash[i+1]+MOD)*savePrefDeg[i-k])%MOD)
        {
            if(flag)
            {
                for(int j=i-k;j<i;j++)
                    cout<<s[j];
            }
            return true;
        }
    }
    return false;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin>>s;
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
    int low=1, high=s.size();
    while(low<high)
    {
        int mid=low+(high-low+1)/2;
        if(can(mid,false))
            low=mid;
        else
        {
            if((mid&1) && can(mid+1,false))
                low=mid;
            else
                high=mid-1;
        }
    }
    can(low,true);
    return 0;
}
