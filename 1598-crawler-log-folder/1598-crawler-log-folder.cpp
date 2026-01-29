class Solution {
public:
    int minOperations(vector<string>& arr) {
        stack<string> st;

        for(string &s : arr){
            if(s == "../"){
                if(!st.empty()) st.pop();
            }
            else if(s == "./"){
                continue;
            }
            else{
                st.push(s);
            }
        }
        return st.size();
    }
};
