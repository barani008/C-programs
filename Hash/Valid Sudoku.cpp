/*
Determine if a Sudoku is valid, according to: Sudoku Puzzles - The Rules.

The Sudoku board could be partially filled, where empty cells are filled with the character '.'.
*/
class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        unordered_set<string> set;
        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                if(board[i][j]!='.'){
                    string b("(");
                    b += board[i][j];
                    b += ")";
                    //cout<<b<<endl;
                    string row = b + to_string(i);
                    string col = to_string(j)+b;
                    string block = to_string(i/3) + b+ to_string(j/3);
                    //cout<<row<<" "<<col<<" "<<block<<endl;
                    if(set.find(row)!=set.end() || set.find(col)!=set.end() 
                                        || set.find(block)!=set.end())
                        return false;
                    set.insert(row);
                    set.insert(col);
                    set.insert(block);
                }
            }
        }
        return true;
    }
};