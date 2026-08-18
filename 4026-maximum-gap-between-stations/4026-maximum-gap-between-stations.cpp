class Solution {
public:
    int maximumGap(string skill, string station) {
        int sz1 = skill.length();
        int sz2 = station.length();
        
        vector<int> first_occ(sz1);
        int pos = 0;
        for (int i = 0; i < sz1; ++i) {
            while (station[pos] != skill[i]) {
                pos++;
            }
            first_occ[i] = pos;
            pos++;
        }
        vector<int> last_occ(sz1);
        pos = sz2 - 1;
        for (int i = sz1 - 1; i >= 0; --i) {
            while (station[pos] != skill[i]) {
                pos--;
            }
            last_occ[i] = pos;
            pos--;
        }
        
        int biggest_diff = 0;
        for (int i = 1; i < sz1; ++i) {
            int current_gap = last_occ[i] - first_occ[i - 1];
            if (current_gap > biggest_diff) {
                biggest_diff = current_gap;
            }
        }
        
        return biggest_diff;
    }
};