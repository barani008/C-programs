/*
Given an integer n, generate a square matrix filled with elements from 1 to n2 in spiral order.

For example,
Given n = 3,

You should return the following matrix:
[
 [ 1, 2, 3 ],
 [ 8, 9, 4 ],
 [ 7, 6, 5 ]
]
*/
enum Enum{LEFT = 0, RIGHT = 1, UP= 2, DOWN = 3};
class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        Enum direction = RIGHT;
        vector<vector<int>> ret;
        if(n==0)
            return ret;
        ret = vector<vector<int>>(n, vector<int>(n,0));
        int rstart = 0, rend = n-1, cstart = 0, cend = n-1;
        int r = 0, c = 0;
        for(int i=1;i<=n*n;){
            if(direction == RIGHT && c<cend){
                ret[r][c] = i++;
                c++;
            }else if(direction == DOWN && r<rend){
                ret[r][c] = i++;
                r++;
            }else if(direction == LEFT && c>cstart){
                ret[r][c] = i++;
                c--;
            }else if(direction == UP && r>rstart){
                ret[r][c] = i++;
                r--;
            }
            if(i > n*n)
                break;
            if(direction == RIGHT && c==cend){
                ret[r][c] = i++;
                direction = DOWN;
                r++;
                rstart++;
            }else if(direction == DOWN && r==rend){
                ret[r][c] = i++;
                direction = LEFT;
                c--;
                cend--;
            }else if(direction == LEFT && c==cstart){
                ret[r][c] = i++;
                direction = UP;
                r--;
                rend--;
            }else if(direction == UP && r==rstart){
                ret[r][c] = i++;
                direction = RIGHT;
                c++;
                cstart++;
            }
        }
        return ret;
    }
};