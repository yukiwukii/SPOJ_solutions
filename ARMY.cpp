#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

int main() {
	
    int tc_num;
    scanf("%d", &tc_num);
    
    for(int tc=0; tc<tc_num; tc++){
        int ng, nm;
        scanf("%d %d", &ng, &nm);
        
        // create arrays
        int arrg[ng], arrm[nm];
        for(int i=0; i<ng; i++){
            scanf("%d", &arrg[i]);
        }

        for(int i=0; i<nm; i++){
            scanf("%d", &arrm[i]);
        }

        // logic
        while(true){
            int sumg=0, summ=0;
            // for godzilla
            int min_g=1000000, index_g;
            for(int i=0; i<ng; i++){
                if ((min_g > arrg[i]) && (arrg[i]!=0)){
                    min_g = arrg[i];
                    index_g = i;
                }
                sumg += arrg[i];
            }

            // for mechazilla
            int min_m=1000000, index_m;
            for(int j=0; j<nm; j++){
                if ((min_m > arrm[j]) && (arrm[j]!=0)){
                    min_m = arrm[j];
                    index_m = j;
                }
                summ += arrm[j];
            }

            if (summ == 0){
                printf("Godzilla\n");
                break;
            }
            else if(sumg == 0){
                printf("MechaGodzilla\n");
                break;
            }

            else if (min_g < min_m){
                arrg[index_g] = 0;
            }
            else{
                arrm[index_m] = 0;
            }
        }
    }

	return 0;
}