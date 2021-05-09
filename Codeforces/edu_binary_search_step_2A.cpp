//Bismillahir Rahman-ir Rahim
#include <bits/stdc++.h>
using namespace std;
#define debug(x) cout << '>' << #x << " : " << x << endl;
#define all(c) c.begin(), c.end()
#define F first
#define S second
typedef unsigned long long ull;
typedef long long ll;


bool f(ll m, ll w, ll h, ll n)
{
    return (m/w)*(m/h) >= n;
}

int main() {

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r" , stdin);
    freopen("output.txt", "w" , stdout);
#endif

    ll w, h, n;
    cin >> w >> h >> n;

    ll l = 0, r = 1;
    while(!f(r, w, h, n)) r*=2;

    while(l+1 < r) {
        ll m = l + (r - l)/2;
        if(f(m, w, h, n)){
            r = m;
        }
        else{
            l = m;
        }
    }
    cout << r << endl;

    return 0;
}