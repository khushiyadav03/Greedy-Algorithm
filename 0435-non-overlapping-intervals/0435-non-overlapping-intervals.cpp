class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& arr) {
        // agr start ya end kisi bhi interval ke beech me aa rha h toh vo remove karenge hum
        if(arr.empty()) return 0;
        sort(arr.begin(), arr.end(), [](vector<int>& a, vector<int>& b){
            return a[1] < b[1];
        });
        int prevEnd = arr[0][1], n = arr.size(), count = 0;
        for(int i = 1; i<n; i++){
            if(arr[i][0] < prevEnd){
                count++;
            } else {
                prevEnd = arr[i][1];
            }
        }
        return count;
    }
};