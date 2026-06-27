class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int searchIndex = 0;

        for(vector<int>& entry : matrix){
            if (target > entry.back()){
                continue;
            }

            int left = 0;
            int right = entry.size() - 1;

            while(left <= right){
                int mid = left + ((right - left)/2);
                if(target == entry[mid]){
                    return true;
                }

                else if(entry[mid] < target){
                    left = mid + 1;
                }

                else{
                    right = mid - 1;
                }
            }
            return false;

            /*
            for(int i = 0; i < entry.size(); i++){
                if(target == entry[i]){
                    return true;
                }
            }
            return false;
            */
        }
        return false;       
    }
};
