int missingNumber(vector<vector<int>>& grid, int n){
    long long sum = 0;
    long long expectedSum = 0;
    long long N = 1LL *n*n;
    
     expectedSum = (N*(N+1))/2;  

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            sum += grid[i][j];
        }
    }
    int output = expectedSum - sum;
    return output;
}

int repeatedNumber(vector<vector<int>>& grid, int n){
    int ans = 0;
    int N = n*n;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            ans = ans ^ grid[i][j];
        }
    }
    for(int i=1; i<=N; i++){
        ans = ans ^ i;
    }
    
   // ans = repeated ^ missing
   int bit = ans & (-ans);
   int x = 0;
   int y =0;
   for(int i=0; i<n; i++){
    for(int j=0; j<n; j++){
        if(grid[i][j] & bit){
            x = x ^ grid[i][j];
        }else{
            y = y ^ grid[i][j];
        }

    }

   }


    for(int i = 1; i <= N; i++){
        if(i & bit)
            x = x ^ i;
        else
            y = y ^ i;
    }

    // x/y mein se ek repeated hai
    int diff = missingNumber(grid, n);

    if(x - y == diff)
        return y;
    else
        return x;

   

}
class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        int n = grid.size();
        int repeat = repeatedNumber(grid, n);
        int miss = missingNumber(grid,n);
        int missing = miss + repeat;
        return {repeat, missing};
    }
};