#include <iostream>
using namespace std;

int main() {
	
	// declare variables
    int row, column, no_of_commands;
    cin >> row >> column;
    int up_down_temp_arr[column];
    int right_left_temp_array[row];

    // generate the initial data
    int arr[row][column];
    int start = 1;
    for (int i =0; i < row ; i++){
        for (int j=0; j < column; j++){
            arr[i][j] = start++;
        }
    }

    // print initial data
    //refactoring = menyederhanakan code
    int largest = row*column;
    for (int i=0; i< row; i++){
        for(int j = 0; j<column; j++){
            int num = arr[i][j];
            if ( largest > 999 && num < 1000 ) // largest 4 digit, num 3 digit
            	printf("0");
            if ( largest > 99 && num < 100 ) // largest 3 digit, num 2 digit
            	printf("0");
            if ( largest > 9 && num < 10 ) // largest 2 digit, num 1 digit
            	printf("0");
				
			printf("%d", num);
            if(j< column-1)
				printf(" ");
        }
       printf("\n");
    }

    // input command number
    cin >> no_of_commands;
    string command;
    
    // execute commands
    for(int i=0; i<no_of_commands; i++){
        cin >> command;

        if (command== "up"){
            // up command
            for(int i=0; i<column; i++){
                up_down_temp_arr[i] = arr[0][i];
            }
            for (int j=1; j<row; j++){
                for (int i =0; i < column; i++){
                    arr[j-1][i] = arr[j][i];
                }
            }
            for(int i=0; i<column; i++){
                arr[row-1][i] = up_down_temp_arr[i];
            }
        }

        else if(command == "down"){
            // down
            for(int i=0; i<column; i++){
                up_down_temp_arr[i] = arr[row-1][i];
            }
            for (int j=row-2; j>=0; j--){
                for (int i =0; i < column; i++){
                    arr[j+1][i] = arr[j][i];
                }
            }
            for(int i=0; i<column; i++){
                arr[0][i] = up_down_temp_arr[i];
            }
        }

        else if(command== "right"){
            // right
            for (int i=0; i<row; i++){
                right_left_temp_array[i] =arr[i][column-1];
            }
            for (int i=0; i<row; i++){
                for(int j = column-2; j >=0; j--){
                    arr[i][j+1] = arr[i][j];
                }
            }
            for(int i=0; i<row; i++){
                arr[i][0] = right_left_temp_array[i];
            }
        }

        else if(command == "left"){
            // left
            for (int i=0; i<row; i++){
                right_left_temp_array[i] =arr[i][0];
            }
            for (int i=0; i<row; i++){
                for(int j = 1; j < column; j++){
                    arr[i][j-1] = arr[i][j];
                }
            }
            for(int i=0; i<row; i++){
                arr[i][column-1] = right_left_temp_array[i];
            }           
        }

        // print the new array
        printf("Command #%d\n" , i+1);
        int largest = row*column;
        for (int i=0; i< row; i++){
            for(int j = 0; j<column; j++){
                int num = arr[i][j];
                if ( largest > 999 && num < 1000 ) // largest 4 digit, num 3 digit
                    printf("0");
                if ( largest > 99 && num < 100 ) // largest 3 digit, num 2 digit
                    printf("0");
                if ( largest > 9 && num < 10 ) // largest 2 digit, num 1 digit
                    printf("0");
                    
                printf("%d", num);
                if(j< column-1)
                    printf(" ");
            }
            printf("\n");
        }
    }
	return 0;
}