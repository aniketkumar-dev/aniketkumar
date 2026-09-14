class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int n = nums.size();
        vector<int>ans(n);
        
        
        int i=0;
        int j= n-1;
        int k = n-1;
        while(i <= j){
            int first = abs(nums[i]);
            int second = abs(nums[j]);
            
            if(first < second){
                 ans[k] = second * second;
                j--;
            }else{
                 ans[k] = first * first;
                i++;
            }
            k--;
        }
        return ans;
        
        
    }
};