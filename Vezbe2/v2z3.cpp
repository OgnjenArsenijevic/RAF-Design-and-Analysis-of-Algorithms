///v2z3
///Author: Ognjen Arsenijevic
///Time Complexity: O(nlogn)
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int n;
vector<int> perica;
vector<int> kompjuter;

int main()
{
    ios_base::sync_with_stdio(0);
    cin>>n;
    for(int i=0;i<n;i++)
    {
        int in;
        cin>>in;
        perica.push_back(in);
    }
    for(int i=0;i<n;i++)
    {
        int in;
        cin>>in;
        kompjuter.push_back(in);
    }
    sort(perica.begin(),perica.end());
    sort(kompjuter.begin(),kompjuter.end());
    int p=n-1,k=n-1,ans=0;
    while(p>=0 && k>=0)
    {
        if(perica[p]>kompjuter[k])
        {
            ans+=perica[p--];
            k--;
        }
        else
            k--;
    }
    cout<<ans;
    return 0;
}
