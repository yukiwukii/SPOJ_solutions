#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	
    int tc_num;
    scanf("%d", &tc_num);

    for (int tc=1; tc<= tc_num; tc++){
        int tiles, max_strawb;
        scanf("%d %d", &tiles, &max_strawb);

        // insert arr
        int arr[tiles+5];
        for (int i=1; i<=tiles; i++){
            scanf("%d", &arr[i]);
        }

        // knapsack algorithm
        int strawb_num;
        long long memo[tiles+5][max_strawb+5];

        // set everything to 1M
        for (int i=1; i<=tiles; i++){
            for(int j=0; j<=max_strawb; j++){
                memo[i][j] = 1000000000;
            }
        }

		memo[1][0] = 0;
        for (int i=1; i<=tiles; i++){
            for(int j=0; j<=max_strawb; j++){
                strawb_num = arr[i];
                
                memo[i+1][j] = min(memo[i][j]+1, memo[i+1][j]); // skip
                
                if ( i+strawb_num <= tiles && j+1 <=max_strawb)
                	memo[i+strawb_num][j+1] = min(memo[i][j], memo[i+strawb_num][j+1]); // buy
            }
        }
		
        // output
        long long ans=1000000000;
        for(int i=0; i<=max_strawb; i++){
            ans = min(ans, memo[tiles][i]);
        }
        printf("Scenario #%d\n", tc);
        
        if (ans != tiles-1){
            printf("Teresa will skip %d strawberries\n", ans);
        }
        else{
            printf("Teresa will skip all the strawberries\n");
        }
    }	

	return 0;
}