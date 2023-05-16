#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	
	int tc_num;
    scanf("%d", &tc_num);

    for(int tc=0; tc<tc_num; tc++){
        int num;
        scanf("%d", &num);
        pair <int, int> arr[1000010];
        for (int i=0; i<num; i++){
            scanf("%d %d", &arr[i].second, &arr[i].first); // put end time in the first
        }

        // sort the array (that's why it's called greedy)
        sort(arr, arr+num);

        int count=1, last_end=arr[0].first;
        for(int i=1; i<num; i++){
            if (arr[i].second >= last_end){
                count +=1;
                last_end = arr[i].first;
            }
        }
        printf("%d\n", count);
    }

	return 0;
}