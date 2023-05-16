#include <iostream>
using namespace std;
int arr[1005];

int summation(int start){
    if (start==1){
        return arr[1];
    }
    return arr[start] + summation(start-1);
}

int main() {
	
	int tc_num;
    scanf("%d", &tc_num);

    for(int tc=1; tc<=tc_num; tc++){
        int num;
        scanf("%d", &num);

        for(int i=1; i<=num; i++){
            scanf("%d", &arr[i]);
        }

        int answer;
        answer = summation(num);
        printf("Case %d: %d\n", tc, answer);

    }
	return 0;
}