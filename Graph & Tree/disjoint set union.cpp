//Bismillahir Rahman-ir Rahim
#include <bits/stdc++.h>
using namespace std;
#define debug(x) cout << '>' << #x << " : " << x << endl;
#define all(c) c.begin(), c.end()
#define F first
#define S second
typedef unsigned long long ull;
typedef long long ll;

int captain[100000];

void delegateCaptain(int v){
    captain[v] = v;
}

void init(int n){
    for(int i = 1; i <= n; i++){
        delegateCaptain(i);
    }
}

int findRepresentative(int u){
    if(captain[u] == u){
        return u;
    }
    captain[u] = findRepresentative(captain[u]);
    return captain[u];
}

void makeFriends(int u, int v){
    u = findRepresentative(u);
    v = findRepresentative(v);
    if(u != v){
        captain[u] = v;
    }
}


int main() {
    
    int n, m, q;
    cin >> n >> m >> q;

    init(n);

    for(int i = 0; i < m; i++){
        int u, v;
        cin >> u >> v;
        makeFriends(u, v);
    }
    while(q--){
        int u, v;
        cin >> u >> v;

        if(findRepresentative(u) == findRepresentative(v)){
            cout << "Friends" << endl;
        }
        else{
            cout << "Enemy" << endl;
        }
    }

    
    return 0;
}
