// User function Template for C++

//Back-end complete function Template for C++

class Solution {
  public:
    long long solve(vector<int>& bt) {
        sort(bt.begin(), bt.end());
        long long wt = 0, curr = 0;
        for(int i = 0; i<bt.size(); i++){
            wt += curr;
            curr += bt[i];
        }
        return wt / bt.size();
    }
};