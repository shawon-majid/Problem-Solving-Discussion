//Bismillahir Rahman-ir Rahim
#include <bits/stdc++.h>
using namespace std;
#define MAX 100000
#define PI acos(-1)
#define debug(x) cout << '>' << #x << " : " << x << endl;
#define all(c) c.begin(), c.end()
/*
                                      AMR10C - Square Free Factorization                    
                                      ----------------------------------
        This is a classical number theory problem. It requires us to find the minimum number of factors
        which are square free number. Now, square free number is a number which can't be factorize using
        a square number. For example 24 is not a square free number because 24 = 8*3. Here 8 is not a square
        free number because it can be factorize as 8 = 4*2, here 4 is a square number and 8 is 24's divisor. 
        But 6 is a square free number because 6 = 2*3. Both 2 and 3 is a square free number and no other 
        combination is available for 6 which does not contains a square-free number. 

        Key idea: Prime factorize a number and notice that any number any prime factor p^a is divisible by
        p^2 if a > 1(i.e 2^5 is divisible by 2^2). So, no prime factors can have power more than 1 to form
        a factor. For example 24 = 2^3 * 3 = (8)*3 is not valid but = 2*2*6 is valid becuse all of the factors
        are square free. Notice that, if any power of prime factor is more than 1 than it must be grouped with
        other factors of power 1 or be alone. For example,
                                        
                                324000 = 2^5 * 3^4 * 5^3
                                       = (2*3*5)*(2*3*5)*(2*3*5)*(2*3)*2  is a valid combination.
                                       
        Hence, we see that the maximum power of prime factors (in this case 5) is the number of factors which
        are square free. Because 2 is grouped with other prime factors once or alone.

        Steps:
        1. Use method of prime factorization to find all the powers.
        2. Ans is the maximum of all powers
*/
int main()
{
    int T;
    cin >> T;
    while(T--) {
        int n, tot = 0;
        vector <int> kount; // here we will store the powers
        cin >> n;
        for(int i = 2; i*i <= n; i++){
            if(n % i == 0){ 
                int cnt = 0;
                while(n % i == 0) {
                    n /= i;
                    cnt++;
                }  
                kount.push_back(cnt);
            }
        }
        if(n > 1){ // n is prime
            kount.push_back(1);
        }
        cout << *max_element(all(kount)) << endl;

    }


    return 0;
}
