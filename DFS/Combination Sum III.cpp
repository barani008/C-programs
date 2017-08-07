class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> ret;
        vector<int> vect;
        dfs(ret,vect, k, n, 1);
        return ret;
    }
    
    void dfs(vector<vector<int>>& ret, vector<int> vect, int k, int n, int start){
        if(vect.size()>k)
            return;
        if(vect.size()==k && n==0)
            ret.push_back(vect);
        else{
            for(int i=start;i<=9;i++){
                //auto it = lower_bound(vect.begin(), vect.end(), i);
                //if(it==vect.end()|| *it!=i){
                    vect.push_back(i);
                    dfs(ret, vect, k, n-i, i+1);
                    vect.pop_back();
                //}
            }
        }
    }
};