#include <iostream>
#include <cstring> //memset
#include <algorithm> // max mins abs
using namespace std;

int main() {
	
	// declare variables
    int tc_number, row;
    scanf("%d", &tc_number);
    

    for(int tc=0; tc<tc_number; tc++){
        scanf("%d", &row);
        int column = 3;
        int arr[row][column], memo[row][column];

        // set memo to all 0
        memset(memo, 0, sizeof(memo));

        // input number to arr
        int input_num;
        for(int i=0; i<row; i++){
            for(int j=0; j<column; j++){
                scanf("%d", &input_num);
                arr[i][j] = input_num;
            }
        }

        // copy first line to memo
        for(int j=0; j<column; j++){
            memo[0][j] = arr[0][j];
        }

        // start filling in numbers in memo
        for(int b=1; b <row; b++){
            for (int k=0; k < column; k++){
                if (k == 0){
                    memo[b][k] = arr[b][k] + min(memo[b-1][k+1],memo[b-1][k+2]);
                }
                else if (k == column-1){
                    memo[b][k] = arr[b][k] + min(memo[b-1][k-1], memo[b-1][k-2]);
                }
                else{
                    memo[b][k] = arr[b][k] + min(memo[b-1][k-1],memo[b-1][k+1]);
                }

            }
        }

        // find highest number in the last row
        int min_num=1000000;
        for(int i=0; i < column; i++){
            min_num =  min(min_num, memo[row-1][i]);
        }
        printf("%d\n", min_num);
    }
	return 0;
}