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

    setIO("pairup");
    int n;
    cin >> n;

    vector< pair<int, int > > vp(n);

    for(int i = 0; i < n; i++){
        int x, y;
        cin >> x >> y;
        vp[i].F = y;
        vp[i].S = x;
    }
    sort(all(vp));
    int i = 0, j = n-1;
    ll ans = 0;
    while(i <= j) {
        if(i == j){ 
            ans = max(ans, (ll)(vp[i].F*2));
            break;
        }

        int bad = min(vp[i].S, vp[j].S);

        ans = max(ans, (ll)(vp[i].F+vp[j].F));

        vp[i].S -= bad;
        if(vp[i].S == 0){
            i++;
        }
        vp[j].S -= bad;
        if(vp[j].S == 0){
            j--;
        }
    }
    cout << ans << endl;
    return 0;
}