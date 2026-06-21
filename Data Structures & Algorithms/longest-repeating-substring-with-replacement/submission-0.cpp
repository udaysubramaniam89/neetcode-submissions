class Solution {
public:
    int characterReplacement(string s, int k) {
        int left = 0;
        int maxFreq = 0;
        int longestCharSequence = 0;

        unordered_map<char, int> freq;
        for(int right = 0; right < s.size(); right++){
            char rightChar = s[right];
            freq[rightChar]++;
            int currentFrequency = freq[rightChar];

            maxFreq = max(maxFreq, currentFrequency);
            while((right - left + 1) - maxFreq > k){
                char leftChar = s[left];
                freq[leftChar]--;
                left++;
            }
            longestCharSequence = max(longestCharSequence, right - left + 1);
       }
       return longestCharSequence;
    }
};
