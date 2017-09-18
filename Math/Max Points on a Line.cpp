/**

Given n points on a 2D plane, find the maximum number of points that lie on the same straight line.
 * Definition for a point.
 * struct Point {
 *     int x;
 *     int y;
 *     Point() : x(0), y(0) {}
 *     Point(int a, int b) : x(a), y(b) {}
 * };
 */
class Solution {
public:
    int maxPoints(vector<Point>& points) {        
        int res = 0;
        for(int i=0;i<points.size();i++){
            int samepoint = 1;
            unordered_map<long double, int> map;
            int local = 0;
            for(int j=i+1;j<points.size();j++){
                if(points[i].x == points[j].x && points[i].y == points[j].y){
                    samepoint++;
                }else if(points[i].x == points[j].x){
                    map[INT_MAX]++;
                }else{
                    long double slope = (long double)(points[i].y - points[j].y)/(long double)(points[i].x - points[j].x);
                    map[slope]++;
                }
            }
            for(auto it = map.begin();it!=map.end();it++){
                local = max(local, it->second);
            }
            local += samepoint;
            res = max(local, res);
        }
        return res;
    }
};