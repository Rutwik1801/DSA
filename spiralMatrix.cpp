
    vector<int> spiralOrder(vector<vector<int>>& arr) {
        int count=0;
        int total=(arr.size()*arr[0].size());
        vector<int> ans;
        int stRow=0,stCol=0,endRow=arr.size()-1,endCol=arr[0].size()-1;
        while(count<total){
            for(int i=stCol;count<total && i<=endCol;i++){
                ans.push_back(arr[stRow][i]);
                count++;
            }
            stRow++;
            for(int i=stRow;count<total && i<=endRow;i++){
                ans.push_back(arr[i][endCol]);
                count++;
            }
            endCol--;
            for(int i=endCol;count<total && i>=stCol;i--){
                ans.push_back(arr[endRow][i]);
                count++;
            }
            endRow--;
            for(int i=endRow;count<total&& i>=stRow;i--){
                ans.push_back(arr[i][stCol]);
                count++;
            }
            stCol++;
        }
        return ans;
    }