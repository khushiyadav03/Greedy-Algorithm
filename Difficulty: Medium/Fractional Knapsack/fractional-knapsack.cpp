struct Item {
    int value;
    int weight;
};

// comparator: sort by value/weight descending
bool comp(Item a, Item b) {
    return (double)a.value / a.weight > (double)b.value / b.weight;
}

class Solution {
  public:
    double fractionalKnapsack(vector<int>& val, vector<int>& wt, int capacity) {
        int n = val.size();
        vector<Item> arr(n);

        // build items
        for (int i = 0; i < n; i++) {
            arr[i] = {val[i], wt[i]};
        }

        // sort by value/weight ratio
        sort(arr.begin(), arr.end(), comp);

        double profit = 0.0;
        int w = capacity;

        for (int i = 0; i < n && w > 0; i++) {
            if (arr[i].weight <= w) {
                // take whole item
                profit += arr[i].value;
                w -= arr[i].weight;
            } else {
                // take fractional part
                profit += ((double)arr[i].value / arr[i].weight) * w;
                w = 0;
            }
        }

        return profit;
    }
};
