vector<int> findLeftMin(vector<int>& nums, int n){
    vector<int>leftMin(n);
    stack<int>st;
    for(int i=0; i<n; i++){
        while(!st.empty() && nums[st.top()] >= nums[i]){
        st.pop();
        }

        if(st.empty()){
            leftMin[i] = -1;
        } else{
            leftMin[i] = st.top();
        }
        st.push(i);
    }
    return leftMin;

}

vector<int> findRightMin(vector<int>& nums, int n){
    vector<int>rightMin(n);
    stack<int>st;
    for(int i=n-1; i>=0; i--){
        while(!st.empty() && nums[st.top()] > nums[i]){
        st.pop();
        }

        if(st.empty()){
            rightMin[i] = n;
        } else{
            rightMin[i] = st.top();
        }
        st.push(i);
    }
    return rightMin;

}

vector<int> findLeftMax(vector<int>& nums, int n){
    vector<int>leftMax(n);
    stack<int>st;
    for(int i=0; i<n; i++){
        while(!st.empty() && nums[st.top()] <= nums[i]){
        st.pop();
        }

        if(st.empty()){
            leftMax[i] = -1;
        } else{
            leftMax[i] = st.top();
        }
        st.push(i);
    }
    return leftMax;

}

vector<int> findRightMax(vector<int>& nums, int n){
    vector<int>rightMax(n);
    stack<int>st;
    for(int i=n-1; i>=0; i--){
        while(!st.empty() && nums[st.top()] < nums[i]){
        st.pop();
        }

        if(st.empty()){
            rightMax[i] = n;
        } else{
            rightMax[i] = st.top();
        }
        st.push(i);
    }
    return rightMax;

}




class Solution {
public:
    long long subArrayRanges(vector<int>& nums) {
        
        int n = nums.size();
        // min
        vector<int> leftMin = findLeftMin(nums,n);
        vector<int> rightMin = findRightMin(nums,n);

        // max
        vector<int> leftMax = findLeftMax(nums,n);
        vector<int> rightMax = findRightMax(nums,n);

        long long sumMin = 0;
        long long sumMax = 0;
    

        for(int i=0; i< n; i++){
            long long leftCount = i - leftMin[i];
            long long rightCount = rightMin[i] - i;

            long long contributionMin = 1LL * nums[i] * (rightCount * leftCount);
            sumMin = sumMin + contributionMin;

        }

        for(int i=0; i< n; i++){
            long long leftCount = i - leftMax[i];
            long long rightCount = rightMax[i] - i;

            long long contributionMax = 1LL * nums[i] * (rightCount * leftCount);
            sumMax = sumMax + contributionMax;

        }

        return sumMax - sumMin;
        
        
    }
};