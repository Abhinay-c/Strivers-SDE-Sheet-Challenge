#include <bits/stdc++.h> 
using namespace std;

/*****Recursion*****/
// int findPaths(int i, int j)    {
// 	if(i == 0 && j == 0)
// 	{
// 		return 1;
// 	}
// 	if(i < 0 || j < 0)
// 	{
// 		return 0;
// 	}
// 	int left = findPaths(i-1, j);
// 	int top = findPaths(i, j-1);
// 	return left + top;
// }

// int uniquePaths(int m, int n) {
// 	return findPaths(m-1, n-1);
// }

/*****Memoization*****/
int findPaths(int i, int j, vector<vector<int>>& dp)    {
	if(i == 0 && j == 0)
	{
		return 1;
	}
	if(i < 0 || j < 0)
	{
		return 0;
	}
	if(dp[i][j] != -1)
	{
		return dp[i][j];
	}
	int left = findPaths(i-1, j, dp);
	int top = findPaths(i, j-1, dp);
	return dp[i][j] = left + top;
}

int uniquePaths(int m, int n) {
	vector<vector<int>> dp(m, vector<int>(n, -1));
	dp[0][0] = findPaths(m-1, n-1, dp);
	return dp[0][0];
}