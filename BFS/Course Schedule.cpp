/*
There are a total of n courses you have to take, labeled from 0 to n - 1.

Some courses may have prerequisites, for example to take course 0 you have to first take course 1, which is expressed as a pair: [0,1]

Given the total number of courses and a list of prerequisite pairs, is it possible for you to finish all courses?

For example:

2, [[1,0]]
There are a total of 2 courses to take. To take course 1 you should have finished course 0. So it is possible.

2, [[1,0],[0,1]]
There are a total of 2 courses to take. To take course 1 you should have finished course 0, and to take course 0 you should also have finished course 1. So it is impossible.

Note:
The input prerequisites is a graph represented by a list of edges, not adjacency matrices. Read more about how a graph is represented.
You may assume that there are no duplicate edges in the input prerequisites.
*/
class Solution {
public:
    bool canFinish(int numCourses, vector<pair<int, int>>& prereq) {
        unordered_set<int> finished;
        unordered_map<int, vector<int>> map;
        unordered_map<int, vector<int>> rev;
        queue<int> q;
        for(int i=0;i<numCourses;i++){
            map[i].clear();
            rev[i].clear();
        }
        for(pair<int, int> p: prereq){
            map[p.first].push_back(p.second);
            rev[p.second].push_back(p.first);
        }
        for(auto it=map.begin();it!=map.end();it++){
            if(it->second.size()==0){
                finished.insert(it->first);
                q.push(it->first);
            }
        }
        while(!q.empty()){
            int cur = q.front();
            for(int f: rev[cur]){
                if(finished.find(f)==finished.end()){
                    bool allFound = true;
                    for(int course:map[f]){
                        if(finished.find(course) == finished.end()){
                            allFound = false;
                            break;
                        }
                    }
                    if(allFound){                        
                        finished.insert(f);
                        q.push(f);
                    }
                }
            }
            q.pop();
        }
        if(finished.size()== numCourses)
            return true;
        else
            return false;
    }
};