//Bismillahir Rahman-ir Rahim
#include <bits/stdc++.h>
using namespace std;
#define debug(x) cout << '>' << #x << " : " << x << endl;
#define all(c) c.begin(), c.end()
#define F first
#define S second
typedef unsigned long long ull;
typedef long long ll;

int adj[105][105];

const int inf = 1000000000;

int main() {
    
    for(int i = 0; i < 105; i++){
        for(int j = 0; j < 105; j++){
            if(i == j) adj[i][j] = 0;
            else adj[i][j] = inf; 
        }
    }
    
    int n, e, t, m;
    cin >> n >> e >> t >> m;

    for(int i = 0; i < m; i++){
        int u, v, w;
        cin >> u >> v >> w;
        adj[u][v] = w;
    }

    for(int k = 1; k <= n; k++){
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= n; j++){
                if(adj[i][k] + adj[k][j] < adj[i][j]){
                    adj[i][j] = adj[i][k] + adj[k][j];
                }
            }
        }
    }
    int ans = 0;
    for(int i = 1; i <= n; i++){
        if(adj[i][e] <= t) ans++;
    }
    cout << ans << endl;
    return 0;
}
