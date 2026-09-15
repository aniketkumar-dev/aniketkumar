class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
       int preMax = INT_MIN;
       int sufMax = INT_MIN;
       int prefix = 1;
       int suffix = 1;
        
        
        // prefix and suffix observation
        
        for(int i=0; i<n; i++){
            prefix = prefix * nums[i];

            preMax = max(preMax, prefix);
            if(prefix == 0) prefix = 1;           


        }
        for(int i= n-1; i>=0; i--){
            suffix = suffix * nums[i];
            sufMax = max(sufMax,suffix );
            if(suffix == 0) suffix = 1;
        }
        int ans = max(preMax, sufMax);
        return ans;

        
        
    }
};