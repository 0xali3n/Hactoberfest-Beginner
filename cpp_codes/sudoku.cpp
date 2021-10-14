#include <bits/stdc++.h>
using namespace std;

// UNASSIGNED is used for empty cells in sudoku grid 
#define UNASSIGNED 0  

// N is used for the size of Sudoku grid.  
// Size will be NxN  
#define N 9  

bool SolveSudoku(int grid[N][N]);

void printGrid(int grid[N][N]);

int main() {
	int t;
	cin>>t;
	while(t--)
	{
		int grid[N][N];
		
		for(int i=0;i<9;i++)
		    for(int j=0;j<9;j++)
		        cin>>grid[i][j];
		
		if (SolveSudoku(grid) == true)  
            printGrid(grid);  
        else
            cout << "No solution exists";  
        
        cout<<endl;
	}
	
	return 0;
}

bool isSafe(int i, int j,int num,int grid[9][9]){
    for(int p=0;p<9;p++){
        if(grid[i][p]==num){
            return false;
        }
        if(grid[p][j]==num){
            return false;
        }
    }
  
    int s = sqrt(9);
    i = i - (i%s);
    j = j - (j%s);
    for(int l =0;l<s;l++){
        for(int m=0;m<s;m++){
            if(grid[l+i][m+j]==num){
                return false;
            }
        }
    }
    return true;
}
bool SolveSudoku(int grid[N][N])  
{ 
    bool flag = false;
    int i,j;
    for( i=0;i<N;i++){
        for( j=0;j<N;j++){
            if(grid[i][j]==0){
                flag = true;
                break;
            }
        }
        if(flag){
            break;
        }
    }
    if(i==N && j==N){
        return true;
    }
    for(int k=1;k<=N;k++){
        if(isSafe(i,j,k,grid)){
            grid[i][j] = k;
            if(SolveSudoku(grid)){
                 return true;
            }
               
            grid[i][j] = 0;    
        }
    }
 return false;   
}

void printGrid (int grid[N][N]) 
{
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            cout<<grid[i][j]<<" ";
        }
    }
   
}
