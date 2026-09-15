class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int>ans;
        
        long long prod = 1;
        for(int i=0; i<n; i++){
            if(nums[i] != 0){
            prod = prod * nums[i];
            }
        }
        vector<int>temp;
        for(int i=0; i<n; i++){
            if(nums[i] == 0){
                temp.push_back(i);
            }
        }

        for(int i=0; i<n; i++){
            if(temp.size() >= 2){
                ans.push_back(0);
            }else if (temp.size() == 0){
                ans.push_back(prod / nums[i]);
            }else{
                if(i == temp[0]){
                    ans.push_back(prod);
                }else{
                    ans.push_back(0);
                }
            }

            
        }
        return ans;


        
    }
};