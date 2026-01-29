class Solution {
public:
    void recursiveF(int op, int cl, string s, vector<string>& ans){
        if(op == 0 && cl == 0){
            ans.push_back(s);
            return;
        }

        if(op > 0){
            recursiveF(op - 1, cl, s + "(", ans);
        }

        if(cl > op){
            recursiveF(op, cl - 1, s + ")", ans);
        }
    }

    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        recursiveF(n, n, "", ans);
        return ans;
    }
};
