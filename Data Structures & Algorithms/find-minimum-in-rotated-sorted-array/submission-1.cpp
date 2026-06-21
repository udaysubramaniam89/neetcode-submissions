class Solution {
public:
    int findMin(vector<int> &nums) {
        int result;
        int left = 0, right = nums.size() - 1;

        while(left < right){
            if(nums[left] <= nums[right]){
                return nums[left];
            }

            else{
                left++;
            }
        }  
    }
};
