class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size();
        int n2 = nums2.size();
        vector<vector<int>>ans;
        map<int,int>mpp1,mpp2;
        for(int i=0; i<n1;i++){
            if(mpp1.find(nums1[i]) == mpp1.end()){
            mpp1[nums1[i]]++;
            }
        }

        for(int i=0; i<n2; i++){
            if(mpp2.find(nums2[i]) == mpp2.end()){
            mpp2[nums2[i]]++;
            }
        }
        vector<int>res1;
        for(auto it : mpp1){
            
            if(mpp2.find(it.first) == mpp2.end()){
                res1.push_back(it.first);
            }
        }
        ans.push_back(res1);
         vector<int>res2;
        for(auto it : mpp2){
           
            if(mpp1.find(it.first) == mpp1.end()){
                res2.push_back(it.first);
            }
        }
        ans.push_back(res2);
    return ans;

    }
};