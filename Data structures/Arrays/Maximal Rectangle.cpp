/*
vGiven a 2D binary matrix filled with 0's and 1's, find the largest rectangle containing only 1's and return its area.

For example, given the following matrix:

1 0 1 0 0
1 0 1 1 1
1 1 1 1 1
1 0 0 1 0
Return 6.
*/
class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        if(matrix.size()==0)
            return 0;
        vector<int> pass(matrix[0].size(), 0);
        int ret = 0;
        for(int i=0;i<matrix.size();i++){
            for(int j=0;j<matrix[0].size();j++){
               if(matrix[i][j] == '0'){
                   pass[j] = 0;
               }else{
                   pass[j]+= 1;
               }  
            }
            //cout<<endl;
            ret = max(ret, maxHistogram(pass));
            //cout<<ret<<endl;
        }
        return ret;
    }
    
    int maxHistogram(vector<int> line){
        int ret = 0;
        stack<int> stk;
        int i=0;
        for(i=0;i<line.size();i++){
            if(stk.empty()){
                stk.push(i);
            }else{
                int top = stk.top();
                if(line[top] <= line[i]){
                    stk.push(i);
                }else{
                    while(!stk.empty() && line[stk.top()] > line[i]){
                        top = stk.top();
                        stk.pop();
                        if(stk.empty())
                            ret = max(ret, line[top]*i);
                        else
                            ret = max(ret, (i-stk.top()-1)*line[top]);
                    }
                    stk.push(i);
                }
            }
        }
        while(!stk.empty()){
            int top = stk.top();
            stk.pop();
            if(stk.empty())
                ret = max(ret, i*line[top]);
            else{
                ret = max(ret, (i-1-stk.top())*line[top]);
            }
        }
        return ret;
    }
};