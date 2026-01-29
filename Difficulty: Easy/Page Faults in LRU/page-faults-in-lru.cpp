class Solution {
public:
    int pageFaults(int N, int C, int pages[]) {
        vector<int> memory;   // stores pages in memory
        int faults = 0;

        for(int i = 0; i < N; i++){
            int page = pages[i];

            // check if page is already in memory
            auto it = find(memory.begin(), memory.end(), page);

            if(it == memory.end()) {
                // page fault
                faults++;

                // if memory full remove LRU page (front)
                if(memory.size() == C) {
                    memory.erase(memory.begin());
                }
            } 
            else {
                // page found → remove it to update recent use
                memory.erase(it);
            }

            // insert current page as most recently used
            memory.push_back(page);
        }

        return faults;
    }
};
