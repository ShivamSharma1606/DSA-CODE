/*
3211
You are given a positive integer n.

A binary string x is valid if all substrings of x of length 2 contain at least one "1".

Return all valid strings with length n, in any order.

*/

class Solution {
public:
    // checking binary string(brute force approach)
    /*
    bool check(string s){
        int n = s.size();
        int i = 1;
        while(i < n){
            if(s[i] == '0' && s[i - 1] == '0'){
                return false;
            }
            i++;
        }
        return true;
    }*/

    // Creating all the substrings
    void sub(int n, string& s, vector<string>& ans) {

        if (n == 0) {
            ans.push_back(s);
            return;
        }

        // inserting the "1"
        s += '1';
        sub(n - 1, s, ans);
        s.pop_back();

        // inserting the "0"
        if (s.empty() || s.back() != '0') {
            s += '0';
            sub(n - 1, s, ans);
            s.pop_back();
        }
    }

    vector<string> validStrings(int n) {
        if (n == 1) {
            return {"0", "1"};
        }

        vector<string> ans;
        string s = "";
        sub(n, s, ans);
        return ans;
    }
};