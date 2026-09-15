class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        int sum = 0;
        
        map<int,int>mpp;
        mpp[0] = -1;
        
        for(int i=0; i<n; i++){
            sum = sum + nums[i];
            int rem =  (sum % k);
            if(mpp.find(rem) != mpp.end()){
                if(i - mpp[rem] >= 2){
                return true;
                }
            }else{
                
                mpp.insert({rem, i});
            
            }
            
        }
        return false;
        
    }
};