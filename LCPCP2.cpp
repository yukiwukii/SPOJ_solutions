#include <iostream>
// # define LL long long
using namespace std;
long long m;

long long modex(long long b, long long e){

    // base cases
    if (e==0){
        return 1;
    }

    else if (e==1){
        return b %m;
    }

    else{
        long long res = modex(b,e/2);
        res = (res%m *res%m)%m;

        if (e%2 != 0){
            res = (res%m * b%m)%m;  // special character of mod
        }

        return res;
    }
}

int main() {
	
	int tc_num;
    scanf("%d", &tc_num);

    for (int tc =1; tc<= tc_num; tc++){
        long long b, e;
        scanf("%lld %lld %lld", &b, &e, &m);

        long long ans;
        ans = modex(b,e);
        printf("%d. %lld\n", tc, ans);
    }
	return 0;
}