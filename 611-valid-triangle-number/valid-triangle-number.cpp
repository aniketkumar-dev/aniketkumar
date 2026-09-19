class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;

        sort(nums.begin(), nums.end());

        for (int k = n - 1; k >= 2; k--) {
            int i = 0;
            int j = k - 1;

            while (i < j) {
                if (nums[i] + nums[j] > nums[k]) {
                    // i se j-1 tak sabke saath triangle banega
                    ans += j - i;
                    j--;
                } else {
                    i++;
                }
            }
        }

        return ans;
    }
};