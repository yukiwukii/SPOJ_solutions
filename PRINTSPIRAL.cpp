#include <iostream>
using namespace std;

int main() {
	
	// declare variables
    int row, column, tc;
    cin >> tc;

    // make an array of pairs to store the row and column for each test case
    pair<int, int> arr_coor[tc];
    for (int i=0; i<tc; i++){
        cin >> row >> column;
        arr_coor[i] = make_pair(row,column);
    }
    
    // logic
    for (int run = 0; run < tc; run++){

        // declare some variables
        int row_max = arr_coor[run].first;
        int column_max = arr_coor[run].second;
        int spiral[row_max][column_max];
        int num_elements = row_max*column_max, count = 0, start = 1;
        int row_start = 0, column_start = 0;

        // start filling in the spiral
        while (count < num_elements){
            // direction: right
            for(int i =column_start; i<column_max && count < num_elements; i++){
                spiral[row_start][i] = start++;
                count++;
            }
            row_start++;

            // direction: down
            for(int i =row_start; i<row_max && count < num_elements; i++){
                spiral[i][column_max-1] = start++;
                count++;
            }
            column_max--;

            // direction: left
            for(int i = column_max-1; i >= column_start && count < num_elements; i--){
                spiral[row_max-1][i] = start++;
                count++;
            }
            row_max--;

            // direction: up
            for(int i= row_max-1; i >=row_start && count < num_elements; i--){
                spiral[i][column_start] = start++;
                count++;
            }
            column_start++;
        }

        // print spiral
        // reset the row_max and column_max (is there any better way of doing this...)
        int row_max_initial = arr_coor[run].first;
        int column_max_initial = arr_coor[run].second;
        cout << "Case " << run+1 << ":" <<endl;
        for (int i =0; i< row_max_initial; i++){
            for(int j = 0; j<column_max_initial; j++){
                
                // prevent empty space at the end of each row
                if(j< column_max_initial-1){

                    // add 0 in front when num_element is 10 or more]
                    if (num_elements > 9){
                        printf("%02d ", spiral[i][j]);
                    }
                    else{
                    cout << spiral[i][j] << " ";
                    }
                }
                else{
                    if (num_elements > 9){
                        printf("%02d", spiral[i][j]);
                    }
                    else{
                    cout << spiral[i][j];
                    }
                }
            }

            if(run < tc){
            cout << endl;
            }
            else{
                continue;
            }
        }
    }
	return 0;
}