class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size() == 0){
            return 0;
        }

        if(nums.size() == 1){
            return 1;
        }
        
        int longestSequence = 1;
        unordered_set<int> numSet;

        sort(nums.begin(), nums.end());
        for(int num : nums){
            numSet.insert(num);
        }

        for(int i = 0; i < nums.size(); i++){
            int currentSequence = 0;
            int newNum = nums[i];
            while(numSet.find(newNum) != numSet.end()){
                currentSequence++;
                newNum++;
            }
            longestSequence = max(longestSequence, currentSequence);
        }
        return longestSequence;
    }
};
