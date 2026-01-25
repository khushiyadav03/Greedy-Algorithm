bool comp(pair<int, int>a, pair<int, int>b){
    return a.second < b.second; // previous end < next start
}

class Solution {
  public:
    // Function to find the maximum number of meetings that can
    // be performed in a meeting room.
    int maxMeetings(vector<int>& start, vector<int>& end) {
        // Your code here
        // pehle start and end ke pairs banayenge
        vector<pair<int, int>> timer;
        int n = start.size();
        
        for(int i = 0; i<n; i++){
            timer.push_back({start[i], end[i]});
        }
        
        // sort karenge end time ke basis pe
        sort(timer.begin(), timer.end(), comp);
        
        int total = 0;
        int ending = -1;
        
        for(int i = 0; i<n; i++){
            if(timer[i].first > ending){
                total++;
                ending = timer[i].second;
            }
        }
        
        return total;
    }
};