class Solution {
  public:
    int assignHole(vector<int>& mices, vector<int>& holes) {
        // code here
        sort(mices.begin(), mices.end());
        sort(holes.begin(), holes.end());
        
        int maxTime = INT_MIN;
        
        int i = 0, j = 0;
        while(i < mices.size() && j < holes.size()){
            int time = abs(mices[i] - holes[i]);
            maxTime = max(maxTime, time);
            i++;
            j++;
        }
        return maxTime;
    }
};