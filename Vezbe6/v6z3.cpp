///v6z3
///Author: Ognjen Arsenijevic
///Time Complexity: O(n)
///Additional space: O(1)
#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <climits>

using namespace std;

int n;
vector<int> v;

pair<int,int> solve(vector<int> v, int l, int r)
{
    if(l==r)
        return make_pair(v[l],INT_MIN);
    int mid=(l+r)/2;
    pair<int,int> left=solve(v,l,mid);
    pair<int,int> right=solve(v,mid+1,r);
    if(max(left.first,left.second)>max(right.first,right.second))
    {
        if(min(left.first,left.second)>max(right.first,right.second))
            return left;
        else
            return make_pair(max(left.first,left.second),max(right.first,right.second));
    }
    else
    {
        if(min(right.first,right.second)>max(left.first,left.second))
            return right;
        else
            return make_pair(max(right.first,right.second),max(left.first,left.second));
    }
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
    cout<<solve(v,0,n-1).second;
    return 0;
}
