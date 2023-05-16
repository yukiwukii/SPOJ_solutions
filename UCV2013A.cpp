#include <iostream>
using namespace std;
long long mod = 1000000007;

long long modex(long long n, long long l){
    // base cases
    if (l==1){
        return n%mod;
    }

    else{
        long long res = modex(n, l/2);
        res = (res%mod * res%mod)%mod;

        if (l%2 != 0){
            res = (res%mod * n%mod)%mod;
        }
        return res;
    }
}

long long summation(long long n, long long l){

    if (l==0){
        return 0;
    }

    return ((modex(n, l)%mod) + (summation(n,l-1)%mod))%mod;
}

int main() {
	
	while(true){
        long long n, l;
        scanf("%lld %lld", &n, &l);

        if (n==0 && l==0){
            break;
        }

        long long ans;
        ans = summation(n,l);
        printf("%lld\n", ans);
    }

	return 0;
}