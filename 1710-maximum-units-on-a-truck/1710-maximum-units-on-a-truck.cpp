class Solution {
public:
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        priority_queue<pair<int, int>> pq; // {unitsPerBox, noOfBoxes}

        for(auto &b : boxTypes){
            pq.push({b[1], b[0]});
        }

        int total = 0;

        while(!pq.empty() && truckSize > 0){
            auto top = pq.top();
            pq.pop();

            int units = top.first;
            int boxes = top.second;

            int take = min(boxes, truckSize);
            total += take * units;
            truckSize -= take;
        }
        return total;
    }
};