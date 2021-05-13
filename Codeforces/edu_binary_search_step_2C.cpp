//Bismillahir Rahman-ir Rahim
#include <bits/stdc++.h>
using namespace std;
#define debug(x) cout << '>' << #x << " : " << x << endl;
#define all(c) c.begin(), c.end()
typedef unsigned long long ull;
typedef long long ll;

struct custom_compare final
{
    bool operator() (const pair<int,int>& left, const pair<int, int>& right) const
    {
        return left.second < right.second;
    }
};

int main() {

    freopen("input.txt", "r" , stdin);
    freopen("output.txt", "w" , stdout);

    int n, k;
    cin >> n >> k;
    multiset <pair <int, int>, custom_compare > ms;
    for(int i = 0; i < n; i++){
        pair <int, int> x;
        cin >> x.first >> x.second;
        ms.insert(x);
    }
    

    return 0;
}