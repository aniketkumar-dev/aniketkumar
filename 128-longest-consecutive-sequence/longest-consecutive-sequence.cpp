class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();

        int ans = 0;
        if(nums.empty()) return 0;

        unordered_set<int> st;
        st.reserve(n * 2);

        for(int x : nums){
            st.insert(x);
        }

        for(int first : st){

            if(first != INT_MIN && st.find(first - 1) == st.end()) {

                int x = first;
                int cnt = 1;

                while(x != INT_MAX && st.find(x + 1) != st.end()){
                    cnt++;
                    x++;
                }

                ans = max(ans, cnt);
            }
        }

        return ans;
    }
};