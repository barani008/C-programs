/*

Given a string of numbers and operators, return all possible results from computing all the different possible ways to group numbers and operators. The valid operators are +, - and *.


Example 1
Input: "2-1-1".

((2-1)-1) = 0
(2-(1-1)) = 2
Output: [0, 2]


Example 2
Input: "2*3-4*5"

(2*(3-(4*5))) = -34
((2*3)-(4*5)) = -14
((2*(3-4))*5) = -10
(2*((3-4)*5)) = -10
(((2*3)-4)*5) = 10
Output: [-34, -14, -10, -10, 10]
*/
class Solution {
public:
    vector<int> diffWaysToCompute(string input) {
        vector<int> res;
        for(int i=0;i<input.size();i++){
            if(input[i] == '+' || input[i] == '-' || input[i] == '*'){
                string left = input.substr(0, i);
                string right = input.substr(i+1);
                vector<int> l = diffWaysToCompute(left);
                vector<int> r = diffWaysToCompute(right);
                for(int p1:l){
                    for(int p2:r){
                        int c = 0;
                        if(input[i] == '+')
                            c = p1 + p2;
                        else if(input[i] == '-')
                            c = p1 - p2;
                        else 
                            c = p1 * p2;
                        res.push_back(c);
                    }
                }
            }
        }
        if(res.size()==0)
            res.push_back(stoi(input));
        return res;
    }
};