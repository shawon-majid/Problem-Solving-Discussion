//Bismillahir Rahman-ir Rahim
#include <bits/stdc++.h>
using namespace std;
#define debug(x) cout << '>' << #x << " : " << x << endl;
#define all(c) c.begin(), c.end()
#define F first
#define S second
typedef unsigned long long ull;
typedef long long ll;


string stringSum(string a, string b){
    string small, big, ans = "";
    (a.length() < b.length() ? (small = a, big = b) : (small = b, big =  a));

    reverse(all(big));
    reverse(all(small));

    int last = -1, carry = 0;

    for(int i = 0; i < small.size(); i++){
        last = i;
        int n1 = small[i] - '0';
        int n2 = big[i] - '0';
        int n3 = (n1+n2+carry) % 10;
        carry = (n1+n2+carry) / 10;
        char c = n3 + '0';
        ans += c;
    }  

    for(int i = last+1; i < big.size(); i++){
        int n1 = big[i] - '0';
        int n3 = (n1+carry) % 10;
        carry = (n1+carry) / 10;
        char c = n3 + '0';
        ans += c;
    }

    if(carry)ans += (char)(carry + '0');

    reverse(all(ans));

    return ans;
}


string stringProduct(string a, string b){
    string small, big, ans = "0";
    (a.length() < b.length() ? (small = a, big = b) : (small = b, big =  a));

    reverse(all(small));
    reverse(all(big));
    int carry = 0;

    for(int i = 0; i < small.size(); i++){
        string layer = "";
        for(int j = 0; j < big.size(); j++){
            int n1 = small[i] - '0';
            int n2 = big[j] - '0';
            int n3 = (n1*n2 + carry) % 10;
            carry = (n1*n2 + carry) / 10;
            char c = n3 + '0';
            layer += c;
        }
        if(carry) layer += (char)(carry + '0');

        reverse(all(layer));

        for(int k = 0; k < i; k++){
            layer += "0";
        }
        ans = stringSum(ans, layer);

        carry = 0;
    }

    return ans;


}


string ncr(int n, int r){
    vector <int> numerator, denominator;    
    vector <int> vis(1000);

    int numer, denom;

    int nMinusR = n - r;

    for(int i = n; i != max(nMinusR, r); i--){
        numerator.push_back(i);
    }
    
    for(int i = 2; i <= min(nMinusR, r); i++){
        int n = i;
        for(int j = 2; j*j <= n; j++){
            if(n % j == 0){
                while(n % j == 0){
                    n /= j; 
                    denominator.push_back(j);
                }
            }
        }
        if(n > 1){
            denominator.push_back(n);
        }
    }
    for(auto x: denominator){
        for(int i = 0; i < numerator.size(); i++){
            if(numerator[i] % x == 0){
                numerator[i] = numerator[i] / x;
                break;
            }
        }
    }
    string ans = "1";
    for(auto x: numerator){
        ans = stringProduct(ans, to_string(x));
    }

    return ans;
}


int main() {

    freopen("input.txt", "r" , stdin);
    freopen("output.txt", "w" , stdout);
    

    int n, m;
    while(1){
        cin >> n >> m;
        if(n == 0 and m == 0) break;

        cout << n << " things taken "<<m<<" at a time is "<<ncr(n, m)<<" exactly."<<endl;

    }


    return 0;
}