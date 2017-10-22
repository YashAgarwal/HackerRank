#include <cmath>
#include <cstdio>
#include <vector>
#include <map>
#include <iostream>
#include <algorithm>
using namespace std;

map<long, bool> isPrime;
bool isprime(long x){
    if(isPrime.find(x) == isPrime.end()){
        bool check = true;
        for(int i=2; i<=sqrt(x); i++){
            if(x%i==0){
                check = false;
                break;
            }
        }
        isPrime[x] = check; 
    }
    return isPrime[x];
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    
    long t,n;
    cin >> t;
    
    
    
    for(long i=0; i<t; i++){
        cin >> n;
        //find the largest prime factor of n
        long p_max;
        bool flag = true;
        for(long j=1; j<=sqrt(n); j++){
            if(n%j == 0){
                long q = n/j;
                if(isprime(q)){
                    cout << q << endl;
                    flag = false;
                    break;
                }
                if(isprime(j)){
                    p_max = j;
                }
            }                                    
        }
        if(flag){
            cout << p_max << endl;            
        }
    }
    
    return 0;
}

