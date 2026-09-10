class Solution {
public:
    bool possible(vector<int>& nums, int k, long long mid) {
        long long sum = 0;
        int count = 1;

        for(int i = 0; i < nums.size(); i++) {
            if(sum + nums[i] <= mid) {
                sum += nums[i];
            }
            else {
                count++;
                sum = nums[i];
            }
        }

        return count <= k;
    }

    int splitArray(vector<int>& nums, int k) {
        long long low = 0;
        long long high = 0;

        for(int i = 0; i < nums.size(); i++) {
            low = max(low, (long long)nums[i]);
            high += nums[i];
        }

        while(low <= high) {
            long long mid = low + (high - low) / 2;

            if(possible(nums, k, mid)) {
                high = mid - 1;
            }
            else {
                low = mid + 1;
            }
        }

        return low;
    }
};