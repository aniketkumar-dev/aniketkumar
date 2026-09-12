class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int n = nums.size();
        int sum = 0;
        for(int i=0; i<n; i++){
            sum += nums[i];
        }
        int pivotSum = 0;
        for(int i=0; i<n; i++){
            
            if(pivotSum == (sum - pivotSum - nums[i])){
                return i;
            }else{
                pivotSum += nums[i];
            }
        }
        return -1;
        
    }
};