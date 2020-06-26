//Bismillahir Rahman-ir Rahim
#include <bits/stdc++.h>
using namespace std;
#define MAX 100000
#define PI acos(-1)
#define debug(x) cout << '>' << #x << " : " << x << endl;
#define all(c) c.begin(), c.end()
#define pb push_back
typedef unsigned long long ull;
typedef long long ll;
typedef vector< int > vi;

/*
                                Conformity
                                ----------

    This is an classical STL problem which can be solved by using map.

    Key idea: We will use a map where key values are sorted vectors of each input
              and mapped value is the occerence of those vectors. Highest occurence
              will be the answer. However if there are multiple highest occurence each
              of the must also be added to the answer. 
    
    Steps:
    1. use map <vector < int >, int >
    2. keep track by mapped value
    3. check how many key value is maximum with kount
    4. ans = kount * maximum


*/
int main()
{

    int n;
    while(1) {
        cin >> n;
        if(n == 0) break;

        map < vector < int >, int > M;
        vector < int > temp(5);

        for(int i = 0; i < n; i++){
            for(int j = 0; j < 5; j++){
                cin >> temp[j];
            }

            sort(all(temp));

            M[temp]++;
        }

        int maximum = 0;
        for(auto x: M){
            if(x.second > maximum) maximum = x.second;
        }
        int kount = 0;
        for(auto x: M){
            if(x.second == maximum) kount++;
        }

        cout << maximum*kount << endl;
 

    }

    return 0;
}
