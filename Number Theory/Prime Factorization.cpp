//Bismillahir Rahman-ir Rahim
#include <bits/stdc++.h>
using namespace std;
#define MAX 1000000
#define PI acos(-1)

/*
                                        Prime Factorization
                                        -------------------
        Primeb Factorization is one of the most important concept in number theory. So in simple
        language, prime factorization means any number n can be factorized by using prime numbers
        only. which means,
                                 n = (p1^a1)*(p2^a2)........(pk^ak)
        where pi is a prime number and ai is the power of that prime number.

        For example, 12 = (2^2)*(3^1), 28 = (2^2)*(7^1), 13 = (13^1)

        Here we can see that 13 which is a prime number has only one prime divisor and that's itself!
        and thats obvious.

        Now, for a compound number the prime factors must be inside sqrt(n). Why? Think of divisors of
        a compound number and figure it out yourself!

        Okay, so for any number n, there could only be 1 prime divisor (and thats when n is prime). 

        Now, lets think about how we can find the prime factors. Notice that, the smallest number by 
        which n can be divided is a prime number(of course without 1). Now if we keep dividing n untill
        it becomes undivisible by that prime number and also we would keep count of times we divided the
        number. Then we will proceed to the next prime number. Notice that here also, when n is again 
        divisible by smallest number thats must also be prime according to the previous logic. So in 
        that process we will find the prime numbers and their powers to find the prime factorization of
        a number.

        Let's code prime factorization using above mentioned facts.

*/


int main()
{
    
    int n, k = 1, cnt = 0; 
    cin >> n;

    for(int i = 2; i*i <= n; i++){
        if(n % i == 0){
            cnt = 0;
            while(n % i == 0) {
                n /= i;
                cnt++;
            }
            
            if((i+1)*(i+1) > n && n == 1) cout << i << "^" << cnt << endl;
            else cout << i <<"^"<< cnt << " * ";
        }
    }
    if(n > 1){ // which means n is a prime number
        cout << n << "^" << 1 << endl;
    }
    
    return 0;
}
