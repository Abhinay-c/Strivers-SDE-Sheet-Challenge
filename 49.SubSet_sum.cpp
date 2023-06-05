#include <bits/stdc++.h> 
using namespace std;

void makeSubset(int i, int sum, int n, vector<int>& ans, vector<int>& nums)
{
    if(i == nums.size())    {
        ans.push_back(sum);
        return;
    }
    makeSubset(i+1, sum + nums[i], n, ans, nums);
    makeSubset(i+1, sum, n, ans, nums);
}

vector<int> subsetSum(vector<int> &nums)
{
    vector<int> ans;
    makeSubset(0, 0, nums.size(),ans, nums);
    sort(ans.begin(), ans.end());
    return ans;
}