class Solution {
public:
    vector<int> getOrder(vector<vector<int>>& tasks) {

        int n = tasks.size();
        vector<int> ans;

        // add original index
        for(int i = 0; i < n; i++){
            tasks[i].push_back(i);
        }

        // sort by enqueue time
        sort(tasks.begin(), tasks.end());

        long long timer = tasks[0][0];
        int i = 0;

        // min heap: {processingTime, index}
        priority_queue<
            pair<int,int>,
            vector<pair<int,int>>,
            greater<pair<int,int>>
        > pq;

        while(!pq.empty() || i < n){

            // push all tasks available at current time
            while(i < n && tasks[i][0] <= timer){
                pq.push({tasks[i][1], tasks[i][2]});
                i++;
            }

            if(pq.empty()){
                // CPU idle → jump time
                timer = tasks[i][0];
            } else {
                auto curr = pq.top();
                pq.pop();

                ans.push_back(curr.second);
                timer += curr.first;
            }
        }

        return ans;
    }
};
