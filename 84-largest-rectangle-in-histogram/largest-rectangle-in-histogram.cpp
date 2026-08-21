vector<int> findLeftMin(vector<int>& heights, int n){
    vector<int>left(n);
    stack<int> st;
    for(int i=0; i<n; i++){
        while(!st.empty() && heights[st.top()] >= heights[i]){
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

vector<int> findRightMin(vector<int>& heights, int n){
    vector<int>right(n);
    stack<int> st;
    for(int i=n-1; i>=0; i--){
        while(!st.empty() && heights[st.top()] > heights[i]){
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
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        vector<int> leftMin = findLeftMin(heights, n);
        vector<int> rightMin = findRightMin(heights, n);

        long long sum = 0;
        for(int i=0; i<n; i++){
            long long leftCount = i - leftMin[i];
            long long rightCount = rightMin[i] - i;

            long long contribution = 1LL * heights[i] * 
            (rightCount + leftCount - 1);
            sum = max(sum, contribution);

        }
        return sum;
        
    }
};