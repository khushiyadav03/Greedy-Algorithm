// User function Template for C++

class Solution {
  public:
    int rotationCount(long long R, long long D) {
        // code here
        int ans = 0;
        int fir, sec;
        
        while(R){
            fir = R % 10;
            sec = D % 10;
            R /= 10;
            D /= 10;
            
            ans += min(abs(fir - sec), 10 - abs(fir - sec));
        }
        
        return ans;
    }
};