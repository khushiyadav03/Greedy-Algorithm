class Solution {
  public:
    vector<int> minMaxCandy(vector<int>& prices, int k) {
        sort(prices.begin(), prices.end());
        vector<int> ans;
        int fir = 0, sec = 0;
        
        int i = 0, j = prices.size() - 1;
        
        while(i <= j){
            fir += prices[i];
            i++;
            j -= k;
        }
        
        i = prices.size() - 1, j = 0;
        
        while(i >= j){
            sec += prices[i];
            i--;
            j += k;
        }
        
        return {fir, sec};
    }
};