class Solution {
public:
    vector<int> findIndices(vector<int>& nums, int indexDifference, int valueDifference) {
        int n = nums.size();

        int i = 0;                 // left pointer
        int minIdx = 0, maxIdx = 0;

        for (int j = indexDifference; j < n; j++) {
            // move left pointer to maintain indexDifference
            i = j - indexDifference;

            // update min and max candidates
            if (nums[i] < nums[minIdx]) minIdx = i;
            if (nums[i] > nums[maxIdx]) maxIdx = i;

            // check conditions
            if (abs(nums[j] - nums[minIdx]) >= valueDifference)
                return {minIdx, j};

            if (abs(nums[j] - nums[maxIdx]) >= valueDifference)
                return {maxIdx, j};
        }

        return {-1, -1};
    }
};
