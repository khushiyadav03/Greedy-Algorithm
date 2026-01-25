class Solution {
public:
    bool canJump(vector<int>& nums) {
        int maxRange = 0;
        for(int i = 0; i<nums.size(); i++){
            if(i > maxRange) return false;

            int range = i + nums[i];
            if(maxRange < range){
                maxRange = range;
            }

            if(maxRange >= nums.size() - 1){
                return true;
            }
        }

        return false;
    }
};