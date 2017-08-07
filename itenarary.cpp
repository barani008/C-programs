/*Given a list of airline tickets represented by pairs of departure and arrival airports [from, to], reconstruct the itinerary in order. All of the tickets belong to a man who departs from JFK. Thus, the itinerary must begin with JFK.

Note:
If there are multiple valid itineraries, you should return the itinerary that has the smallest lexical order when read as a single string. For example, the itinerary ["JFK", "LGA"] has a smaller lexical order than ["JFK", "LGB"].
All airports are represented by three capital letters (IATA code).
You may assume all tickets form at least one valid itinerary.
Example 1:
tickets = [["MUC", "LHR"], ["JFK", "MUC"], ["SFO", "SJC"], ["LHR", "SFO"]]
Return ["JFK", "MUC", "LHR", "SFO", "SJC"].
Example 2:
tickets = [["JFK","SFO"],["JFK","ATL"],["SFO","ATL"],["ATL","JFK"],["ATL","SFO"]]
Return ["JFK","ATL","JFK","SFO","ATL","SFO"].
Another possible reconstruction is ["JFK","SFO","ATL","JFK","ATL","SFO"]. But it is larger in lexical order.
*/
class Solution {
public:
    unordered_map<string, vector<string>> map;
    vector<string> res;
    
    vector<string> findItinerary(vector<pair<string, string>> tickets) {
        for(pair<string, string> tick:tickets)
            map[tick.first].push_back(tick.second);
        for(auto it= map.begin();it!=map.end();it++){
            sort(map[it->first].begin(), map[it->first].end());
        }
        visit("JFK");
        return vector<string> (res.rbegin(), res.rend());
    }
    
    void visit(string port){
        while(map[port].size()){
            string str = map[port][0];
            map[port].erase(map[port].begin());
            visit(str);
        }
        res.push_back(port);
    }
};