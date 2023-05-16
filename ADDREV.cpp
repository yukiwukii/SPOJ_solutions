#include <iostream>
using namespace std;

int ReverseNum(int num){
    int reversed_num = 0;

    while (num >0){
        // reversed_num *10 add 1 more digit
        // num%10 returns the last digit in num
        reversed_num = (reversed_num*10) + (num%10);
        // num/10 deletes the last digit of in num
        num = num /10;
    }

    return reversed_num;
}

int main() {
	
    int tc_num;
    scanf("%d", &tc_num);

    for(int tc=0; tc<tc_num; tc++){
        int one,two;
        scanf("%d %d", &one,&two);

        one = ReverseNum(one);
        two = ReverseNum(two);

        int sum = one+two;
        sum = ReverseNum(sum);
        printf("%d\n", sum);

    }

	return 0;
}