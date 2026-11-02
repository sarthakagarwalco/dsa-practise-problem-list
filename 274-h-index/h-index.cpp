#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int hIndex(vector<int>& citations) {
        int n = citations.size();
        vector<int> freq(n + 1, 0);
        
        for (int x : citations) {
            if (x >= n) {
                freq[n]++;
            } else {
                freq[x]++;
            }
        }
        
        int total = 0;
        for (int i = n; i >= 0; --i) {
            total += freq[i];
            if (total >= i) {
                return i;
            }
        }
        
        return 0;
    }
};