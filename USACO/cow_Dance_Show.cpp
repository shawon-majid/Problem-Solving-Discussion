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

    setIO("cowdance");
    
    ll n, T;
    cin >> n >> T;

    vector <ll> ara(n);

    for(ll i = 0; i < n; i++) cin >> ara[i];

    //sort(ara.rbegin(), ara.rend());

    ll high = n, low = 0;
    ll mid, ans = LLONG_MAX;
    while(low <= high){
        mid = low + (high - low) / 2;
        priority_queue < ll, vector <ll>, greater <ll> > pq;
        ll mx  = 0;
        ll i;
        for(i = 0; i < mid; i++){
            pq.push(ara[i]);
            mx = max(mx, ara[i]);
        }
        for(; i < n; i++){
            ll temp = pq.top();
            temp += ara[i];
            pq.pop();
            pq.push(temp);
            mx = max(mx, temp);
        }
        if(mx <= T){
            ans = min(ans, mid);
            high = mid-1;
        }
        else{
            low = mid+1;
        }
    }

    cout << ans  << endl;
    return 0;

}
