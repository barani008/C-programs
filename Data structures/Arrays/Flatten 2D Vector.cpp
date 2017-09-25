/*
Implement an iterator to flatten a 2d vector.

For example,
Given 2d vector =

[
  [1,2],
  [3],
  [4,5,6]
]
By calling next repeatedly until hasNext returns false, the order of elements returned by next should be: [1,2,3,4,5,6]
*/
class Vector2D {
public:
    int rindex = 0;
    int cindex = 0;
    queue<vector<int>> q;
    Vector2D(vector<vector<int>>& vec2d) {
        for(vector<int> tmp: vec2d){
            q.push(tmp);
        }
    }

    int next() {
        if(hasNext()){
            int ret = q.front().front();
            q.front().erase(q.front().begin());
            return ret;
        }
        return 0;
    }

    bool hasNext() {
        while(!q.empty() && q.front().size()==0){
            q.pop();
        }
        if(q.empty())
            return false;
        else
            return true;
    }
};

/**
 * Your Vector2D object will be instantiated and called as such:
 * Vector2D i(vec2d);
 * while (i.hasNext()) cout << i.next();
 */