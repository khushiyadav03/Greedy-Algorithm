class Solution {
public:
    int jump(vector<int>& nums) {
        int jumps = 0;
        int maxReach = 0; // next jump me yaha tak pohoch sakte ho
        int currEnd = 0; // is jump me yaha tak pohoch sakte h 

        for(int i = 0; i < nums.size() - 1; i++){
            maxReach = max(maxReach, i +  nums[i]);

            if(i == currEnd) { // iska mtlb h ki curr jump ki range khatam ho gyi h 
                jumps++; 
                currEnd = maxReach;
            }
        }

        return jumps;
    }
};