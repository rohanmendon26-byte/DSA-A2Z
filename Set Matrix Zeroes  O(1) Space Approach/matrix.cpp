//Brute force
markrow(){
    for(j=0;j<m;j++){
        if(arr[i][j]!=0){
            arr[i][j]=-1
        }
    }
}

markcol(){
    for(i=0;i<n;i++){
        if(arr[i][j]!=0){
            arr[i][j]=-1
        }
    }
}

for(int i=0;i<n;i++){
    for(j=0;j<m;i++){
        if(arr[i][j]==0){
            markrow();
            markcol();
        }
    }
}

for(int i=0;i<n;i++){
    for(j=0;j<m;i++){
        if(arr[i][j]==-1){
            arr[i][j]=0
        }
    }
}



//better approach
#include <bits/stdc++.h> 
vector<vector<int>> zeroMatrix(vector<vector<int>> &matrix, int n, int m) {
	// Write your code here.
	int col[m]={0};
	int row[n]={0};
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			if(matrix[i][j]==0){
				row[i]=1;
				col[j]=1;
			}
		}
	}

	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			if(row[i] || col[j]){
				matrix[i][j]=0;
			}
		}
	}
	return matrix;
}

// Input: matrix = [[1,1,1],[1,0,1],[1,1,1]]
// Output: [[1,0,1],[0,0,0],[1,0,1]]


//optimal approach
#include <bits/stdc++.h> 
vector<vector<int>> zeroMatrix(vector<vector<int>> &matrix) {
	// Write your code here.
	int n=matrix.size();
	int m=matrix[0].size();
	int col0=1;
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			if(matrix[i][j]==0){
				matrix[i][0]=0;
				if(j!=0)
				   matrix[0][j]=0;
				else
				   col0=0;
			}
		}
	}
	for(int i=1;i<n;i++){
		for(int j=1;j<m;j++){
			if(matrix[i][j]!=0){
				if(matrix[0][j]==0|| matrix[i][0]==0){
					matrix[i][j]=0;
				}
			}
		}
	}

	if(matrix[0][0]==0){
		for(int j=0;j<m;j++)
		    matrix[0][j]=0;
	}
	if(col0==0){
		for(int i=0;i<n;i++){
			matrix[i][0]=0;
		}
	}
	return matrix;
}