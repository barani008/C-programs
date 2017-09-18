/*
According to the Wikipedia's article: "The Game of Life, also known simply as Life, is a cellular automaton devised by the British mathematician John Horton Conway in 1970."

Given a board with m by n cells, each cell has an initial state live (1) or dead (0). Each cell interacts with its eight neighbors (horizontal, vertical, diagonal) using the following four rules (taken from the above Wikipedia article):

Any live cell with fewer than two live neighbors dies, as if caused by under-population.
Any live cell with two or three live neighbors lives on to the next generation.
Any live cell with more than three live neighbors dies, as if by over-population..
Any dead cell with exactly three live neighbors becomes a live cell, as if by reproduction.
Write a function to compute the next state (after one update) of the board given its current state.
*/

class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        if(board.size()==0)
            return;
        int row = board.size();
        int col = board[0].size();
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                int count = 0;
                if(i>0 && (board[i-1][j] == 2 || board[i-1][j] == 1)){
                    count++;
                }
                if(j>0 && (board[i][j-1] == 2 || board[i][j-1] == 1)){
                    count++;
                }
                if(i>0 && j>0 &&(board[i-1][j-1] == 2 || board[i-1][j-1] == 1)){
                    count++;
                }
                if(i<row-1 && (board[i+1][j] == 2 || board[i+1][j] == 1)){
                    count++;
                }
                if(j<col-1 && (board[i][j+1] == 2 || board[i][j+1] == 1)){
                    count++;
                }
                if(i<row-1 && j<col-1 && (board[i+1][j+1] == 2 || board[i+1][j+1] == 1)){
                    count++;
                }
                if(i>0 && j<col-1 && (board[i-1][j+1] == 2 || board[i-1][j+1] == 1)){
                    count++;
                }
                if(i<row-1 && j>0 && (board[i+1][j-1] == 2 || board[i+1][j-1] == 1)){
                    count++;
                }
                if((count < 2 || count >3) && board[i][j] == 1)
                   board[i][j] = 2;
                else if(count == 3 && board[i][j] == 0)
                   board[i][j] = -1;   
            }
        }
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                if(board[i][j] == -1)
                    board[i][j] = 1;
                else if(board[i][j] == 2)
                    board[i][j] = 0;
            }
        }
    }
};