class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        
        unordered_map<int,int>mpp;
       
        
        for(int j =0; j<n; j++){
           int resTar =  target - nums[j];

           // resTar ko find karege mpp me agaar mil gya to index of j 
           // and resTar ka index ko ans me push kr ke return kr denge 
           // or nhi mila to i++ kar denge 

           auto it = mpp.find(resTar);
           if(it != mpp.end()){
            
            return {it->second, j};
            
           }
           mpp[nums[j]] = j;
           
        }
        return {};
        
        
    }
};