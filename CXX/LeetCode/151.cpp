class Solution {
public:
    string reverseWords(string s) {
        vector <string> ans;
        string tmp;
        string str = "";
        int i, n;
        n = s.size();
        for (i = 0; i < n; i++) {
            tmp = "";
            while (i < n && s[i] != ' ') {
                tmp += s[i];
                i++;
            }
            if (tmp != "") {
                ans.push_back(tmp);
            }
        }

        i = 0;
        n = ans.size() - 1;
        while (i < n - i) {
            swap(ans[i], ans[n - i]);
            i++;
        }
        
        if (ans.size())
            str = ans[0];
        for (i = 1; i < ans.size(); i++) {
            str += " " + ans[i];
        }
        return str;
    }
};