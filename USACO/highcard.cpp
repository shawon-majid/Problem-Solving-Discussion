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

    setIO("highcard");
    int n;
    cin >> n;
    vector <int> bessie, elsie(n);
    map <int, int> mp;
    for(int i = 0; i < n; i++){
        cin >> elsie[i];
        mp[elsie[i]]++;
    }
    for(int i = 1; i <= 2*n; i++){
        if(!mp[i]) bessie.push_back(i);
    }
    sort(all(elsie));
    int point = 0;
    for(int i = 0, j = 0; j < n; ){
        if(bessie[j] > elsie[i]){
            point++;
            i++;
            j++;
        }
        else{
            j++;
        }
    }
    cout << point << endl;

    return 0;

}