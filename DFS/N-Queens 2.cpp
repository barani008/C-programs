/*Follow up for N-Queens problem.

Now, instead outputting board configurations, return the total number of distinct solutions.
*/

class Solution {
public:
    int totalNQueens(int n) {
        vector<int> row(n, 0);
        vector<bool> col(n,true);
        vector<bool> four5(2*n-1, true);
        vector<bool> one35(2*n-1, true);
        int count = 0;
        dfs(0, row, col, four5, one35, count);
        return count;
    }
    
    void dfs(int i,vector<int>& row,vector<bool>& col, vector<bool>& four5, vector<bool>& one35, int& count){
        if(i==row.size()){
            count++;
            return;
        }else{
            for(int j=0;j<row.size();j++){
                if(col[j] && four5[i+j] && one35[col.size()-1+j-i]){
                    row[i] = j; 
                    col[j] = four5[i+j] = one35[col.size()-1+j-i] = false;
                    dfs(i+1, row, col, four5, one35, count);
                    col[j] = four5[i+j] = one35[col.size()-1+j-i] = true;
                }
            }
        }
    }
};