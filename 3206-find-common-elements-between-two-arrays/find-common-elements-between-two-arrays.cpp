class Solution {
public:
    vector<int> findIntersectionValues(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size();
        int n2 = nums2.size();
        int cnt1 = 0;
        int cnt2 = 0;
        map<int,int>mpp1,mpp2;
        for(int i=0; i<n1; i++){
            mpp1[nums1[i]]++;
        }
        for(int i=0; i<n2; i++){
            mpp2[nums2[i]]++;
        }

        for(int i=0; i<n1; i++){
            if(mpp2.find(nums1[i]) != mpp2.end()){
                cnt1++;
            }
        }

        for(int i=0; i<n2; i++){
            if(mpp1.find(nums2[i]) != mpp1.end()){
                cnt2++;
            }
        }
        return {cnt1, cnt2};


        
    }
};