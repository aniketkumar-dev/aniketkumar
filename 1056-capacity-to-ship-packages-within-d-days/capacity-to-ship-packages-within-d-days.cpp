int totalCapicity(vector<int>& weights, int mid){
    int n = weights.size();
    int load = 0;
    int days = 1;
    for(int i=0; i<n; i++){
        if(weights[i] + load > mid){
            days += 1;
            load = weights[i];
        }else{
            load += weights[i];
        }
    }
    return days;
}


class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int low = *max_element(weights.begin(), weights.end());
        int high = accumulate(weights.begin(), weights.end(), 0);
        while(low <= high){
            int mid = (low + high)/2;
           int nuOfDays = totalCapicity(weights, mid);
           if(nuOfDays <= days){
            high = mid - 1;
           }else {
            low = mid + 1;
           }

        }
        return low;
        
    }
};