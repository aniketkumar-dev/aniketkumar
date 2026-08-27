class Solution {
public:
    int majorityElement(vector<int>& nums) {
        
        int n = nums.size();
        int cand = nums[0];
        int cnt = 1;
        for(int i=1; i<n;i++){
            if(nums[i] == cand){
                cnt++;
            }else{
                cnt--;
            }

            if(cnt == 0 || cnt < 0){
                cand = nums[i];
                cnt = 1;
            }
           

        }
        int ans = 0;
            for(int i=0; i<n; i++){
                if(nums[i] == cand) ans++;
            }
            if(ans > n/2) return cand;
        return -1;
    }
};