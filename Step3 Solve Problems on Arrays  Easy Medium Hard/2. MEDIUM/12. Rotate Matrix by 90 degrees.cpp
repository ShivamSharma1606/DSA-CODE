#include <bits/stdc++.h>
#include<vector>

//brute force approach
//TC=O(N^2) AND SC=O(N^2)
using namespace std;
void rotateMatrix(vector<vector<int>> &mat){

	int n=mat.size();
	vector<vector<int>> ans(n, vector<int>(n));

	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			ans[j][n-i-1]=mat[i][j];
		}
	}

	for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            mat[i][j] = ans[i][j];
        }
    }
}

// SC = N^2 AND TC = N^2

//OPTIMAL APPROACH
//TC= 2(N*N) AND SC=1

//first transpose the matrix and then reverse the rows
void rotateMatrix(vector<vector<int>> &mat){
	int n=mat.size();
	for(int i=0;i<n;i++){
		for(int j=i;j<n;j++){
			swap(mat[i][j],mat[j][i]);
		}
	}

	for(int i=0;i<n;i++){
		reverse(mat[i].begin(),mat[i].end());
	}
}
