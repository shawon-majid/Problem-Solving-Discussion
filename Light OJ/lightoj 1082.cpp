//Bismillahir Rahman-ir Rahim
#include <bits/stdc++.h>
using namespace std;
#define debug(x) cout << '>' << #x << " : " << x << endl;
#define all(c) c.begin(), c.end()
#define F first
#define S second
typedef unsigned long long ull;
typedef long long ll;

const int inf = 10000000;

vector <int> tree;

int RangeMinimumQuery(int node, int node_low, int node_high, int l, int r){
    if(node_low >= l and node_high <= r){
        return tree[node];
    }
    if(r < node_low || l > node_high){
        return inf;
    }

    int mid = (node_low + node_high)/2;
    return min(RangeMinimumQuery(2*node, node_low, mid, l, r), RangeMinimumQuery(2*node + 1, mid+1, node_high, l, r));
}

int main() {

    int T, cs = 1;
    cin >> T;
    while(T--){
        int n, q;
        cin >> n >> q;
        vector <int> ara(n);
        for(int i = 0; i < n; i++){
            cin >> ara[i];
        }

        while(__builtin_popcount(n) != 1){
            ara.push_back(inf);
            n++;
        }

        tree.resize(2*n);

        // build the tree;
        for(int i = 0; i < n; i++){
            tree[n+i] = ara[i];
        }
        for(int i = n-1; i >= 1; i--){
            tree[i] = min(tree[2*i], tree[2*i + 1]);
        }
        cout << "Case " <<cs<<":"<< endl;
        while(q--){
            int l, r;
            cin >> l >> r;
            l--, r--;
            cout << RangeMinimumQuery(1, 0, n-1, l, r) << endl;
        }
        cs++;
    }

    return 0;
}
