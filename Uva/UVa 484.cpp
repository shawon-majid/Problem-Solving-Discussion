//Bismillahir Rahman-ir Rahim
#include <bits/stdc++.h>
using namespace std;
#define MAX 100000
#define PI acos(-1)
#define debug(x) cout << '>' << #x << " : " << x << endl;
#define all(c) c.begin(), c.end()
#define F first
#define S second
#define pb push_back
#define mp make_pair
typedef unsigned long long ull;
typedef long long ll;
typedef vector< int > vi;

/*
                                The Department of Redundancy Department
                                ---------------------------------------

    This is an easy problem which can be solved easily by map but have to manipulate the map order

    Key idea: We will use a map to get frequency of occurence. then we will order it by taking a vector which is ordered by
    first occurance.
    
    Steps:
    1. use map < int, int >
    2. keep track of frequency by mapped value
    3. Also use a vector to keep track the first occurence
    4. print the mapped value in the order of vector


*/
int main()
{
    int n;
    map <int, int > M;
    vector < int > v;
    while(cin >> n) {
        auto it = find(all(v), n);
        if(it == v.end()){
            v.push_back(n);
        }

        M[n]++;
    }

    for(auto x: v){
        cout << x << ' ' <<M[x] << endl; 
    }    
     

    return 0;

}
