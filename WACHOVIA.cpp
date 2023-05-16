// KNAPSACK PROBLEM
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

int main() {
    int tc_num, max_weight, num_bags;
    scanf("%d", &tc_num);

    for(int tc=1; tc<=tc_num; tc++){
        
        // insert details of each bag
        scanf("%d %d", &max_weight, &num_bags);
        int arr[num_bags+1][3];
        memset(arr, 0, sizeof(arr));
        for(int i=1; i<=num_bags; i++){
            scanf("%d %d", &arr[i][1], &arr[i][2]);
        }

        // make the memo
        int memo[num_bags+1][max_weight+1];
        memset(memo, 0, sizeof(memo));

        // KNAPSACK algo
        int buy, skip, bag_value, rem_weight, bag_weight;
        for(int r=1; r<=num_bags; r++){
            for(int c=1; c<= max_weight; c++){
                skip = memo[r-1][c];
                bag_weight = arr[r][1];

                // if bag weight is greater than remaining weight...
                if (c< bag_weight){
                    memo[r][c] = skip;
                }
                else{
                    bag_value = arr[r][2];
                    rem_weight = c - bag_weight;
                    buy = bag_value + memo[r-1][rem_weight];
                    memo[r][c] = max(skip, buy);
                }

            }
        }

        // output
        printf("Hey stupid robber, you can get %d.\n", memo[num_bags][max_weight]);

    }
	

	return 0;
}
