#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

int main() {

	while (true){

        int cash, party;
        scanf("%d %d", &cash, &party);
        if(cash ==0 && party==0){
            break;
        }

        int arr[party+1][3], memo[party+1][cash+1];
        memset(memo, 0, sizeof(memo));

        int input_price, input_value;
        for(int i=1; i<=party; i++){
            scanf("%d %d", &input_price, &input_value);
            arr[i][1] = input_price;
            arr[i][2] = input_value;
        }

        // KNAPSACK algorithm
        int skip, buy, value, rem_cash;
        for(int row=1; row<=party; row++){
            for(int column=0; column<= cash; column++){
                skip = memo[row-1][column];

                if (column<arr[row][1]){
                    memo[row][column] = skip;
                }
                else{
                    value = arr[row][2];
                    rem_cash = column - arr[row][1];
                    buy =value+memo[row-1][rem_cash];
                    memo[row][column] = max(skip, buy);
                }

            }
        }

        int sum=0;
        for(int col=0; col<= cash; col++){
            // find the cheapest cash with the max party value
            if(memo[party][col] == memo[party][cash]){
                sum = col;
                break;
            }
        }

        printf("%d %d\n", sum, memo[party][cash]);
    }
	return 0;
}