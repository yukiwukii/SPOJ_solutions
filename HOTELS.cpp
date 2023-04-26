#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	
	int hotels, budget, input;
    scanf("%d %d", &hotels, &budget);
    int arr[hotels];
    int answer=0, total=0;

    for (int i=0; i<hotels; i++){
        scanf("%d",&input); 
        arr[i] = input;
    }

    for(int i=0; i<hotels; i++){
        total += arr[i];
        if(total>budget){
            for(int j=0; j<hotels; j++){
                total -= arr[j];
                if (total <=budget){
                    break;
                }
            }
        }
        answer = max(total,answer);
    }
    printf("%d", answer);

	return 0;
}