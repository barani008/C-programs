/*
Suppose you have a random list of people standing in a queue. Each person is described by a pair of integers (h, k), where h is the height of the person and k is the number of people in front of this person who have a height greater than or equal to h. Write an algorithm to reconstruct the queue.

Note:
The number of people is less than 1,100.

Example

Input:
[[7,0], [4,4], [7,1], [5,0], [6,1], [5,2]]

Output:
[[5,0], [7,0], [5,2], [6,1], [4,4], [7,1]]
*/
class Solution {
public:
    vector<pair<int, int>> reconstructQueue(vector<pair<int, int>>& people) {
        vector<pair<int,int>> res;        
        while(people.size()>0){
            int max1 = 0;
            vector<pair<int, int>> ret;
            for(pair<int, int> p: people){
                if(p.first > max1){
                    max1 = p.first;
                    ret.clear();
                    ret.push_back(p);
                }else if(p.first == max1){
                    ret.push_back(p);
                }
            }
            sort(ret.begin(), ret.end());
            for(pair<int, int> p: ret){
                res.insert(res.begin()+p.second, p);
            }
            for(int i =0;i<people.size();){
                if(people[i].first==max1)
                    people.erase(people.begin()+i);
                else
                    i++;
            }
        }
        return res;
    }
};