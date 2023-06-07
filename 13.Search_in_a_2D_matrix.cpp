#include<bits/stdc++.h>
using namespace std;

bool findTarget(vector<vector<int>>& mat, int ind, int n, int target)    {
    for(int j = 0; j < n; j++)    {
        if(mat[ind][j] == target)    {
            return true;
        }
        else if(mat[ind][0] > target)    {
            return false;
        }
    }
    return false;
}

bool searchMatrix(vector<vector<int>>& mat, int target) {
    int m = mat.size();
    int n = mat[0].size();
    for(int i = 0; i < m; i++)    {
        if(mat[i][0] == target)    {
            return true;
        }
        else if(mat[i][0] > target)    {
            return findTarget(mat, i-1, n, target);
        }
    }
    return findTarget(mat, m-1, n, target);
}