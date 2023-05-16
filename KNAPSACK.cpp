#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

int main() {
	
	int cash, item;
    scanf("%d %d", &cash, &item);
    int arr[item+1][3], memo[item+1][cash+1];
    memset(memo, 0, sizeof(memo));

    int input_price, input_value;
    for(int i=1; i<=item; i++){
        scanf("%d %d", &input_price, &input_value);
        arr[i][1] = input_price;
        arr[i][2] = input_value;
    }

    int skip, buy, value, rem_cash;
    for(int row=1; row<=item; row++){
        for(int column=0; column<= cash; column++){
            skip = memo[row-1][column];

            if (column<arr[row][1]){
                memo[row][column] = skip;
            }
            else{
                value = arr[row][2];
                rem_cash = column - arr[row][1];
                buy = max(skip, value+memo[row-1][rem_cash]);
                memo[row][column] = buy;
            }

        }
    }

    printf("%d\n", memo[item][cash]);

	return 0;
}