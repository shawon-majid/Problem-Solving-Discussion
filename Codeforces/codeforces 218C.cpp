//Bismillahir Rahman-ir Rahim
#include <bits/stdc++.h>
using namespace std;
#define debug(x) cout << '>' << #x << " : " << x << endl;
#define all(c) c.begin(), c.end()
#define F first
#define S second
typedef unsigned long long ull;
typedef long long ll;

vector <int> adj[100000];

int vis[100000];

void bfs(int source){
    vis[source] = 1;
    queue <int> q;
    q.push(source);

    while(!q.empty()){
        int u = q.front();
        q.pop();
        for(auto v: adj[u]){
            if(!vis[v]){
                vis[v] = 1;
                q.push(v);
            }
        }
    }
}

int connected_components(int n){
    int cnt = 0;
    for(int i = 0; i < n; i++){
        if(!vis[i]){
            cnt++;
            bfs(i);
        }
    }

    return cnt;
}


int main(){

    int n;
    cin >> n;

    vector <pair <int, int> > p(n);

    for(int i = 0; i < n; i++){
        cin >> p[i].first >> p[i].second;
    }

    for(int i = 0; i < n; i++){
        for(int j = i+1; j < n; j++){
            if(p[i].first == p[j].first || p[i].second == p[j].second){
                adj[i].push_back(j);
                adj[j].push_back(i);
            }
        }
    }

    cout << connected_components(n) - 1 << endl;


    return 0;
}