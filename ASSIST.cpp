#include <iostream>
#include <cstring>
// #include <bits/stdc++.h>
using namespace std;
long long prime[35005];
bool bo[35005];

void sieve_of_eratosthenes(){
    memset(bo, true, sizeof(bo));

    for(int a=2;a<=35005; a++){
        if (bo[a] == false){
            continue;
        }

        else{  
            int count=0, b=a+1;
            while (b<=35005){
                if(bo[b]== true){
                    count++;
                }
                if (count == a){
                    bo[b] = false;
                    count = 0;
                }
                b++;
            }
        }
    }

    prime[1] = 2;
    int j =2;
    for(int i=3; i<=35005; i+=2){
        if (bo[i] == true){
            prime[j] = i;
            j++;
        }
    }

    return;
}

int main() {
	
    sieve_of_eratosthenes();
    while(true){
        int input;
        scanf("%d", &input);
        if(input == 0){
            break;
        }
        else{
            printf("%lld\n", prime[input]);
        }
    }
	return 0;
}