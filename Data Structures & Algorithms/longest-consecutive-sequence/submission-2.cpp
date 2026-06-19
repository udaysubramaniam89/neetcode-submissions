class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        /* Greater than O(n) 
        int result = 1;

        sort(nums.begin(), nums.end());
        for(int i = 1; i < nums.size(); i++){
            if(nums[i] == nums[i-1]){
                continue;
            }

            if(nums[i] - nums[i-1] > 1){
                break;
            }

            if(nums[i] - nums[i-1] == 1){
                result++;
            }
        }
        return result;
        */

        int result = 1;

        unordered_set<int> uSet(nums.begin(), nums.end());

        if(uSet.empty()) return 0;

        for(int num : uSet){
            int currentSequence = 1;
            int currentNumber = num;
            
            //int currentNumber = uSet[i];
            if(uSet.find(currentNumber - 1) != uSet.end()){
                //found a previous number, skip
                continue;
            }

            else{
                //did not find a previous number.
                //could be start of a chain
                while(uSet.find(currentNumber + 1) != uSet.end()){
                    //found currentNumber + 1, keep going
                    currentNumber++;
                    currentSequence++;
                }
            }
            result = max(result, currentSequence);
        }
        return result;
    }
};
