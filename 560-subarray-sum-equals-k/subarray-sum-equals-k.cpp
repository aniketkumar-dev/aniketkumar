class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        map<int,int>mpp;
        mpp[0] = 1;
        int cnt = 0;
        int preSum = 0;
        for(int i=0; i<n; i++){
            preSum = preSum + nums[i];
            int rem = preSum - k;
            if(mpp.find(rem) != mpp.end()){
                cnt += mpp[rem];               
            }
            mpp[preSum] +=1;

        }
        return cnt;
        
    }
};