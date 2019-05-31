///v1z5
///Author: Ognjen Arsenijevic
///Time Complexity O(sz1+sz2+sz3)
#include <iostream>
#include <stack>

using namespace std;

int sz1,sz2,sz3,sum1,sum2,sum3;
stack<int> st1;
stack<int> st2;
stack<int> st3;


int main()
{
    ios_base::sync_with_stdio(0);
    cin>>sz1>>sz2>>sz3;
    for(int i=0;i<sz1;i++)
    {
        int in;
        cin>>in;
        sum1+=in;
        st1.push(in);
    }
    for(int i=0;i<sz2;i++)
    {
        int in;
        cin>>in;
        sum2+=in;
        st2.push(in);
    }
    for(int i=0;i<sz3;i++)
    {
        int in;
        cin>>in;
        sum3+=in;
        st3.push(in);
    }
    int cnt=0;
    while(true)
    {
        if(sum1==sum2 && sum1==sum3) break;
        cnt++;
        int maxi=sum1,idx=1;
        if(sum2>maxi)
        {
            maxi=sum2;
            idx=2;
        }
        if(sum3>maxi)
        {
            maxi=sum3;
            idx=3;
        }
        if(idx==1)
        {
            sum1-=st1.top();
            st1.pop();
        }
        if(idx==2)
        {
            sum2-=st2.top();
            st2.pop();
        }
        if(idx==3)
        {
            sum3-=st3.top();
            st3.pop();
        }
    }
    cout<<cnt;
    return 0;
}
