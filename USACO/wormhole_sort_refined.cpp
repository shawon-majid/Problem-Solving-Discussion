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

const int mx = 1e5+7;

vector <pair <int, int> > adj[mx];
            //node, cost
vector <int> connected(mx); // connected components will have same level
vector <int> p(mx);
int n, m;


void dfs(int source, int level, int minW){
    connected[source] = level;

    for(auto v: adj[source]){
        if(connected[v.first] == -1 and v.second >= minW){
            dfs(v.first, level, minW);
        }
    }
}

bool ok(int minW){

    fill(all(connected), -1); // -1 means not connected / visited
    int level = 0;
    for(int i = 1; i <= n; i++){
        if(connected[i] == -1){
            dfs(i, level, minW);
            level++;
        }
    }
    for(int i = 1; i <= n; i++){
        if(connected[i] != connected[p[i]]){
            return false;
        }
    }
    return true;
}


int main() {

    setIO("wormsort");
    
    cin >> n >> m;
    
    for(int i = 1; i <= n; i++){
        cin >> p[i];
    }

    for(int i = 0; i < m; i++){
        int u, v, c;
        cin >> u >> v >> c;
        adj[u].push_back({v, c});
        adj[v].push_back({u, c});   
    }   

    // binary search on answer
    ll ans = -1;
    ll lo = 1, hi = 1e9+5, top = hi;

    while(lo <= hi){
        ll mid = lo + ((hi - lo)/2);
        if(ok(mid)){
            ans = max(ans, mid);
            lo = mid+1;
        }
        else{
            hi = mid-1;
        }
    }

    if(ans == top){
        cout << -1 << endl;
    }
    else{
        cout << ans << endl;
    }
    return 0;

}