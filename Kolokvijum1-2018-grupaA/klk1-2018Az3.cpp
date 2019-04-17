///Kolokvijum 1 - 2017/18 grupa A z3
///Author: Ognjen Arsenijevic
///Time Complexity: O(n)
///Additional Space: O(1)
#include <iostream>
#include <vector>
#include <utility>
#include <climits>
using namespace std;

int n,ans=INT_MIN;
vector<int> v;

pair<int,int> solve(vector<int> v, int l, int r)
{
    if(l==r)
        return make_pair(v[l],v[l]);
    int mid=(l+r)/2;
    pair<int,int> left=solve(v,l,mid);
    pair<int,int> right=solve(v,mid+1,r);
    ans=max(ans,right.first-left.second);
    return make_pair(max(left.first,right.first),min(left.second,right.second));
}


int main()
{
    ios_base::sync_with_stdio(0);
    cin>>n;
    for(int i=0;i<n;i++)
    {
        int in;
        cin>>in;
        v.push_back(in);
    }
    pair<int,int> tmp=solve(v,0,n-1);
    cout<<ans<<"\n";
    return 0;
}
