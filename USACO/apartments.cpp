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

    // freopen("input.txt", "r" , stdin);
    // freopen("output.txt", "w" , stdout);
    
    ll n, m, k;
    cin >> n >> m >> k;
    vector <ll> applicants(n);
    multiset <ll> apartments;
    for(ll i = 0; i < n; i++) cin >> applicants[i];
    for(ll i = 0; i < m; i++){
        ll x;
        cin >> x;
        apartments.insert(x);
    }
    
    sort(all(applicants));
    
    ll ans = 0;
    for(ll i = 0; i < n; i++){
        ll l = applicants[i] - k, h = applicants[i] + k;
        
        auto it = apartments.lower_bound(l);
        if(it == apartments.end()) {
            continue;
        }
        
        if(*it >= l and *it <= h){
            ans++;
            apartments.erase(it);
        }
        
    }
    cout << ans << endl;


    return 0;
}