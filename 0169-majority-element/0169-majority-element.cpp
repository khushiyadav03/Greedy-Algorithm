class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int, int> freq;
        int maxFre = 0;
        int maxCandidate = nums[0];
        for(int n : nums){
            freq[n]++;
            if(freq[n] > maxFre){
                maxFre = freq[n];
                maxCandidate = n;
            }
        }
        return maxCandidate;
    }
};