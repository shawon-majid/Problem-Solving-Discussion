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
    
    ll n, t;
    cin >> n >> t;

    vector<ll> ara(n);
    for(int i = 0; i < n; i++){
        cin >> ara[i];
    }
    ll minel = *min_element(all(ara));

    ll ans = LLONG_MAX;
    ll high = t*minel, low  = 0;
    while(low <= high) {
        ll mid = low + (high - low)/2;
        ll products = 0;
        for(int i = 0; i < n; i++){
            products += (mid/ara[i]);
        }
        if(products >= t){
            ans = min(ans, mid);
            high = mid - 1;
        }
        else{
            low = mid+1;
        }
    }
    cout << ans << endl;
    
    return 0;
}
