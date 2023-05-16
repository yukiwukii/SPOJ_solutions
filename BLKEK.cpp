#include <iostream>
using namespace std;

int main() {
	
	int tc_num;
    scanf("%d", &tc_num);

    for(int tc=0; tc< tc_num; tc++){
        char word[20000];
        scanf("%s", &word);
        
        int k=0, e=0, count=0;
        for(int i=0; i<=strlen(word); i++){
            if (word[i] == 'K'){
                k += 1;
                count += e;
                
            }
            else if(word[i]=='E'){
                e += k;
            }

        }

        printf("%d\n", count);

    }

	return 0;
}