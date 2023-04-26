#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

int main() {
	
	// declare
    int num, input;
    scanf("%d",&num);
    int arr[num], memo[num];

    // input numbers in arr
    for(int i=0; i<num; i++){
        scanf("%d", &input);
        arr[i] = input;
        memo[i] = 1;
    }

    // logic here
    for (int jim=1; jim<num; jim++){
        for(int me=0; me<jim; me++){
            if (arr[jim] > arr[me]){
                memo[jim] = max(memo[jim], memo[me]+1);
            }
        }
    }

    // longest icnreasing subsequence
    int max_num=1;
    for(int i=0; i <num; i++){
        max_num =  max(max_num, memo[i]);
    }
    printf("%d\n", max_num);

	return 0;
}