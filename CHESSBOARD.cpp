#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

int main() {
	
    int row, column;
    scanf("%d", &row);
    column = row;

    int input, arr[row+1][column+1];
    int memo[row+1][column+1];
    memset(memo, 0, sizeof(memo));
    memset(arr, 0, sizeof(arr));

    for(int i=1; i<=row; i++){
        for(int j=1; j<=column; j++){
            scanf("%d", &input);

            // positive when white
            if ((i+j)%2 ==0){
                arr[i][j] = input;
            }
            // negative when black
            else{
                arr[i][j] = -input;
            }

            // fill in memo here using prefix algorithm
            memo[i][j] = arr[i][j]+memo[i-1][j]+memo[i][j-1]-memo[i-1][j-1];
        }
    }

    int q_num, r1, c1, r2, c2;
    scanf("%d", &q_num);
    
    int answer;
    for(int q=1; q<=q_num; q++){
        scanf("%d %d %d %d", &r1, &c1, &r2, &c2);
        answer = abs(memo[r2][c2] - memo[r1-1][c2]- memo[r2][c1-1]+memo[r1-1][c1-1]);
        printf("%d\n", answer);
    }
	return 0;
}