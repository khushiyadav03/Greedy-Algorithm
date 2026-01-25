class Solution {
  public:
    int findMin(int N) {
        int curr[] = {10, 5, 2, 1};
        int i = 0;
        int count = 0;

        while (N > 0 && i < 10) {
            count += N / curr[i];
            N %= curr[i];
            i++;
        }

        return count;
    }
};
