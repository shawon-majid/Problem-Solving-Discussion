//Bismillahir Rahman-ir Rahim
#include <bits/stdc++.h>
using namespace std;
#define debug(x) cout << '>' << #x << " : " << x << endl;
#define all(c) c.begin(), c.end()
#define F first
#define S second
typedef unsigned long long ull;
typedef long long ll;

const int inf = 1000000000;

unordered_map <int, vector <pair <int,int> > > adj;
vector <int> cost(1005, inf);


bool bellmanFordNegativeCycle(int n){
    cost.clear();
    cost.resize(1005, inf);   
    cost[0] = 0;
    // path relaxation n-1 times
    for(int i = 0; i < n-1; i++){
        for(int u = 0; u < n; u++){
            for(auto v: adj[u]){
                if(cost[u] + v.first < cost[v.second]){
                    cost[v.second] = cost[u] + v.first;
                }
            }
        }
    }
    //detect if there exist negative cycle
    for(int u = 0; u < n; u++){
        for(auto v: adj[u]){
            if(cost[u] + v.first < cost[v.second]){
                return 1; 
            }
        }
    }
    return 0;
}

int main() {
    
    int T;
    cin >> T;
    while(T--){
        int n, m;
        cin >> n >> m;
        for(int i = 0; i < m; i++){
            int u, v, c;
            cin >> u >> v >> c;
            adj[u].push_back(make_pair(c, v));            
        }
        if(bellmanFordNegativeCycle(n)){
            cout << "possible" << endl;
        }
        else cout << "not possible" << endl;
        adj.clear();
    }

    return 0;
}
