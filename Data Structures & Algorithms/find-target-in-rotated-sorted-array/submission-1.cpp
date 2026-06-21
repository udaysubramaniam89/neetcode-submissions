class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left = 0, right = nums.size() - 1;

        while(left <= right){
            //trivial case: target == nums[left] or target == nums[right]
            if(target == nums[left]){
                return left;
            }else if(target == nums[right]){
                return right;
            }
            //case 1: target > nums[left]
            else if(target > nums[left]){
                left++;
            }
            //case 2: target < nums[right]
            else if(target < nums[right]){
                right--;
            }
            else{
                break;
            }
        }
        //not found
        return -1;   
    }
};
