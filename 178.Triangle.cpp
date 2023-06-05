#include <bits/stdc++.h>
using namespace std;
/****Recursion****/
// int minSum(int i, int  j, int cost, int&sum, vector<vector<int>>& grid)    {
//     if(i == 0 && j == 0)    {
//         return grid[0][0];
//     }
//     cost += grid[i][j];
//     int up = INT_MAX, left = INT_MAX;
//     if(i > 0)   {
//         up = minSum(i-1, j, cost, sum, grid);
//     }
//     if(j > 0)    {
//         left = minSum(i, j-1, cost, sum, grid);
//     }
//     if(up != INT_MAX || left != INT_MAX)    {
//         cost += min(up, left);
//     }
//     sum = min(sum, cost);
//     return cost;
// }


// int minSumPath(vector<vector<int>> &grid) {
//     int rows = grid.size();
//     int cols = grid[0].size();
//     int sum = INT_MAX;
//     minSum(rows-1, cols-1, 0, sum, grid);
//     return sum;
// }

/*****Memoization***/
// int minSum(int i, int  j, vector<vector<int>>& dp, vector<vector<int>>& grid)    {
//     if(i == 0 && j == 0)    {
//         return grid[0][0];
//     }
//     if(dp[i][j] != -1)   {
//         return dp[i][j];
//     }
//     int cost = grid[i][j];
//     int up = INT_MAX, left = INT_MAX;
//     if(i > 0)   {
//         up = minSum(i-1, j, dp, grid);
//     }
//     if(j > 0)    {
//         left = minSum(i, j-1, dp, grid);
//     }
//     if(up != INT_MAX || left != INT_MAX)    {
//         cost += min(up, left);
//     }
//     return dp[i][j] = cost;
// }


// int minSumPath(vector<vector<int>> &grid) {
//     int rows = grid.size();
//     int cols = grid[0].size();
//     vector<vector<int>> dp(rows, vector<int>(cols, -1));
//     minSum(rows-1, cols-1, dp, grid);
//     return dp[rows-1][cols-1];
// }


/***Tabulation****/
// int minSumPath(vector<vector<int>> &grid) {
//     int rows = grid.size();
//     int cols = grid[0].size();
//     vector<vector<int>> dp(rows, vector<int>(cols, -1));
//     for(int i = 0; i < rows; i++)    {
//         for(int j = 0; j < cols; j++)    {
//             if(i == 0 && j == 0)    {
//                 dp[i][j] = grid[0][0];
//             }
//             int cost = grid[i][j];
//             int up = INT_MAX, left = INT_MAX;
//             if(i > 0)    {
//                 up = dp[i-1][j];
//             }
//             if(j > 0)    {
//                 left = dp[i][j-1];
//             }
//             if(up != INT_MAX || left != INT_MAX)    {
//                 cost += min(up, left);
//             }
//             dp[i][j] = cost;
//         }
//     }
//     return dp[rows-1][cols-1];
// }


/******Space Optimized Tabulation*******/
int minSumPath(vector<vector<int>> &grid) {
    int rows = grid.size();
    int cols = grid[0].size();
    vector<int> prev(cols, -1);
    for(int i = 0; i < rows; i++)    {
        vector<int> cur(cols, -1);
        for(int j = 0; j < cols; j++)    {
            if(i == 0 && j == 0)    {
                cur[j] = grid[0][0];
            }
            int cost = grid[i][j];
            int up = INT_MAX, left = INT_MAX;
            if(i > 0)    {
                up = prev[j];
            }
            if(j > 0)    {
                left = cur[j-1];
            }
            if(up != INT_MAX || left != INT_MAX)    {
                cost += min(up, left);
            }
            cur[j] = cost;
        }
        prev = cur;
    }
    return prev[cols-1];
}