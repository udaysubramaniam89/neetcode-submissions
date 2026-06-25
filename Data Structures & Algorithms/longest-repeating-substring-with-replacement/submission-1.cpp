class Solution {
public:
    int characterReplacement(string s, int k) {

        int left = 0;
        int maxFreq = 0;
        int longestSequence = 0;

        unordered_map<char, int> freqMap;

        for(int right = 0; right < s.size(); right++){
            char currentChar = s[right];
            freqMap[currentChar]++;
            int currentFreq = freqMap[currentChar];
            maxFreq = max(maxFreq, currentFreq);

            while((right - left + 1) - maxFreq > k){
                char leftChar = s[left];
                freqMap[s[left]]--;
                left++;
            }

            int currentSequence = right - left + 1;
            longestSequence = max(currentSequence, longestSequence);
        }
        return longestSequence;
    }
};        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        /*
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
*/
