//Bismillahir Rahman-ir Rahim
#include <bits/stdc++.h>
using namespace std;
#define debug(x) cout << '>' << #x << " : " << x << endl;
#define all(c) c.begin(), c.end()
#define F first
#define S second
typedef unsigned long long ull;
typedef long long ll;

unordered_map <string, vector <string> > adj;
unordered_map <string, int> vis;
unordered_map <string, int> level;


void bfs(string source){
    queue <string> q;
    vis[source] = 1;
    level[source] = 0;
    q.push(source);
    while(!q.empty()){
        string u = q.front();
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
    
    int T;
    cin >> T;
    while(T--){
        vector <string> dictionary;
        while(1){
            string str;
            cin >> str;
            if(str == "*") break;
            dictionary.push_back(str);
        }
        vector <pair<string, string> > ps;
        getchar();
        while(1){
            string str;
            getline(cin, str);
            if(str[0] == '\0') break;
            string w1 = "", w2 = "";
            bool getSecondWord = 0;
            for(int i = 0; i < str.size(); i++){
                if(str[i] == ' '){
                    getSecondWord = 1;
                    continue;
                }
                if(getSecondWord){
                    w2 += str[i];
                }
                else w1 += str[i];
            }
            ps.push_back({w1, w2});
            
        }

        // make the graph
        for(int i = 0; i < dictionary.size(); i++){
            string currentWord = dictionary[i];
            int currentWordSize = currentWord.size();
            for(int j = i+1; j < dictionary.size(); j++){
                int dif = 0;
                if(currentWordSize == dictionary[j].size()){
                    for(int k = 0; k < currentWordSize; k++){
                        if(currentWord[k] != dictionary[j][k]) dif++;
                    }
                    if(dif == 1){
                        adj[currentWord].push_back(dictionary[j]);
                        adj[dictionary[j]].push_back(currentWord);
                    }
                }
            }
        }

        // find the shortest path
        for(int i = 0; i < ps.size(); i++){
            vis.clear();
            level.clear();
            bfs(ps[i].first);
            cout <<ps[i].first << " " << ps[i].second <<" " <<level[ps[i].second] << endl;
        }
        if(T != 0)cout << endl;
        adj.clear();
    }
    
    return 0;
}