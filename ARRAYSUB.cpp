// SLIDING WINDOW PROBLEM
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int num;
	scanf("%d", &num);
	int arr[num];

	for(int i=0; i<num; i++){
		scanf("%d", &arr[i]);
	}
	
	int cont;
	scanf("%d", &cont);

	// logic starts here
	for(int i=0; i<num-cont+1; i++){
		int count=0, max_num=0;
		while (count<cont){
			max_num = max(max_num, arr[i+count]);
			count++;
		}
		printf("%d ", max_num);
	}

	return 0;
}

// probably rather inefficient. might be better if we can use proper DP. complexity is O(nk)