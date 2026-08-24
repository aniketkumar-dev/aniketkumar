class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        map<int,int>mpp;
        for(int i=0; i<n; i++){
            mpp[nums[i]]++;
        }

        int j = 0;
        for(auto it : mpp){
            nums[j] = it.first;
            j++;
            
        }
        return j;
        
    }
};