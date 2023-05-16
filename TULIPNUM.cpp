// uses dp prefix sum

#include <iostream>
using namespace std;

int main() {
	
	int tc_num, num, q_num;
    scanf("%d", &tc_num);
    
    for(int tc=0; tc<tc_num; tc++){
        scanf("%d %d", &num, &q_num);
        int arr[num+1], input;
        for(int i=1; i<=num; i++){
            scanf("%d", &input);
            arr[i] = input;
        }

        // create memo
        int memo[num+1], latest=0, count=0;;
        for(int i=1; i<=num; i++){
            if(arr[i]>latest){
                latest = arr[i];
                count++;
            }
            memo[i] = count;
        }

        printf("Case %d:\n", tc+1);
        
        // complexity below is O(q)
        int start, end, answer;
        for(int q=0; q<q_num; q++){
            scanf("%d %d", &start, &end);
            // don't forget the +1 since the first number is unique!
            answer = memo[end]-memo[start]+1;
            printf("%d\n", answer);
        }
    }
	return 0;
}