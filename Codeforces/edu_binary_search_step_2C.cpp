//Bismillahir Rahman-ir Rahim
#include <bits/stdc++.h>
using namespace std;
#define debug(x) cout << '>' << #x << " : " << x << endl;
#define all(c) c.begin(), c.end()
#define F first
#define S second
typedef unsigned long long ull;
typedef long long ll;

bool ok(ll m, ll mn, ll mx, ll n)
{
    if(m < mn) return 0;
    m -= mn;
    return (m/mn) + (m/mx) + 1 >= n;
}

int main() {

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r" , stdin);
    freopen("output.txt", "w" , stdout);
#endif

    ll n, x, y;
    cin >> n >> x >> y;

    ll mn = min(x, y), mx = max(x, y);

    
    ll l, r, m;
    l = 0; // not possible 
    r = mn*n; // possible
    

    while(l+1 < r){
        ll m = (l+r)/2;
        if(ok(m, mn, mx, n)){
            r = m;
        }
        else{
            l = m;
        }
    }
    
    cout << r << endl;
    
    return 0;
}
