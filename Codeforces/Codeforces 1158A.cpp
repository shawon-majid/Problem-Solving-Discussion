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

    int n, m;
    cin >> n >> m;
    vector <int> b(n), g(m);
    for(int i = 0; i < n; i++){
        cin >> b[i];
    }    
    for(int i = 0; i < m; i++) cin >> g[i];

    if(*max_element(all(b)) > *min_element(all(g))){
        cout << -1 << endl;
        return 0;
    }
    sort(all(b));
    sort(all(g));
    ll ans = 0;
    if(b.back() == g[0]){
        for(int i = 0; i < n-1; i++){
            ans += (ll)m*b[i];
        }
        for(int i = 0; i < m; i++){
            ans += (ll)g[i];
        }
        cout << ans << endl;
    }
    else{
        for(int i = 0; i < n-1; i++){
            ans += (ll)m*b[i];
        }
        for(int i = 0; i < m; i++){
            ans += (ll)g[i];
        }
        ans += (ll)b.back();
        ans -= (ll)b[n-2];
        cout << ans << endl;
    }

}