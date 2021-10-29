/*
link :: https://leetcode.com/problems/spiral-matrix/
*/

class Solution
{
public:
    vector<int> spiralOrder(vector<vector<int>> &matrix)
    {

        int row = matrix.size();    //  size of row
        int col = matrix[0].size(); // size of column

        int row_start = 0; // row starting
        int col_start = 0; // column starting

        int row_end = row - 1; // row ending
        int col_end = col - 1; //  column ending

        vector<int> spiral; //  declaration of the new vector spiral

        while ( row_start <= row_end && col_start <= col_end)
        {
            for (int j = col_start; j <= col_end; j++)
            {
                spiral.push_back(matrix[row_start][j]);
            }

            row_start++; // increment of  row by 1 to point at next row

            for (int j = row_start; j <= row_end; j++)
            {
                spiral.push_back(matrix[j][col_end]);
            }
            col_end--; // to decrease the column end by 1 to point at rear element

            if( row_start <= row_end )
            {
                for (int j = col_end ; j >= col_start ; j--)
                {
                    spiral.push_back (matrix[row_end][j]);
                }
            }
            row_end--; // to decrease the row pointer at end by 1 

            if ( col_start <= col_end )
            { 
                for (int j = row_end ; j >= row_start ; j--)
                {
                    spiral.push_back ( matrix[j][col_start] ) ;
                }

            }

            col_start++;
        }

        return spiral ; 
    }
};

/*

Constraints ::

m == matrix.length
n == matrix[i].length
1 <= m, n <= 10
-100 <= matrix[i][j] <= 100

Example ::

Input: matrix = [[1,2,3],[4,5,6],[7,8,9]]
Output: [1,2,3,6,9,8,7,4,5]

Input: matrix = [[1,2,3,4],[5,6,7,8],[9,10,11,12]]
Output: [1,2,3,4,8,12,11,10,9,5,6,7]
 
*/