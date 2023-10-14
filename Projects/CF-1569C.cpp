#include <bits/stdc++.h>
using namespace std;
#define int long long int
const int nax = 200010;
const int mod = 998244353;

int pre[nax];

void calc()
{
    pre[0] = 1;
    for(int i=1;i<200010;i++)
    {
        pre[i] = (pre[i-1]*i)%mod;
    }
}

int power(int a, int b)    //a is base, b is exponent
{
    if (b == 0)
        return 1;
    if (b == 1)
        return a;
    if (b % 2 == 1)
        return (power(a, b - 1) * a) % mod;
    int q = power(a, b / 2);
    return (q * q) % mod;
}


int choose(int n,int r)
{
    if(n<r || r==0)
    {
        if(n<r)
            return 0;
        else
            return 1;
    }
    return ((power(pre[r],mod-2)*pre[n])%mod * power(pre[n-r],mod-2)%mod)%mod;
}

signed main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    calc();
    int t;
    cin >> t;
    while(t--)
    {
        int n;
        cin >> n;
        int a[n];
        for(int i=0;i<n;i++)
        {
            cin >> a[i];
        }
        sort(a,a+n);
        int sol;
        sol = pre[n];
        int cnt = 0;
        for(int i=0;i<n;i++)
        {
            if(a[i]<a[n-2])
                cnt++;
        }
        int comp;
        if(a[n-1]>1+a[n-2])
        {
            cout << "0\n";
            continue;
        }
        if(a[n-2]==a[n-1])
        {
            cout << sol << "\n";
            continue;
        }
        comp = 0;
        for(int i=0;i<cnt+1;i++)
        {
            comp = (comp + ((pre[i]*((choose(cnt,i)*pre[n-i-1])%mod))%mod)%mod)%mod;
        }
        sol = (sol-comp+mod)%mod;
        cout << (sol%mod) << "\n";
    }
    return 0;
}
