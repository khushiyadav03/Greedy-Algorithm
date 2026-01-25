bool comp(pair<int,int> a, pair<int,int> b){
    return a.second > b.second;   // profit descending
}

class Solution {
  public:
    vector<int> parent;

    int find(int x){
        if(parent[x] == x)
            return x;
        return parent[x] = find(parent[x]); // path compression
    }

    vector<int> jobSequencing(vector<int> &deadline, vector<int> &profit) {

        int n = deadline.size();
        vector<pair<int,int>> job;

        for(int i = 0; i < n; i++){
            job.push_back({deadline[i], profit[i]});
        }

        sort(job.begin(), job.end(), comp);

        int maxDead = 0;
        for(auto &j : job)
            maxDead = max(maxDead, j.first);

        // DSU initialization
        parent.resize(maxDead + 1);
        for(int i = 0; i <= maxDead; i++)
            parent[i] = i;

        int count = 0, totalProfit = 0;

        for(auto &j : job){
            int availableSlot = find(j.first);
            if(availableSlot > 0){
                count++;
                totalProfit += j.second;
                parent[availableSlot] = find(availableSlot - 1);
            }
        }

        return {count, totalProfit};
    }
};
