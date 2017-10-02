/*

Numbers can be regarded as product of its factors. For example,

8 = 2 x 2 x 2;
  = 2 x 4.
Write a function that takes an integer n and return all possible combinations of its factors.

Note: 
You may assume that n is always positive.
Factors should be greater than 1 and less than n.
Examples: 
input: 1
output: 
[]
input: 37
output: 
[]
input: 12
output:
[
  [2, 6],
  [2, 2, 3],
  [3, 4]
]
input: 32
output:
[
  [2, 16],
  [2, 2, 8],
  [2, 2, 2, 4],
  [2, 2, 2, 2, 2],
  [2, 4, 4],
  [4, 8]
]
*/
class Solution {
public:
    vector<vector<int>> getFactors(int n) {
        vector<vector<int>> ret;
        vector<int> row;
        getResults(ret, row, n);
        return ret;
    }
    
    void getResults(vector<vector<int>>& ret, vector<int>& row, int n){
        int i = row.empty()? 2:row.back();
        while(i<=n/i){
            if(n%i==0){
                row.push_back(i);
                row.push_back(n/i);
                ret.push_back(row);
                row.pop_back();
                getResults(ret, row, n/i);
                row.pop_back();
            }
            i++;
        }
    }
};