/*
Given a 2D board and a word, find if the word exists in the grid.

The word can be constructed from letters of sequentially adjacent cell, where "adjacent" cells are those horizontally or vertically neighboring. The same letter cell may not be used more than once.

For example,
Given board =

[
  ['A','B','C','E'],
  ['S','F','C','S'],
  ['A','D','E','E']
]
word = "ABCCED", -> returns true,
word = "SEE", -> returns true,
word = "ABCB", -> returns false.
*/
class Solution {
public:
    vector<vector<vector<int>>> map;
    bool check(vector<vector<char>>& board, string word, int row, int col, int ind, vector<vector<bool>> added){
        if(ind == word.size())
            return true;
        if(map[row][col][ind] == 0)
            return false;
        else if(map[row][col][ind] == 1)
            return true;                
        added[row][col] = true;
        bool ret = false;
        if(row>0 &&!added[row-1][col] && board[row-1][col] == word[ind]){
            ret = check(board, word, row-1, col, ind+1, added);
        }
        if(!ret && col>0 && !added[row][col-1] && board[row][col-1] == word[ind]){
            ret = check(board, word, row, col-1, ind+1, added);
        }
        if(!ret && row<board.size()-1 && !added[row+1][col] && board[row+1][col] == word[ind]){
            ret = check(board, word, row+1, col, ind+1, added);
        }
        if(!ret && col<board[0].size()-1 && !added[row][col+1] && board[row][col+1] == word[ind]){
            ret = check(board, word, row, col+1, ind+1, added);
        }
        if(ret)
            map[row][col][ind] == 1;
        else 
            map[row][col][ind] == 0;
        //cout<<ret<<endl;
        return ret;
    }
    
    bool exist(vector<vector<char>>& board, string word) {
        if(word.size()==0)
            return true;
        if(board.size()==0)
            return false;
        map = vector<vector<vector<int>>>(board.size(),vector<vector<int>>(board[0].size(),
                                                        vector<int>(word.size(), -1)));
        vector<vector<bool>> added(board.size(),vector<bool>(board[0].size(), false));
        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[0].size();j++){
                if(board[i][j] == word[0]){
                    if(check(board, word, i, j, 1, added))
                        return true;
                }
            }
        }
        return false;
        
    }
};