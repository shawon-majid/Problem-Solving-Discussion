//Bismillahir Rahman-ir Rahim
#include <bits/stdc++.h>
using namespace std;
#define debug(x) cout << '>' << #x << " : " << x << endl;
#define all(c) c.begin(), c.end()
#define F first
#define S second
typedef unsigned long long ull;
typedef long long ll;

const ll inf = 1000000000000000;

vector < vector <pair <ll, ll> > > adj(100005);
                                /*cost, node*/
vector <ll> path(100005);
vector <ll> cost(100005);


void Dijkstra(ll source){
    cost.clear();
    cost.resize(100005, inf);
    cost[source] = 0;
    priority_queue <pair <ll, ll> > q;
                        /*cost, node*/
    q.push({-cost[source], source});
    while(!q.empty()){
        ll u = q.top().second;
        q.pop();
        for(auto v: adj[u]){
            if(cost[u] + v.first < cost[v.second]){
                path[v.second] = u;
                cost[v.second] = cost[u] + v.first;
                q.push({-cost[v.second], v.second}); 
            }
        }
    }
}                   

void showPath(ll start, ll finish){
    vector<ll>v;
    v.push_back(finish);
    ll now = finish;
    while(1)
    {
        v.push_back(path[now]);
        if(path[now] == start) break;
        now = path[now];
    }
    reverse(all(v));
    for(auto c: v) cout << c << " ";
}

int main() {

    ll n, m;
    
    cin >> n >> m;
    for(ll i = 0; i < m; i++){
        ll u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({w, v});
        adj[v].push_back({w, u});
    }

    Dijkstra(1);
    
    if(cost[n] != inf) showPath(1, n);
    else cout << -1 << endl;
    
    adj.clear();
    path.clear();

    return 0;
    
}