#include <iostream>
#include <string.h> //strlen
using namespace std;

int main() {
	char keyword[1500000];
    scanf("%s", &keyword);
    int len_kw = strlen(keyword);

    int q_num;
    scanf("%d", &q_num);

    for(int q=1; q<= q_num; q++){
        char x, y;
        scanf("%c %c", &x, &y);
        int a=-1, b=-1;
        for(int i=0; i<=len_kw; i++){
            if (keyword[i]== x && a== -1){
                a = i;
            }
        }

        for(int j= len_kw; j>=0; j--){
            if (keyword[j] == y && b== -1){
                b = j;
            }
        }

        if (b>a && b != -1 && a!= -1) {
            printf("YA\n");
        }
        else{
            printf("TIDAK\n");
        }
           
    }

	return 0;
}