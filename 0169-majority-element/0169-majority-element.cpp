class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int cand = nums[0];
        int votes = 1;
        for(int i = 1; i<nums.size(); i++){
            votes += (nums[i] == cand) ? 1 : -1;
            if(votes < 0){
                cand = nums[i];
                votes = 1;
            }
        }
        return cand;
    }
};