class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>>ans;
        
        for(int i=0; i<numRows; i++){
            vector<int>list;
            long long res = 1;
            list.push_back(res);
            
            for(int j= 0; j<i; j++){
                res = res * (i - j);
                res = res/(j+1);
                list.push_back(res);


            }
            ans.push_back(list);

        }
        return ans;
    }
};