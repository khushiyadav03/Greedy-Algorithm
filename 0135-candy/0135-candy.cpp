class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();

        // initialize candies array with 1
        vector<int> arr(n, 1);

        // left to right pass
        for (int i = 1; i < n; i++) {
            if (ratings[i] > ratings[i - 1]) {
                arr[i] = arr[i - 1] + 1;
            }
        }

        // right to left pass
        for (int i = n - 2; i >= 0; i--) {
            if (ratings[i] > ratings[i + 1]) {
                arr[i] = max(arr[i], arr[i + 1] + 1);
            }
        }

        // sum all candies
        int sum = 0;
        for (int x : arr) {
            sum += x;
        }

        return sum;
    }
};
