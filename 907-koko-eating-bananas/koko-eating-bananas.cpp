long long calTotalHrs(vector<int>& piles, int mid){
    long long totalH = 0;
    int n = piles.size();
    for(int i=0; i<n; i++){
        totalH += ceil((double) piles[i]/(double) mid);
    }
    return totalH;
}

class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int low = 1;
        int high = *max_element(piles.begin(), piles.end());
        
        while(low <= high){
            int mid = (low + high )/2;
            long long totalHrs = calTotalHrs(piles,mid);
            if(totalHrs <= h){
               
                high = mid -1;
            }else{
                low = mid + 1;
            }

        }
        return low;
    }
};