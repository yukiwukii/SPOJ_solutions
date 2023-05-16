// when dealing with large numbers, you have to be very aware of the mods
// everything and anything must be modded

#include <iostream>
#include<stdio.h>
#include<math.h>
#include <cmath>
#include<string.h>
#include<algorithm>
using namespace std;
long long mod;
long long mod2 = 1000000007;

long long f(long long base, long long pangkat) {
	
	if(pangkat ==1){
        return base%mod2;
    }

    else{
        long long hasil = f(base,pangkat/2);
        hasil = (hasil%mod2 * hasil%mod2)%mod2;

        if(pangkat%2 !=0){
            hasil = (hasil%mod2 *base%mod2)%mod2;
        }
        return hasil%mod2;
    }
}

long long count(long long n){ // n will be inputted with r  
    long long denum_inverse = f(2, mod2-2)%mod2;
    // sub in mod-1 to n  in n(n+1)
    long long one_rotation_num = (mod%mod2 *(mod%mod2-1%mod2)%mod2)%mod2;
    long long one_rotation= (one_rotation_num * denum_inverse)%mod2;
    // above is the formula of Sn%mod2 for one rotation

    long long num_of_rotation = n/mod;
    long long remain = n%mod;

    // sub in remain to n in n(n+1)
    long long remain_num = (remain%mod2 * (remain%mod2 +1))%mod2;
    long long remain_sum = (remain_num * denum_inverse)%mod2;

    return ((one_rotation * num_of_rotation%mod2) + remain_sum)%mod2;
}


int main() {
    
    long long l,r, include, exclude;
    scanf("%lld %lld %lld", &l, &r, &mod);

    include = count(r);
    exclude = count(l-1);

    // print include - exclude %mod2
    long long ans;
    ans = include%mod2 - exclude%mod2;
    ans %= mod2;
    if (ans<0){
        ans = (ans + mod2)%mod2;
    }
    printf("%lld\n", ans);
}