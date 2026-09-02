
class Solution {
public:
    int countPairs(vector<int>& nums, int low, int mid, int high) {
        int j = mid + 1;
        int cnt = 0;

        for (int i = low; i <= mid; i++) {
            while (j <= high && (long long)nums[i] > 2LL * nums[j]) {
                j++;
            }
            cnt += j - (mid + 1);
        }

        return cnt;
    }

    void merge(vector<int>& nums, int low, int mid, int high) {
        vector<int> temp;
        int i = low;
        int j = mid + 1;

        while (i <= mid && j <= high) {
            if (nums[i] <= nums[j]) {
                temp.push_back(nums[i++]);
            } else {
                temp.push_back(nums[j++]);
            }
        }

        while (i <= mid) {
            temp.push_back(nums[i++]);
        }

        while (j <= high) {
            temp.push_back(nums[j++]);
        }

        for (int k = low; k <= high; k++) {
            nums[k] = temp[k - low];
        }
    }

    void mergeSort(vector<int>& nums, int low, int high, int& cnt) {
        if (low >= high) return;

        int mid = low + (high - low) / 2;

        mergeSort(nums, low, mid, cnt);
        mergeSort(nums, mid + 1, high, cnt);

        cnt += countPairs(nums, low, mid, high);

        merge(nums, low, mid, high);
    }

    int reversePairs(vector<int>& nums) {
        int n = nums.size();
        int cnt = 0;

        mergeSort(nums, 0, n - 1, cnt);

        return cnt;
    }
};

