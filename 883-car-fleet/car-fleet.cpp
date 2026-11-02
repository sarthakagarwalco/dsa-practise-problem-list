#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int n = position.size();
        vector<pair<int, int>> cars(n);
        
        for (int i = 0; i < n; ++i) {
            cars[i] = {position[i], speed[i]};
        }
        
        sort(cars.rbegin(), cars.rend());
        
        int fleets = 0;
        double max_time = 0.0;
        
        for (int i = 0; i < n; ++i) {
            double t = (double)(target - cars[i].first) / cars[i].second;
            if (t > max_time) {
                fleets++;
                max_time = t;
            }
        }
        
        return fleets;
    }
};