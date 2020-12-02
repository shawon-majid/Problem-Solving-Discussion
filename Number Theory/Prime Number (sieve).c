#include <stdio.h>
#include <math.h>

int mark[1000000];
// 0 for prime
// 1 for not prime

void sieve(int n){
    mark[0] = mark[1] = 1;
    for(int i = 2; i*i <= n; i++){
        if(mark[i] == 0){
            for(int j = i+i; j <= n; j += i){
                mark[j] = 1;
            }
        }
    }
}

int main(){
    int n;
    scanf("%d", &n);
    sieve(n);
    for(int i = 1; i <= n; i++){
        if(mark[i] == 0){
            printf("%d\n", i);
        }
    }
}
