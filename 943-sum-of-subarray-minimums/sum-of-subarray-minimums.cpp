vector<int> findLeftMin(vector<int>& arr, int n){
    vector<int> left(n);
    stack<int> st;
    for(int i=0; i<n; i++){
        while(!st.empty() && arr[st.top()] >= arr[i]){
            st.pop();
        }
        if(st.empty()){
            left[i] = -1;
        }else{
            left[i] = st.top();
            
        }
        st.push(i);
    }
    return left;
    

}

vector<int> findRightMin(vector<int>& arr, int n){
    vector<int> right(n);
    stack<int> st;
    for(int i= n-1; i>=0; i--){
        while(!st.empty() && arr[st.top()] > arr[i]){
            st.pop();
        }

        if(st.empty()){
            right[i] = n;
        }else{
            right[i] = st.top();
        }
        st.push(i);
    }
    return right;

}

class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        
        int n = arr.size();
        // right smallest 
        vector<int> left = findLeftMin(arr, n);
        vector<int> right = findRightMin(arr,n);

        long long sum = 0;
        long long mod = 1e9 + 7;
        for(int i=0; i<n; i++){
           long long leftCount  = i - left[i];
           long long rightCount = right[i] - i;

          long long contribution = 1LL * arr[i] * leftCount * rightCount;
          sum = (sum + contribution ) % mod;
        }
         return sum;
        
    }
};