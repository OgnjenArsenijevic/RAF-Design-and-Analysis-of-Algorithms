///v1z10
///Author: Ognjen Arsenijevic
#include <iostream>
#include <cstdio>
#include <bits/stdc++.h>

using namespace std;

int a,b;

int main()
{
    scanf("%d/%d",&a,&b);
    bool flag=false;
    while(true)
    {
        if(flag) cout<<" + ";
        int down=b/a;
        if(b%a) down++;
        cout<<"1/"<<down;
        if(b%a==0) break;
        int lcm=b*down/(__gcd(b,down));
        a*=(lcm/b);
        a-=(lcm/down);
        b=lcm;
        flag=true;
    }
    return 0;
}
