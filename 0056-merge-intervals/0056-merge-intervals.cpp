class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& arr) {
        vector<vector<int>> ans;
        int i = 0, n = arr.size();
        sort(arr.begin(), arr.end());

        // hum pehle vale ke end ko next ke start se compare karte chalenge and jaha bhi pehle ka end <= next start hum merge kar denge 
        for(int i = 0; i<n; i++){
            if(ans.empty() || ans.back()[1] < arr[i][0]){
                ans.push_back(arr[i]);
            } else {
                // overlap
                ans.back()[1] = max(ans.back()[1], arr[i][1]);
            }
        }
        return ans;
    }
};