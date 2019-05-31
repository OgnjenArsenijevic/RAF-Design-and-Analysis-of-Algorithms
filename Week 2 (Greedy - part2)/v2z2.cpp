///v2z2
///Author: Ognjen Arsenijevic
///Time Complexity: O(log_c{n})
#include <iostream>

using namespace std;

int n,c,curr=1,ans;

int main()
{
    ios_base::sync_with_stdio(0);
    cin>>n>>c;
    if(c==1)
    {
        cout<<n;
        return 0;
    }
    while(curr*c<=n)
        curr*=c;
    while(n>0)
    {
        ans+=(n/curr);
        n%=curr;
        while(curr>n)
            curr/=c;
    }
    cout<<ans;
    return 0;
}
