/*
Suppose you are at a party with n people (labeled from 0 to n - 1) and among them, there may exist one celebrity. The definition of a celebrity is that all the other n - 1 people know him/her but he/she does not know any of them.

Now you want to find out who the celebrity is or verify that there is not one. The only thing you are allowed to do is to ask questions like: "Hi, A. Do you know B?" to get information of whether A knows B. You need to find out the celebrity (or verify there is not one) by asking as few questions as possible (in the asymptotic sense).

You are given a helper function bool knows(a, b) which tells you whether A knows B. Implement a function int findCelebrity(n), your function should minimize the number of calls to knows.

Note: There will be exactly one celebrity if he/she is in the party. Return the celebrity's label if there is a celebrity in the party. If there is no celebrity, return -1.
*/
// Forward declaration of the knows API.
bool knows(int a, int b);

class Solution {
public:
    int findCelebrity(int n) {
        if(n == 0)
            return -1;
        if(n == 1)
            return 0;
        queue<int> candidates;
        for(int i=0;i<n;i++)
            candidates.push(i);
        queue<int> ret = find(candidates);
        if(ret.empty())
            return -1;
        else{
            for(int i=0;i<n;i++){
                if(i!=ret.front() && knows(i, ret.front()) && !knows(ret.front(), i))
                    continue;
                else if(i!=ret.front())
                    return -1;
            }
            return ret.front();
        }            
    }
    
    queue<int> find(queue<int> q){
        while(q.size()>=2){
            int a = q.front();
            q.pop();
            int b = q.front();
            q.pop();
            bool ab = knows(a, b);
            bool ba = knows(b, a);
            if((ab && ba) || (!ab && !ba))
                continue;
            else if(ab){
                q.push(b);
            }else{
                q.push(a);
            }
        }
        return q;
    }
    
};