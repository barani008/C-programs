/*
Given a 2d grid map of '1's (land) and '0's (water), count the number of islands. An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically. You may assume all four edges of the grid are all surrounded by water.

Example 1:

11110
11010
11000
00000
Answer: 1

Example 2:

11000
11000
00100
00011
Answer: 3
*/
class Solution {
public:
    void mapIsland(int i, int j, int row, int col, vector<vector<char>>& grid, vector<vector<bool>>& seen){
        seen[i][j] = true;
        if(i>0 && grid[i-1][j]=='1' && !seen[i-1][j])
            mapIsland(i-1, j, row, col, grid, seen);
        if(j>0 && grid[i][j-1]=='1' && !seen[i][j-1])
            mapIsland(i, j-1, row, col, grid, seen);
        if(i<row-1 && grid[i+1][j]=='1' && !seen[i+1][j])
            mapIsland(i+1, j, row, col, grid, seen);
        if(j<col-1 && grid[i][j+1]=='1' && !seen[i][j+1])
            mapIsland(i, j+1, row, col, grid, seen);
    }
    
    int numIslands(vector<vector<char>>& grid) {
        if(grid.size()==0)
            return 0;
        int row = grid.size();
        int ret = 0;
        int col = grid[0].size();
        vector<vector<bool>> seen;
        for(int i=0;i<row;i++){
            vector<bool> tmp(col, false);
            seen.push_back(tmp);
        }
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                if(!seen[i][j] && grid[i][j]=='1'){
                    ret++;
                    mapIsland(i, j, row, col, grid, seen);
                }
            }
        }
        return ret;
    }
};