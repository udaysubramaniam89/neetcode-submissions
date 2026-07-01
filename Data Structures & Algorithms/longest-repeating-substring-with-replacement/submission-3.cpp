class Solution {
public:
    int characterReplacement(string s, int k) {
        unordered_map<char, int> charFreqMap;

        int left = 0;
        int longestSequence = 0;
        int maxFreq = 0;

        for(int right = 0; right < s.size(); right++){
            char rightChar = s[right];
            charFreqMap[rightChar]++;

            int currentFrequency = charFreqMap[rightChar];
            maxFreq = max(maxFreq, currentFrequency);

            while((right - left + 1) - maxFreq > k){
                char leftChar = s[left];
                charFreqMap[leftChar]--;
                left++;
            }
            longestSequence = max(longestSequence, right - left + 1);
        }
        return longestSequence;
    }
};
