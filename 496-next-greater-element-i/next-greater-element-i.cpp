class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int>ans;
        // map me push kro
        unordered_map<int, int>mpp;
        stack<int>st;
        for(int i=0; i<nums2.size(); i++){
            while(!st.empty() && nums2[i] > st.top()){
                mpp[st.top()] = nums2[i];
                st.pop();

            }
            st.push(nums2[i]);
            
        }

        while(!st.empty()){
            mpp[st.top()] = -1;
            st.pop();

        }

        for(int i=0; i<nums1.size(); i++){
          // map se dhund ke fin kr de 
          ans.push_back(mpp[nums1[i]]);


        }


        return ans;

    }
};