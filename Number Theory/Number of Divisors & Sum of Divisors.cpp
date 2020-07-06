//Bismillahir Rahman-ir Rahim
#include <bits/stdc++.h>
using namespace std;
#define MAX 1000000
#define PI acos(-1)

/*
                                        Number of Divisors & Sum of Divisors
                                        ------------------------------------
        If n = (p1^a1)*(p2^a2)....(pk^ak)
        Then the number of divisor NOD(n) = (a1+1)*(a2+1)...(ak+1). Why?
        consider any divisor d. d could be prime ar non prime number.
        if d is a prime number then it's a prime divisor, and if d is 
        non prime number than it's a another combinations of prime number
        so total combinations of prime number is the number of divisor.
        for example, divisors of 6 are:
                                1. 1 = 2^0 * 3^0
                                2. 2 = 2^1 * 3^0
                                3. 3 = 2^0 * 3^1
                                4. 6 = 2^1 * 3^1 
        So we have ai+1 choice for any prime number. So, 
                        
                        NOD(n) = (a1+1)*(a2+1)...(ak+1)
        
        Now lets calculate sum of divisors
        SOD(n) = (p1^(a1+1) - 1)/(p1 - 1)*(p2^(a2+1) - 1)/(p2 - 1)...(pk^(ak+1) - 1)/(pk - 1). Why?
        Because we get that formula by simply adding all the combinations:
                       
                       SOD(n) = (2^0 * 3^0) + (2^1 * 3^0) + (2^0 * 3^1) + (2^1 * 3^1)
*/

int NOD(int n){
    int cnt = 0;
    int divisor = 1;

    for(int i = 2; i*i <= n; i++){
        if(n % i == 0){
            cnt = 1;
            while(n % i == 0) {
                n /= i;
                cnt++;
            }
            divisor *= cnt;
        }
    }
    if(n > 1){ // which means n is a prime number
        divisor *= 2;
    }
    return divisor; 
}

int SOD(int n){
    int cnt, sum = 1;
    for(int i = 2; i*i <= n; i++){
        if(n % i == 0){
            cnt = 1;
            while(n % i == 0) {
                n /= i;
                cnt++;
            }
            int x = pow(i, cnt)-1, y = i-1;
            sum *= (x/y);
        }
    }
    if(n > 1){ // which means n is a prime number
        int x = pow(n, 2)-1, y = n-1;
        sum *= (x/y);
    }
    return sum;
}



int main()
{
    int n;
    cin >> n;

    cout << NOD(n) << endl;
    cout << SOD(n) << endl;
    
    return 0;
}
