class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        for(int i = 0; i<s.size(); i++){
            char currChar = s[i];
            if(currChar == '(' || currChar == '{' || currChar == '['){
                st.push(currChar);
            } else {
                if(st.empty()) return false;

                if((st.top() == '{' && currChar == '}') ||
                    (st.top() == '[' && currChar == ']') ||
                    (st.top() == '(' && currChar == ')') ){
                        st.pop();
                } else {
                    return false;
                }
            }
        }

        return st.empty();
    }
};