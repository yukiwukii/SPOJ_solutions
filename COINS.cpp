#include <iostream>
using namespace std;
long long memo[10000005]; //10^7;

long long conversion(long long coin){ // there are 10^9 coin

    // divide and conquer since there are too many coins
    if (coin>10000000){
        return conversion(coin/2) + conversion(coin/3) + conversion(coin/4);
    }

    // base cases
    if (coin >=  coin/2 +coin/3 +coin/4){
        return coin;
    }
    
    //memoisation
    if (memo[coin] !=0){
        return memo[coin];
    }

    return memo[coin] = conversion(coin/2) + conversion(coin/3) + conversion(coin/4);
}

int main() {
	
    long long coin;
	while (scanf("%lld",&coin)!=EOF){
        long long ans = conversion(coin);
        printf("%lld\n", ans);
    }
	return 0;
}