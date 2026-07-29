class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        stack<pair<int, int>> s;

        int ans = INT_MIN;
        for(int i=0; i<n; i++){
            if(s.empty()){
                s.push({i, i});
            }
            else{
                if(heights[s.top().second]<=heights[i]){
                    s.push({i, i});
                }
                int stIdx = i;
                while(!s.empty() && heights[s.top().second]>heights[i]){
                    int area = heights[s.top().second] * (i-s.top().first);
                    ans = max(ans, area);
                    stIdx=s.top().first;
                    s.pop();
                }
                s.push({stIdx, i});
            }
        }

        while(!s.empty()){
            int area = heights[s.top().second]*(n-s.top().first);
            ans = max(ans, area);
            s.pop();
        }

        return ans;
    }

    int maximalRectangle(vector<vector<char>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        vector<int> arr(m, 0);
        int ans = -1e9;

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(matrix[i][j]=='0'){
                    arr[j] = 0;
                }
                else{
                    arr[j] += 1;
                }
            }
            int currArea = largestRectangleArea(arr);
            ans = max(ans, currArea);
        }

        return ans;
    }
};