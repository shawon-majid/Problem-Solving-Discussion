//Bismillahir Rahman-ir Rahim
#include <bits/stdc++.h>
using namespace std;
#define debug(x) cout << '>' << #x << " : " << x << endl;
#define all(c) c.begin(), c.end()
#define F first
#define S second
typedef unsigned long long ull;
typedef long long ll;


unordered_map <int, vector <int> > adj;
unordered_map <int, int> vis;
unordered_map <int, int> level;

void bfs(int source){
    level.clear();
    vis.clear();
    vis[source] = 1;
    level[source] = 0;
    queue <int> q;
    q.push(source);
    while(!q.empty()){
        int u = q.front();
        q.pop();
        for(auto v: adj[u]){
            if(!vis[v]){
                vis[v] = 1;
                level[v] = level[u] + 1;
                q.push(v);
            }
        }
    }
}


int main() {

    int T, cs = 1;
    cin >> T;
    while(T--){
        int n, r;
        cin >> n >> r;
        for(int i = 0; i < r; i++){
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        int start, finish;
        cin >> start >> finish;
        unordered_map <int, int> levelFromStart;
        bfs(start);
        
        levelFromStart = level;
        
        int ans = 0;
        for(auto x: adj){
            int node = x.first;    
            bfs(node);
            ans = max(ans, levelFromStart[node] + level[finish]);
        }
        cout <<"Case "<<cs<<": "<< ans << endl;
        adj.clear();
        levelFromStart.clear();
        cs++;
    }

    return 0;
}