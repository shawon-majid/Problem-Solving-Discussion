#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using vi = vector<int>;
#define all(x) begin(x), end(x)
using pi = pair<int,int>;
#define F first
#define S second

void setIO(string name = "") { // name is nonempty for USACO file I/O

    ios_base::sync_with_stdio(0); cin.tie(0); // see Fast Input & Output

    // alternatively, cin.tie(0)->sync_with_stdio(0);

    if (name.size()) {

        freopen((name+".in").c_str(), "r", stdin); // see Input & Output

        freopen((name+".out").c_str(), "w", stdout);

    }

}


int main() {

    setIO("socdist");
    
    ll n, m;
    cin >> n >> m;
    vector<pair <ll, ll> > vp(m);
    for(ll i = 0; i < m; i++){
        cin >> vp[i].F >> vp[i].S;
    }
    sort(all(vp));
    ll low = 1, high = vp[m-1].S - vp[0].F;
    ll last = LLONG_MIN, ans = LLONG_MIN;

    while(low <= high) {
        ll mid = low + (high - low) / 2;
        last = LLONG_MIN;
        ll c = 0;
        for(ll i = 0; i < m; i++){
            ll cur = last + mid;
            if(cur <= vp[i].S){
                ll r1 = max(cur, vp[i].F), r2 = vp[i].S;
                ll count_in_range = ((r2 - r1) / mid) + 1;
                c += count_in_range;
                last = r1 + (count_in_range-1)*mid;
            }
        }
        if(c < n){
            high = mid-1;
        }
        else{
            ans = max(ans, mid);
            low = mid+1;
        }
    }
    cout << ans << endl;
    
    return 0;
}
