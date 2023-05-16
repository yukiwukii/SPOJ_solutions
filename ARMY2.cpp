#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	
    int tc_num;
    scanf("%d", &tc_num);
    
    for(int tc=0; tc<tc_num; tc++){
        int ng, nm;
        scanf("%d %d", &ng, &nm);
        
        // create arrays
        int arrg[ng], arrm[nm], max_g=0, max_m=0;
        for(int i=0; i<ng; i++){
            scanf("%d", &arrg[i]);
            max_g = max(max_g,arrg[i]);
        }

        for(int i=0; i<nm; i++){
            scanf("%d", &arrm[i]);
            max_m = max(max_m, arrm[i]);
        }

        if (max_g >= max_m){
            printf("Godzilla\n");
        }
        else{
            printf("MechaGodzilla\n");
        }
    }
	return 0;
}