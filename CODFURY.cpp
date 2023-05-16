#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	
	int tc_num;
    scanf("%d", &tc_num);

    for (int tc=0; tc<tc_num; tc++){
        int planet, seen;
        scanf("%d %d", &planet, &seen);

        // fill in array and logic
        int arr[planet];
        int sum=0, close =0, ans =0, count = 0, final_count=0;
        for (int i=0; i<planet; i++){
            scanf("%d", &arr[i]);

            // slide open
            sum += arr[i];
            count++;

            // while over
            while (sum > seen){
                sum -= arr[close];
                close++;
                count--;
            }

            // find max
            if(final_count < count){
                final_count = count;
                ans = sum;
            }
            else if(final_count == count){
                ans = min(ans, sum);
            }
        }
        printf("%d %d\n", ans, final_count);

	return 0;
}