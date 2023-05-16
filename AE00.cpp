#include <iostream>
#include <cmath>
using namespace std;

int main() {
	
    int num;
    scanf("%d", &num);

    int row;
    row = floor(sqrt(num));
	
    int count = 0; 
    for(int i=1; i<=row; i++){
        int product = 1;
        int column = i;
        while (product <= num){
            product = i * column;
            column++;
            count++;
        }
        count--;
    }
    printf("%d\n", count);
	return 0;
}