///v2z1
///Author: Ognjen Arsenijevic
///Time Complexity: O(nlogn)
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

bool compare(int a,int b)
{
    return a>b;
}

int n,pera,mika;
vector<int> v;

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
    sort(v.begin(),v.end(),compare);
    for(int i=0;i<v.size();i++)
    {
        if(i&1)
            mika+=v[i];
        else
            pera+=v[i];
    }
    cout<<pera<<" "<<mika<<"\n";
    return 0;
}
