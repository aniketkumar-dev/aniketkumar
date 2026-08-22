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
    for(int i= n-1; i>=0; i--){
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


int largestRectangle (vector<int>& heights){
    int n = heights.size();
    int ans = 0;
    vector<int>left = findLeftMin(heights,n);
    vector<int>right = findRightMin(heights, n);

    for(int i=0; i<n; i++){
        int width = right[i] - left[i] - 1;
        int areaCurr = heights[i] * width;
        ans = max(ans, areaCurr);
    }
    return ans;


}
class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        int n = matrix.size();   // row
        int m = matrix[0].size();   // col
        vector<vector<int>>pSum(n, vector<int>(m));

        for(int j=0; j<m; j++){
            int sum = 0;
            for(int i=0; i<n; i++){              

                if(matrix[i][j] == '0'){
                    sum = 0;
                }else{
                    sum++;
                }
                pSum[i][j] = sum;
                
            }
        }

        int maxAns = 0;
        for(int i=0; i<n; i++){
            // rectangualar waha concept use kre
            
            int area = largestRectangle(pSum[i]);

             maxAns = max( maxAns, area);

            

        }
        return maxAns;
        
    }
};