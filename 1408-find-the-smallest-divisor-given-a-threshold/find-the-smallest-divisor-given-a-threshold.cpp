long long findDivisor(vector<int>& nums,  int mid){
    int n = nums.size();
    long long sum = 0;
    for(int i=0; i<n; i++){
        sum += ceil((double)nums[i] / mid);

    }
    return sum;
}

class Solution {
public:
    int smallestDivisor(vector<int>& nums, int threshold) {
        int low = 1;
        int high = *max_element(nums.begin(),nums.end());
        while(low <= high){
            int mid = (low + high)/2;

           long long ans =  findDivisor(nums,mid);
           if(ans <= threshold){
            // agar an se km hai to. store kr lenge 
            high = mid - 1;

           }else{
            low = mid +1;
           }
        }
        
        return low;
    }
};