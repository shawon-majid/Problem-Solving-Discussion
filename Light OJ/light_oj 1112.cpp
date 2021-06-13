//Bismillahir Rahman-ir Rahim
#include <bits/stdc++.h>
using namespace std;
#define debug(x) cout << '>' << #x << " : " << x << endl;
#define all(c) c.begin(), c.end()
#define F first
#define S second
typedef unsigned long long ull;
typedef long long ll;

vector <int> tree;

ll query(int node, int treeLeft, int treeRight, int queryLeft, int queryRight, int x){
    if(treeLeft >= queryLeft and treeRight <= queryRight){
        int ans = tree[node];
        if(x == -1){
            tree[node] = 0;
        }
        else if(x != -2){
            tree[node] += x;
        }
        return ans;
    }
    if(treeLeft > queryRight or treeRight < queryLeft){
        return 0;
    }
    int mid = (treeLeft + treeRight)/2;
    ll ans = query(2*node, treeLeft, mid, queryLeft, queryRight, x) + query((2*node) + 1, mid+1, treeRight, queryLeft, queryRight, x);
    tree[node] = tree[2*node] + tree[2*node + 1];
    return ans;
}


int main() {

    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    
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
            ara.push_back(0);
            n++;
        }

        // make tree
        tree.resize(2*n);
        for(int i = 0; i < n; i++){
            tree[n+i] = ara[i];
        }
        for(int i = n-1; i >= 1; i--){
            tree[i] = tree[2*i] + tree[2*i + 1];
        }

        cout << "Case "<<cs<<":"<< endl;
        while(q--){
            int type;
            cin >> type;
            if(type == 1){
                int ind;
                cin >> ind;
                cout << query(1, 0, n-1, ind, ind, -1) << endl; // -1 means make it 0 afterwards
            }
            else if(type == 2){
                int v, ind;
                cin >> ind >> v;
                query(1, 0, n-1, ind, ind, v); // means add v at index ind
            }
            else{
                int l, r;
                cin >> l >> r;
                cout << query(1, 0, n-1, l, r, -2) << endl; // -2 means dont change anything
            }

            //printTree(2*n);
        }
        tree.clear();
        cs++;
    }
    

    return 0;
}

