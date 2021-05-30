//Bismillahir Rahman-ir Rahim
#include <bits/stdc++.h>
using namespace std;
#define debug(x) cout << '>' << #x << " : " << x << endl;
#define all(c) c.begin(), c.end()
#define F first
#define S second
typedef unsigned long long ull;
typedef long long ll;

unordered_map <int, vector <pair <int, int> > > adj;
             // u                v     cost
vector <int> cost(20005, INT_MAX);
unordered_map <int, int> vis;

void dijkstra(int source){
    cost.clear();
    cost.resize(20005, INT_MAX);
    cost[source] = 0;
    
    priority_queue <pair <int, int> > q; 
                        //cost, node
    q.push({-cost[source], source});
    while(!q.empty()){
        int u = q.top().second;
        q.pop();        
        for(auto v: adj[u]){                      
            if(cost[u] + v.second < cost[v.first]){     /*notice the difference we don't use vis[] in dijakstra because we may need to visit a node more than once*/
                cost[v.first] = cost[u] + v.second;
                q.push({-cost[v.first], v.first});
            }
        }
    }
}

int main() {

    int N, cs = 1;
    cin >> N;
    while(N--){
        int n, m, S, T;
        cin >> n >> m >> S >> T;
        for(int i = 0; i < m; i++){
            int u, v, c;
            cin >> u >> v >> c;
            adj[u].push_back({v, c});
            adj[v].push_back({u, c});
        }

        dijkstra(S);
        if(cost[T] != INT_MAX) cout <<"Case #"<<cs <<": " << cost[T] << endl;
        else cout <<"Case #"<<cs <<": "<< "unreachable"<< endl;
        adj.clear();
        cs++;
    }

    
    return 0;
}
