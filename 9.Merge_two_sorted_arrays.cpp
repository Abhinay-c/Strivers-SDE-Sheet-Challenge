#include <bits/stdc++.h>
using namespace std;

vector<int> ninjaAndSortedArrays(vector<int>& arr1, vector<int>& arr2, int m, int n) {
	int i = m-1, j = n-1;
	vector<int> ans;
	while(i >= 0 && j >= 0)    {
		if(arr1[i] >= arr2[j])    {
			ans.push_back(arr1[i]);
			i--;
		}
		else	{
			ans.push_back(arr2[j]);
			j--;
		}
	}
	while(i >= 0)	{
		ans.push_back(arr1[i]);
		i--;
	}
	while(j >= 0)	{
		ans.push_back(arr2[j]);
		j--;
	}
	reverse(ans.begin(), ans.end());
	return ans;
}