//Bismillahir Rahman-ir Rahim
#include <bits/stdc++.h>
using namespace std;
#define debug(x) cout << '>' << #x << " : " << x << endl;
#define all(c) c.begin(), c.end()
#define F first
#define S second
typedef unsigned long long ull;
typedef long long ll;

const int mx = 2e5+7;
vector <int> adj[mx];

int cnt[mx];


void dfs(int curNode, int prevNode){
    cnt[curNode] = 1;

    for(auto v: adj[curNode]){
        if(v != prevNode){
            dfs(v, curNode);
            cnt[curNode] += cnt[v];
        }
    }
}

int main(){

    int n;
    cin >> n;

    for(int i = 2; i <= n; i++){
        int x;
        cin >> x;
        adj[i].push_back(x);
        adj[x].push_back(i);
    }

    dfs(1, -1);


    for(int i = 1; i <= n; i++){
        cout << cnt[i]-1 << " ";
    }
    cout << endl;

    return 0;
}