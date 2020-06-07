/*

Give a N*N square matrix, return an array of its anti-diagonals. Look at the example for more details.

Example:

Input: 	
1 2 3
4 5 6
7 8 9

Return the following :
[ 
  [1],
  [2, 4],
  [3, 5, 7],
  [6, 8],
  [9]
]
Input : 
1 2
3 4

Return the following  : 
[
  [1],
  [2, 3],
  [4]
]

*/

vector<vector<int> > Solution::diagonal(vector<vector<int> > &A) {
    
    vector<vector<int> > sol(2*A.size()-1);
    
    int rows = A.size();
    int cols = A[0].size();
    int calc = 0;
    for(int j = 0; j < cols; j++){
        int jtemp = j;
        int jjtemp= j;
        for(int i = 0; i <= jtemp; i++){
            if(j == 0){
                // cout << A[i][j];
                sol[calc].push_back(A[i][j]);
            }
            else{
                if(i != 0){
                    jjtemp--;
                }
                // cout << A[i][jjtemp];
                sol[calc].push_back(A[i][jjtemp]);
            }
            // cout << endl;
        }
        calc++;
    }
    
    int count = rows-1;
    int itemp = 1;
    
    while(count > 0){
        int j = A.size()-1;
        int jtemp = count;
        for(int i = itemp; i <= rows; i++){
            if(jtemp == 0){
                break;
            }
            // cout << A[i][j];
            sol[calc].push_back(A[i][j]);
            jtemp--;
            j--;
        }
        // cout << endl;
        count--;
        itemp++;
        calc++;
    }
    
    return sol;
}
