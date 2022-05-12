//Bismillahir Rahman-ir Rahim
#include <bits/stdc++.h>
using namespace std;
#define debug(x) cout << '>' << #x << " : " << x << endl;
#define all(c) c.begin(), c.end()
#define F first
#define S second
#define fastIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
typedef unsigned long long ull;
typedef long long ll;

struct STree{   
    vector <ll> tree;
    vector <ll> ara;
    STree(vector < ll > pArray){
        ara = pArray;
        ll n = ara.size();
        while(__builtin_popcount(n) != 1){
            ara.push_back(0);
            n++;
        }
        tree.resize(2*n);
        build(1, 0, n-1);
    }   

    // build the tree
    void build(ll node, ll nodeLeft, ll nodeRight){
        if(nodeLeft == nodeRight){
            tree[node] = ara[nodeLeft];
            return;
        }

        ll lastInLeft = (nodeLeft+nodeRight)/2;
        build(2*node, nodeLeft, lastInLeft);
        build(2*node+1, lastInLeft+1, nodeRight);
        tree[node] = tree[2*node] + tree[2*node+1];
        return;
    }


    ll query(ll node, ll nodeLeft, ll nodeRight, ll queryLeft, ll queryRight){
        if(nodeLeft >= queryLeft and nodeRight <= queryRight){
            return tree[node];
        }
        if(nodeLeft > queryRight || nodeRight < queryLeft){
            return 0;
        }
        ll lastInLeft = (nodeLeft+nodeRight)/2;
        return query(2*node, nodeLeft, lastInLeft, queryLeft, queryRight) 
             + query(2*node+1, lastInLeft+1, nodeRight, queryLeft, queryRight); 
    }
};


int main(){

    ll n, q;
    cin >> n >> q;

    vector < ll > ara(n);

    for(auto &x: ara){
        cin >> x;
    }

    STree t(ara);

    while(q--){
        ll a, b;
        cin >> a >> b;
        a--;
        b--;
        cout << t.query(1, 0, n-1, a, b) << endl;    
    }


    return 0;
}