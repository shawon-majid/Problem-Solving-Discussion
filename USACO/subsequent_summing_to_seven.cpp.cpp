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

    setIO("div7");
    long long int n;
    cin >> n;
    vector <long long> ara(n), pre(n);
    for(int i = 0;i < n; i++){
        cin >> ara[i];
    }
    pre[0] = ara[0];
    for(int i = 1; i < n; i++){
        pre[i] = pre[i-1] + ara[i];
    }
    ll ans = 0, sum = 0;
    map <long long, long long> mp;
    for(int i = 0; i < n; i++){
        ll ind = i+1;
        ll need = pre[i] % 7;
        if(need == 0){
            ans = max(ans, ind);
        }
        if(mp[need] != 0){
            ans = max(ans, (ind - mp[need]));
        }
        else{
            mp[need] = ind;
        }
    }
    cout << ans << endl;
    return 0;
}