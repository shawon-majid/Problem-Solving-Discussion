//Bismillahir Rahman-ir Rahim
#include <bits/stdc++.h>
using namespace std;
#define MAX 1000000
#define PI acos(-1)

/*
                                    Euler's Totient Function
                                    ------------------------
        Euler's Totient Function gives us the number of co-primes between 1 to n.
        phi(n) = x means: x is the number of co-primes between 1 to n.
        [a and b are called co-primes if gcd(a, b) = 1]

        ex: phi(12) = 4; here (1, 5, 7, 11) are the co-primes of 12 from 1 - 12.
        
        Now we can find 3 general case.
        1. If a number is prime than all the numbers before that number is it's co-prime. for example,
        phi(7) = 6; here [1, 2, 3, 4, 5, 6] are the co-primes of 7.
        So, phi(p) = p - 1; where p is any prime number.
        
        2. If a number is power of a prime number (i.e n = p^k where k >= 1), then this number can only be co-prime with the numbers that is not 
        divisible by that prime number. (try to find out why).
        Now, there are n/p numbers which can be divided by p from 1 to n.
          n/p = p^k/p = p^k-1;
          So, phi(n) = p^k - p^(k-1) (where n = p^k and p is prime and k >= 1)
         
        3. if a and b are co-primes then, phi(a*b) = phi(a)*phi(b). Why this is true? For the explanation we need to understand Chinese remainder theorem.
           And it will be covered later.
           
 
        By combining these 3 properties, Euler found a formula for finding totient function. which is:
                    phi(n) = phi(p1^a1)*phi(p2^a2)*......*phi(pk^ak)
                           = p1^a1 - p1^(a1 - 1)*p2^a2 - p2^(a2 - 1)*....*pk^ak - pk^(ak - 1)  
                    phi(n) = n*(1 - 1/p1)*(1 - 1/p2)....(1 - 1/pk)

        So, we will see two method of finding phi of a number.
        First one is for a single number. In that case, we will use the idea of prime factorization to
        find the prime numbers.

        And second method is for finding all the value of phi between 1 to n. In that case, we will use
        a sieve-like method to store this number. 
*/

int phi(int n)
{
    int ret = n;
    for(int i = 2; i*i <= n; i++){
        if(n % i == 0){
            ret -= (ret/i);  // it simply means ret*(1 - 1/i)
            while(n % i == 0) {
                n /= i;
            }
        }
    }
    if(n > 1){ // which means n is a prime number
        ret -= (ret/n); 
    }
    return ret;
}

// Now lets write the second function

int PHI[100000], marked[100000]; // for identifying prime
// for storing  // 0 -> prime
// the values   // 1 -> not prime

void phisieve(int n){

    for(int i = 1; i <= n; i++) PHI[i] = i;

    marked[1] = 1;

    for(int i = 2; i <= n; i++){
        if(!marked[i]){ // i is prime
            for(int j = i; j <= n; j += i){ // we start from that prime to the all of the compound numbers that this prime will divide.
                marked[j] = 1;
                PHI[j] -= PHI[j]/i;
            }
        }
    }
}


int main()
{
    int n;
    cin >> n;
    
    cout <<"Phi("<<n<<") = " << phi(n) << endl;
    
    int x;
    cin >> x;
    phisieve(x);
    for(int i = 1; i <= x; i++){
        cout <<"Phi("<<i<<") = " << PHI[i] << endl;
    }
    
    return 0;
}
