class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int searchIndex = 0;

        for(vector<int>& entry : matrix){
            if (target > entry.back()){
                continue;
            }

            else{
                for(int i = 0; i < entry.size(); i++){
                    if(target == entry[i]){
                        return true;
                    }
                }
                return false;
            }
        }
        return false;       
    }
};
