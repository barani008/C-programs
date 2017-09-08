enum Enum{ RIGHT = 0, DOWN =1, LEFT = 2, UP = 3 } ;

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& m) {
        vector<int> ret;
        if(m.size()==0)
            return ret;
        int rstart = 0, cstart = 0;
        int rend = m.size()-1, cend = m[0].size()-1;
        int i=0, j=0;
        Enum direction = RIGHT;
        while(ret.size()<(m.size()*m[0].size())){
            if(direction == RIGHT && j<cend){
                ret.push_back(m[i][j]);
                j++;
            }else if(direction == DOWN && i<rend){
                ret.push_back(m[i][j]);
                i++;
            }else if(direction == LEFT && j>cstart){
                ret.push_back(m[i][j]);
                j--;
            }else if(direction == UP && i>rstart){
                ret.push_back(m[i][j]);
                i--;
            }
            if(direction == RIGHT && j==cend){
                ret.push_back(m[i][j]);
                i++;
                rstart++;
                direction = DOWN;
            }else if(direction == DOWN && i==rend){
                ret.push_back(m[i][j]);
                cend--;
                j--;
                direction=LEFT;
            }else if(direction == LEFT && j==cstart){
                ret.push_back(m[i][j]);
                i--;
                rend--;
                direction=UP;
            }else if(direction == UP && i==rstart){
                ret.push_back(m[i][j]);
                j++;
                cstart++;
                direction = RIGHT;
            }
        }
        return ret;
    }
};