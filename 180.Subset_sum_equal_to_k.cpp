#include <bits/stdc++.h> 
/*****Recursion*****/
// bool checkSum(int ind, int target, vector<int>& arr)    {
//     if(target == 0)    {
//         return true;
//     }
//     if(ind == 0)    {
//         return arr[0] == target;
//     }
//     bool notpick = checkSum(ind-1, target, arr);
//     bool pick = false;
//     if(arr[ind] <= target)    {
//         pick = checkSum(ind-1, target-arr[ind], arr);
//     }
//     return pick || notpick;
// }

// bool subsetSumToK(int n, int k, vector<int> &arr) {
//     return checkSum(n-1, k, arr);
// }


/*****Memoization****/
// bool checkSum(int ind, int target, vector<int>& arr, vector<vector<bool>>& dp)    {
//     if(target == 0)    {
//         return true;
//     }
//     if(ind == 0)    {
//         return arr[0] == target;
//     }
//     if(dp[ind][target] != false)    {
//         return dp[ind][target];
//     }
//     bool notpick = checkSum(ind-1, target, arr, dp);
//     bool pick = false;
//     if(arr[ind] <= target)    {
//         pick = checkSum(ind-1, target-arr[ind], arr, dp);
//     }
//     return dp[ind][target] = pick || notpick;
// }

// bool subsetSumToK(int n, int k, vector<int> &arr) {
//     vector<vector<bool>> dp(n, vector<bool>(k+1, false));
//     return checkSum(n-1, k, arr, dp);
// }


/*****Tabulation*****/
// bool subsetSumToK(int n, int k, vector<int> &arr) {
//     vector<vector<bool>> dp(n, vector<bool>(k+1, false));
//     for(int i = 0; i < n; i++)    {
//         dp[i][0] = true;
//     }
//     dp[0][arr[0]] = true;
//     for(int ind = 1; ind < n; ind++)    {
//         for(int target = 1; target <= k; target++) {
//             bool notpick = dp[ind-1][target];
//             bool pick = false;
//             if(arr[ind] <= target)    {
//                 pick = dp[ind-1][target-arr[ind]];
//             }
//             dp[ind][target] = notpick || pick;
//         }
//     }
//     return dp[n-1][k];
// }


/****Space Optimized tabulation****/
bool subsetSumToK(int n, int k, vector<int> &arr) {
    vector<bool> prev(k+1, false);
    vector<bool> cur(k+1, false);
    prev[0] = true;
    cur[0] = true;
    prev[arr[0]] = true;
    for(int ind = 1; ind < n; ind++)    {
        for(int target = 1; target <= k; target++) {
            bool notpick = prev[target];
            bool pick = false;
            if(arr[ind] <= target)    {
                pick = prev[target-arr[ind]];
            }
            cur[target] = notpick || pick;
        }
        prev = cur;
    }
    return prev[k];
}