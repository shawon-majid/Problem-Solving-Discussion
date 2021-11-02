//Bismillahir Rahman-ir Rahim
#include <bits/stdc++.h>
using namespace std;
#define debug(x) cout << '>' << #x << " : " << x << endl;
#define all(c) c.begin(), c.end()
#define F first
#define S second
typedef unsigned long long ull;
typedef long long ll;



class Solution{
public:
    map <pair <int, int>, bool > m;
    double goldenRatio = (1 + sqrt(5))/2;

    Solution(){

      for(int i = 0; i <= 1e6+1; i++){
        int a = floor(i*goldenRatio);
        double sq = goldenRatio*goldenRatio;
        int b = floor(i*sq);
        m[{a,b}] = 1;
      }
    }
    bool solve(int a, int b){
      return !m[{min(a, b), max(a, b)}];      
    }
};


int main(){

    Solution ob;

    // cout << ob.goldenRatio << endl;

    int t, a, b;
    cin >> t;
    while(t--){
        cin >> a >> b;
        bool dolly = ob.solve(a, b);
        puts(dolly?"Dolly":"Bunty");

    }


    return 0;
}
