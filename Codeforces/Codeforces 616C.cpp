//Bismillahir Rahman-ir Rahim
#include <bits/stdc++.h>
using namespace std;
#define debug(x) cout << '>' << #x << " : " << x << endl;
#define all(c) c.begin(), c.end()
#define F first
#define S second
typedef unsigned long long ull;
typedef long long ll;

char mat[2000][2000];
int n, m;
int vis[2000][2000];
int type[2000][2000];
int k = 0;
map <int, int> cnt;
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};

bool valid(pair <int, int> v){
    if(v.F >= 0 and v.F < n and v.S >= 0 and v.S < m and mat[v.F][v.S] == '.') return 1;
    return 0;
}

void bfs(pair <int, int> source){
    k++;
    vis[source.F][source.S] = 1;
    type[source.F][source.S] = k;
    cnt[k]++;
    queue <pair <int, int> > q;
    q.push(source);
    while(!q.empty()){
        pair <int, int> u = q.front();
        q.pop();
        for(int i = 0; i < 4; i++){
            pair <int, int> v;
            v.F = u.F + dx[i];
            v.S = u.S + dy[i];
            if( valid(v) and !vis[v.F][v.S] ){
                vis[v.F][v.S] = 1;
                type[v.F][v.S] = k;
                cnt[k]++;
                q.push(v);
            }
        }
    }
}

int main() {

    cin >> n >> m;
    for(int i = 0; i < n; i++){
        string str;
        cin >> str;
        for(int j = 0; j < m; j++){
            mat[i][j] = str[j];
        }
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(mat[i][j] == '.' and !vis[i][j]){
                pair <int, int> source = make_pair(i, j);
                bfs(source);
            }
        }
    }

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(mat[i][j] == '*'){
                set <int> s;
                for(int k = 0; k < 4; k++){
                    int u, v;
                    u = i + dx[k];
                    v = j + dy[k];
                    if(valid(make_pair(u, v))){
                        s.insert(type[u][v]);
                    }
                }
                int ans = 1;
                for(auto x: s){
                    ans += cnt[x];
                }
                mat[i][j] = (ans % 10) + '0';
            }
        }
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cout << mat[i][j];
        }
        cout << endl;
    }

    return 0;
}
