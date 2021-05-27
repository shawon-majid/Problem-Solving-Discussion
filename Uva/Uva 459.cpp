//Bismillahir Rahman-ir Rahim
#include <bits/stdc++.h>
using namespace std;
#define debug(x) cout << '>' << #x << " : " << x << endl;
#define all(c) c.begin(), c.end()
#define F first
#define S second
typedef unsigned long long ull;
typedef long long ll;


unordered_map <char, vector <char> > adj;
unordered_map <char, int> vis;


void bfs(char source){
    vis[source] = 1;
    queue <char> q;
    q.push(source);
    while(!q.empty()){
        char u = q.front();
        q.pop();
        for(auto v: adj[u]){
            if(!vis[v]){
                q.push(v);
                vis[v] = 1;
            }
        }
    }
}

int bfs_connected(char last){
    int ans = 0;
    for(char i = 'A'; i <= last; i++){
        if(!vis[i]){
            ans++;
            bfs(i);
        }
    }
    return ans;
}

int main() {

    int T;
    cin >> T;
    getchar();
    getchar();
    while(T--) {
        
        char c;
        cin >> c;  
        //debug(c);
        getchar();
        vector <string> v;
        // taking input of graph
        while(1){
            string str;
            getline(cin, str);
            if(str[0] == '\0') break;
            
            adj[str[0]].push_back(str[1]);
            adj[str[1]].push_back(str[0]);
        }
        
        cout << bfs_connected(c) << endl;
        if(T != 0) cout << endl;
        adj.clear();
        vis.clear();
    }
    
    return 0;
}