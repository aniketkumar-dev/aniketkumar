class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        
        map<int,int>mpp;
        for(int i=0; i<n; i++){
        
        int a = nums[i];
        int more = target - a ;
        if(mpp.find(more) != mpp.end()){
            return { i, mpp[more]};
        }else{
            mpp[nums[i]] = i;
        }
        
        }
        return {-1};       
           
       
        
    }
};