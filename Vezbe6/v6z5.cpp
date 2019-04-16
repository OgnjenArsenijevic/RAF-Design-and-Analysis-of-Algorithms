///v6z5
///Author: Ognjen Arsenijevic
///Time Complexity: O(log n)
///Additional space: O(1)
#include <iostream>

using namespace std;

int x,n;

int fastPow(int a, int n)
{
    int res=1;
    while(n)
    {
        if(n&1)
            res*=a;
        a*=a;
        n>>=1;
    }
    return res;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin>>x>>n;
    cout<<fastPow(x,n);
    return 0;
}
