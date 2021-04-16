//Bismillahir Rahman-ir Rahim
#include <bits/stdc++.h>
using namespace std;
#define debug(x) cout << '>' << #x << " : " << x << endl;
#define all(c) c.begin(), c.end()
#define F first
#define S second
typedef unsigned long long ull;
typedef long long ll;


int main() {

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r" , stdin);
    freopen("output.txt", "w" , stdout);
#endif

    ll n, k;
    cin >> n >> k;
    vector<ll> ara(n);
    for(ll i = 0; i  < n; i++){
        cin >> ara[i];
    }
    sort(all(ara));

    ll high = k, low = 0;
    ll last;
    ll ans = 0;
    while(low <= high) {
        
        ll mid = low + (high - low)/2;
        ll temp = k;

        last = ara[n/2] + mid;

        temp -= mid;
        bool f = 1;
        for(ll i = (n/2) + 1; i < n; i++){
            
            if(ara[i] + temp < last){
                f =0;
                break;
            }
            else{
                temp -= (last - ara[i]);
            }

        }

        if(f){
            low = mid+1;
            ans = max(ans, last);
        }
        else{
            high = mid-1;
        }
    }
    cout << ans << endl;

    
    return 0;
}