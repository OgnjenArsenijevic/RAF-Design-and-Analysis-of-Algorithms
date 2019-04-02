///v2z4
///Author: Ognjen Arsenijevic
///Time Complexity: O(n)
#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int n;
vector<char> v;

int main()
{
    ios_base::sync_with_stdio(0);
    cin>>n;
    for(int i=0;i<2*n;i++)
    {
        char in;
        cin>>in;
        v.push_back(in);
    }
    int w=0,b=0,ans=0,cnt=0;
    while(v[w]!='B') w++;
    while(v[b]!='C') b++;
    while(cnt<n)
    {
        ans+=(abs(w-b));
        cnt++;
        w++;
        b++;
        while(v[w]!='B') w++;
        while(v[b]!='C') b++;
    }
    cout<<ans;
    return 0;
}
