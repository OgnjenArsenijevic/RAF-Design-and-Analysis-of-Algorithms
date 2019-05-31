///v6z6
///Author: Ognjen Arsenijevic
///Additional space: O(1)
#include <iostream>
#include <vector>
#include <string>

using namespace std;

int n;
vector<string> v;

string solve(vector<string> v, int l, int r)
{
    if(l==r)
        return v[l];
    int mid=(l+r)/2;
    string left=solve(v,l,mid);
    string right=solve(v,mid+1,r);
    string ans="";
    for(int i=0;i<min(left.size(),right.size());i++)
    {
        if(left[i]!=right[i])
            break;
        ans+=left[i];
    }
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin>>n;
    for(int i=0;i<n;i++)
    {
        string in;
        cin>>in;
        v.push_back(in);
    }
    cout<<solve(v,0,n-1);
    return 0;
}
