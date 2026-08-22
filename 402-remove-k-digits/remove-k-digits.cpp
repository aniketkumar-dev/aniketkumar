class Solution {
public:
    string removeKdigits(string num, int k) {

        stack<char> st;
        int n = num.size();

        for(int i = 0; i < n; i++){

            while(!st.empty() && k > 0 &&
                  (st.top() - '0') > (num[i] - '0')) {

                st.pop();
                k--;
            }

            st.push(num[i]);
        }

        // Agar abhi bhi k digits remove karne hain
        while(k > 0 && !st.empty()){
            st.pop();
            k--;
        }

        if(st.empty())
            return "0";

        string res = "";

        while(!st.empty()){
            res += st.top();
            st.pop();
        }

        reverse(res.begin(), res.end());

        // Leading zeros remove
        int i = 0;

        while(i < res.size() && res[i] == '0'){
            i++;
        }

        res = res.substr(i); // ye important hai

        if(res.empty())
            return "0";

        return res;
    }
};