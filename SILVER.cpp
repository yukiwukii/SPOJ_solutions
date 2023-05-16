#include <iostream>
using namespace std;

int main() {
	
	int n;
    while(true){
        scanf("%d", &n);
        if (n==0){
            break;
        }

        else{
            int count=0;
            while (n!=1){
                n = n/2;
                count++;
            }
            printf("%d\n", count);
        }
    }

	return 0;
}