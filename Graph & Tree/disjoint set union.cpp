//Bismillahir Rahman-ir Rahim
#include <bits/stdc++.h>
using namespace std;
#define debug(x) cout << '>' << #x << " : " << x << endl;
#define all(c) c.begin(), c.end()
#define F first
#define S second
#define fastIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
typedef unsigned long long ull;
typedef long long ll;

const int mx = 2e5+10;

vector < int > parent(mx);
vector < int > sz(mx);

int numberOfComponents;

void init(int n){
    for(int i = 1; i <= n; i++){
        parent[i] = i;
        sz[i] = 1;
    }
}


int findSet(int a){
    if(parent[a] == a){
        return a;
    }
    parent[a] = findSet(parent[a]);
    return parent[a];
}

void unionSet(int a, int b){
    a = findSet(a);
    b = findSet(b);

    if(a != b){
        if(sz[a] >= sz[b]){
            parent[b] = a;
            sz[a] += sz[b];
        }
        else{
            parent[a] = b;
            sz[b] += sz[a];
        }
        numberOfComponents--;
    }
}

int main(){


    int n, m, q;
    cin >> n >> m >> q;

    init(n);

    for(int i = 0; i < m; i++){
        int u, v;
        cin >> u >> v;
        unionSet(u, v);
    }
    while(q--){
        int u, v;
        cin >> u >> v;

        if(findSet(u) == findSet(v)){
            cout << "Friends" << endl;
        }
        else{
            cout << "Enemy" << endl;
        }
    }


    return 0;
}
