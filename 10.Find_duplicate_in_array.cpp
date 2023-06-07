#include <bits/stdc++.h>
using namespace std;

int findDuplicate(vector<int> &arr, int n){
	set<int> s;
	for(int i = 0; i < arr.size(); i++)    {
		if(s.find(arr[i]) == s.end())    {
			s.insert(arr[i]);
		}
		else    {
			return arr[i];
		}
	}
	return -1;
}
