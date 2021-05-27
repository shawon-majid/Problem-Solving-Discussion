//Bismillahir Rahman-ir Rahim
#include <bits/stdc++.h>
using namespace std;
#define debug(x) cout << '>' << #x << " : " << x << endl;
#define all(c) c.begin(), c.end()
#define F first
#define S second
typedef unsigned long long ull;
typedef long long ll;

char grid[105][105];
int vis[105][105];

int dx[] = {1, -1, 0, 0, 1, 1, -1, -1};
int dy[] = {0, 0, 1, -1, 1, -1, 1, -1};


bool valid(pair <int, int> v, int m, int n){
    if(grid[v.first][v.second] == '@' and v.first >= 1 and v.first <= m and v.second >= 1 and v.second <= n){
        return 1;
    }
    return 0;
}

void bfs(pair <int, int> source, int m, int n){
    vis[source.first][source.second] = 1;
    queue <pair <int, int> > q;
    q.push(source);
    while(!q.empty()){
        pair <int,int> u = q.front();
        q.pop();
        for(int i = 0; i < 8; i++){
            pair<int, int> v;
            v.first = u.first + dx[i];
            v.second = u.second + dy[i];
            if(!vis[v.first][v.second] and valid(v, m, n)){
                vis[v.first][v.second] = 1;
                q.push(v);
            }
        }

    }
}



int bfs_connected(int m, int n){
    int ans = 0;
    for(int i = 1; i <= m; i++){
        for(int j = 1; j <= n; j++){
            if(!vis[i][j] and valid({i, j}, m, n)) {
                ans++;
                bfs({i, j}, m, n);
            }
        }
    }
    return ans;
}


int main() {
    
    while(1) {
        int m, n;
        cin >> m >> n;
        if(m == 0) break;
        for(int i = 1; i <= m; i++){
            for(int j = 1; j <= n; j++){
                cin >> grid[i][j];
                vis[i][j] = 0;
            }
        }

        cout << bfs_connected(m, n) << endl;

    }
    
    return 0;
}