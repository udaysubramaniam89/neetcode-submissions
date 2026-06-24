class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        
        unordered_set<int> uSet(nums.begin(), nums.end());
        int result = 0;

        for(int i = 0; i < nums.size(); i++){
            
            int currentNum = nums[i];
            int currentLength = 1;

            if(uSet.find(currentNum - 1) == uSet.end()){
                //good news, no previous value found
                while(uSet.find(currentNum + 1) != uSet.end()){
                    currentNum++;
                    currentLength++;
                }
            }
            result = max(result, currentLength);
        }

        return result;
        
        /* ----- also O(n^2) -----
        unordered_set<int> uSet;
        int result = 0;

        if(nums.size() == 0){
            return 0;
        }

        for(int i = 0; i < nums.size(); i++){
            bool lesserValueFound = true;
            bool greaterValueFound = true;
            int j = 1;
            int currentMaxLength = 1;

            while(lesserValueFound){
                if(uSet.find(nums[i] - j) != uSet.end()){
                    currentMaxLength++;
                }

                else{
                    lesserValueFound = false;
                }

                j++;
                uSet.insert(nums[i]);
            }

            int k = 1;

            while(greaterValueFound){
                if(uSet.find(nums[i] + k) != uSet.end()){
                    currentMaxLength++;
                }

                else{
                    greaterValueFound= false;
                }

                k++;
                uSet.insert(nums[i]);
            }

            result = max(result, currentMaxLength);
        }

        return result;
        */
        
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

        /* ----- proposed solution -----
        unordered_set<int> uSet(nums.begin(), nums.end());

        int result = 0;
        //if(uSet.empty()) return 0;

        for(int num : uSet){
            if(uSet.find(num - 1) != uSet.end()){
                //found a previous number, skip
                continue;
            }

            int currentSequence = 1;
            int currentNumber = num;

            //did not find a previous number.
            //could be start of a chain
            while(uSet.find(currentNumber + 1) != uSet.end()){
                //found (currentNumber + 1), keep going
                currentNumber++;
                currentSequence++;
            }
            result = max(result, currentSequence);
        }
        return result;
        */
    }
};
