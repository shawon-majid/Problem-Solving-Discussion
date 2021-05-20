#include <bits/stdc++.h>
using namespace std;
#define debug(x) cout << '>' << #x << " : " << x << endl;
#define all(c) c.begin(), c.end()
#define F first
#define S second
typedef unsigned long long ull;
typedef long long ll;


int main() {

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r" , stdin);
    freopen("output.txt", "w" , stdout);
#endif

    int n, m, k, t;
    cin >> n >> m >> k >> t;
    vector <int> wasted;
    for(int i = 0; i < k; i++){
        int r, c;
        cin >> r >> c;
        wasted.push_back(m*(r-1)+c);
    }  
    sort(all(wasted)); 
    while(t--){
        int r, c;
        cin >> r >> c;
        int toFind = m*(r-1) + c;

        int ind = lower_bound(all(wasted), toFind) - wasted.begin();
        if(ind != wasted.size() and wasted[ind] == toFind){
            cout << "Waste" << endl;
        }
        else{
            int passedWasted = ind;
            toFind = toFind - passedWasted;
            if(toFind % 3 == 1){
                cout << "Carrots" << endl;
            }
            else if(toFind % 3 == 2){
                cout << "Kiwis" << endl;
            }
            else{
                cout << "Grapes" << endl;
            }
        }
    }

}