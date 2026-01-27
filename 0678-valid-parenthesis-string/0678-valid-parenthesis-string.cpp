class Solution {
public:
    bool checkValidString(string s) {
        // agr '(' h to ')' hona hi chahiye
        // are ')' h toh pehle '(' hona hi chahiye
        // '*' = '(' or ')' both ways can be used

        // track min and max open brackets
        int minOpen = 0, maxOpen = 0;

        // traverse each char in string
        for(char c : s){
            if(c == '('){
                minOpen++;
                maxOpen++;
            } else if (c == ')'){
                minOpen--;
                maxOpen--;
            } else {
                minOpen--;
                maxOpen++;
            }

            if(maxOpen < 0) return false;

            minOpen = max(minOpen, 0);
        }

        return minOpen == 0;
    }
};