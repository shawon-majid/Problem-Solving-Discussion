#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using vi = vector<int>;
#define all(x) begin(x), end(x)
using pi = pair<int,int>;
#define F first
#define S second

void setIO(string name = "") { // name is nonempty for USACO file I/O

    ios_base::sync_with_stdio(0); cin.tie(0); // see Fast Input & Output

    // alternatively, cin.tie(0)->sync_with_stdio(0);

    if (name.size()) {

        freopen((name+".in").c_str(), "r", stdin); // see Input & Output

        freopen((name+".out").c_str(), "w", stdout);

    }

}


int main() {

    setIO("cardgame");
    
    int n;
    cin >> n;
    vector <int > elsie1, elsie2, bessie;
    map <int, int> used;
    for(int i = 0; i < n/2; i++){
        int x;
        cin >> x;
        elsie1.push_back(x);
        used[x] = 1;
    }
    for(int i = n/2; i < n; i++){
        int x;
        cin >> x;
        elsie2.push_back(x);
        used[x] = 1;
    }
    for(int i = 1; i <= 2*n; i++){
        if(!used[i]){
            bessie.push_back(i);
        }
    }
    sort(all(bessie));

    // first half
    sort(all(elsie1));
    int ans = 0;
    for(int i = 0, j = n/2; j < n; j++){
        if(bessie[j] > elsie1[i]){
            ans++;
            i++;
        }
    }
    // second half
    sort(elsie2.rbegin(), elsie2.rend());


    for(int i = 0, j = (n/2)-1 ; j >= 0; j--){
        if(bessie[j] < elsie2[i]){
            ans++;
            i++;
        }
    }
    cout << ans << endl;

    
    return 0;
}