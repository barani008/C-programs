/*
Given a m x n matrix, if an element is 0, set its entire row and column to 0. Do it in place.
*/
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        if(matrix.size()==0)
            return;
        bool rowZero = false;
        bool colZero = false;
        int row = matrix.size();
        int col = matrix[0].size();
        for(int i=0;i<row;i++){
            if(matrix[i][0]==0){
                colZero = true;
                break;
            }
        }
        for(int i=0;i<col;i++){
            if(matrix[0][i]==0){
                rowZero = true;
                break;
            }
        }
        for(int i=1;i<row;i++){
            for(int j=1;j<col;j++){
                if(matrix[i][j]==0){
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                }
            }
        }
        for(int i=1;i<row;i++){
            if(matrix[i][0] == 0){
                for(int j=1;j<col;j++)
                    matrix[i][j] = 0;
            }
        }
        for(int i=1;i<col;i++){
            if(matrix[0][i] == 0){
                for(int j=1;j<row;j++)
                    matrix[j][i] = 0;
            }
        }
        if(rowZero){
            for(int i=0;i<col;i++)
                matrix[0][i] = 0;
        }
        if(colZero){
            for(int j=0;j<row;j++)
                matrix[j][0] = 0;
        }
    }
};