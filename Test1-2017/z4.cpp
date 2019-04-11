///z4
///Author: Ognjen Arsenijevic
///Time Complexity: O(nlog n)
#include <iostream>
#include <queue>
#include <utility>
#include <vector>
#include <functional>

using namespace std;

int n;
priority_queue<pair<int,int>, vector<pair<int,int> >, greater<pair<int,int> > > pq;

int main()
{
    ios_base::sync_with_stdio(0);
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        int in;
        cin>>in;
        pq.push(make_pair(in,i));
    }
    while(pq.size()>1)
    {
        pair<int,int> p1=pq.top();
        pq.pop();
        pair<int,int> p2=pq.top();
        pq.pop();
        cout<<p1.second<<" "<<p2.second<<"\n";
        pq.push(make_pair(p1.first+p2.first,++n));
    }
    return 0;
}
