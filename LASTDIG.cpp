#include <iostream>
using namespace std;

long long exponential(int a, long long b){

    if (b==1){
        return a;
    }

    else if(b==0){
        return 1;
    }

    else{
        long long res = exponential(a, b/2);
        res = ((res%10) *(res%10))%10;  // prevent the number from getting bigger since we only care abt the last digit

        if (b%2!=0){
            res = ((res%10) * (a%10))%10;
        }
        return res;
    }
}

int main() {
	
	int tc_num;
    scanf("%d", &tc_num);

    for(int tc=0; tc<tc_num; tc++){
        int a;
        long long b;
        scanf("%d %lld", &a,&b);

        long long ans;
        ans = exponential(a,b);
        printf("%lld\n", ans);
    }

	return 0;
}