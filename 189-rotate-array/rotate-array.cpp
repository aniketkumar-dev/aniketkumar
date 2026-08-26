class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        k = k % n;
        int m = n-k;
        
        // temp me store kr diye 
        vector<int> temp(k);
        for(int i=0; i<k; i++){
            temp[i] = nums[m];
            m++;
        }

        for(int i= n-1; i>=k; i--){
            nums[i] = nums[i-k];
        }

       int  j=0;
       for(int i= 0; i<k; i++){
          nums[i] = temp[j];
          j++;
       }
       return;
        
    }
};