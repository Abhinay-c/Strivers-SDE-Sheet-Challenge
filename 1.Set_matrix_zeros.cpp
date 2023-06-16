#include <bits/stdc++.h>
using namespace std;
/******Brute force*****/
    // void makeRow(int j, int n, vector<vector<int>>& matrix)    {
    //     for(int i = 0; i < n; i++)    {
    //         if(matrix[j][i] != 0)    {
    //             matrix[j][i] = -1e9;
    //         }
    //     }
    // }
    // void makeCol(int i, int m, vector<vector<int>>& matrix)    {
    //     for(int j = 0; j < m; j++)    {
    //         if(matrix[j][i] != 0)    {
    //             matrix[j][i] = -1e9;
    //         }
    //     }
    // }
    // void setZeros(vector<vector<int>>& matrix) {
    //     int m = matrix.size();
    //     int n = matrix[0].size();
    //     for(int i = 0; i < m; i++)   {
    //         for(int j = 0; j < n; j++)    {
    //             if(matrix[i][j] == 0)    {
    //                 makeRow(i, n, matrix);
    //                 makeCol(j, m, matrix);
    //             }
    //         }
    //     }
    //     for(int i = 0; i < m; i++)    {
    //         for(int j = 0; j < n; j++)    {
    //             if(matrix[i][j] == -1e9)    {
    //                 matrix[i][j] = 0;
    //             }
    //         }
    //     }
    // }

/********Optimal apporach*******/
    // void setZeros(vector<vector<int>>& matrix) {
    //     int m = matrix.size();
    //     int n = matrix[0].size();
    //     vector<bool> cols(n, -1);
    //     vector<bool> rows(m, -1);
    //     for(int i = 0; i < m; i++)   {
    //         for(int j = 0; j < n; j++)    {
    //             if(matrix[i][j] == 0)    {
    //                 cols[i] = 0;
    //                 rows[j] = 0;

    //             }
    //         }
    //     }
    //     for(int i = 0; i < m; i++)    {
    //         for(int j = 0; j < n; j++)    {
    //             if(cols[i] == 0 || rows[j] == 0)    {
    //                 matrix[i][j] = 0;
    //             }
    //         }
    //     }
    // }

/******Space optimized approach******/
void setZeros(vector<vector<int>> &matrix)
{
	int m = matrix.size();
        int n = matrix[0].size();
        int col0 = 1;
        for(int i = 0; i < m; i++)   {
            for(int j = 0; j < n; j++)    {
                if(matrix[i][j] == 0)    {
                    matrix[i][0] = 0;
                    if(j != 0)    {
                        matrix[0][j] = 0;
                    }
                    else    {
                        col0 = 0;
                    }
                    
                }
            }
        }
        for(int i = 1; i < m; i++)    {
            for(int j = 1; j < n; j++)    {
                if(matrix[i][0] == 0 || matrix[0][j] == 0)    {
                    matrix[i][j] = 0;
                }
            }
        }
        if(matrix[0][0] == 0)    {
            for(int j = 0; j < n; j++)    {
                matrix[0][j] = 0;
            }
        }
        if(col0 == 0)    {
            for(int i = 0; i < m; i++)    {
                matrix[i][0] = 0;
            }
        }
}