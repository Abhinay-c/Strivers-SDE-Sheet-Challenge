#include <bits/stdc++.h>
using namespace std;

long long int nCr(int n, int r)
{
  long long int l = 1;
  for(int i = 0; i < r; i++)
  {
    l *= (n-i);
    l /= (i+1);
  }
  return l;
}

vector<long long int> getRow(int rowindex)
{
  vector<long long int> row;
  for(int i = 0; i <= rowindex; i++)
  {
    row.push_back(nCr(rowindex, i));
  }
  return row;
}

vector<vector<long long int>> printPascal(int n) 
{
  vector<vector<long long int>> ans;
  for(int i = 0; i < n; i++)
  {
    ans.push_back(getRow(i));
  }
  return ans;
}