class Solution {
public:
    int maxSumDivThree(vector<int>& nums) {
        int sum = 0;

        // smallest two numbers with remainder 1
        int x1 = INT_MAX, x2 = INT_MAX;
        // smallest two numbers with remainder 2
        int y1 = INT_MAX, y2 = INT_MAX;

        for (int i = 0; i < nums.size(); i++) {
            sum += nums[i];

            if (nums[i] % 3 == 1) {
                if (nums[i] < x1) {
                    x2 = x1;
                    x1 = nums[i];
                } else if (nums[i] < x2) {
                    x2 = nums[i];
                }
            }
            else if (nums[i] % 3 == 2) {
                if (nums[i] < y1) {
                    y2 = y1;
                    y1 = nums[i];
                } else if (nums[i] < y2) {
                    y2 = nums[i];
                }
            }
        }

        if (sum % 3 == 0) return sum;

        if (sum % 3 == 1) {
            int remove1 = x1;
            int remove2 = (y1 != INT_MAX && y2 != INT_MAX) ? y1 + y2 : INT_MAX;
            int rem = min(remove1, remove2);
            return rem == INT_MAX ? 0 : sum - rem;
        }

        // sum % 3 == 2
        int remove1 = y1;
        int remove2 = (x1 != INT_MAX && x2 != INT_MAX) ? x1 + x2 : INT_MAX;
        int rem = min(remove1, remove2);
        return rem == INT_MAX ? 0 : sum - rem;
    }
};
