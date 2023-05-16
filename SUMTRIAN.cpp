
// CLASSIC DP PROBLEM
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

int main() {
	
    int tc_num;
    scanf("%d", &tc_num);
    for(int tc=1; tc <=tc_num; tc++){
        int row;
        scanf("%d", &row);

        // insert nums to array
        int arr[row+1][row+1], input;
        memset(arr, 0, sizeof(arr));
        for(int r=1; r <=row; r++){
            for(int c=1; c <=r; c++){
                scanf("%d", &input);
                arr[r][c] = input;
            }
        }
        

        // create memo
        int memo[row+1][row+1];
        memset(memo, 0, sizeof(memo));
        
        // copy first line into memo
        memo[1][1] = arr[1][1];

        // start filling the rest of the memo
        int above_sum, diagonal_sum;
        for(int r=2; r<=row; r++){
            for(int c=1; c <=r; c++){
                above_sum = arr[r][c] + memo[r-1][c];
                diagonal_sum = arr[r][c] + memo[r-1][c-1];
                memo[r][c] = max(above_sum,diagonal_sum);
            }
        }

        // find the highest number in the last row
        int max_num=0;
        for(int i=1; i<=row; i++){
            max_num = max(max_num, memo[row][i]);
        }
        printf("%d\n", max_num);
    }
	return 0;
}