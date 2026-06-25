class Solution {
public:
    int lengthOfLongestSubstring(string s) {

        int result = 0;
        unordered_set<int> charSet;
        int left = 0;

        for(int right = 0; right < s.size(); right++){
            char currentChar = s[right];

            while(charSet.find(currentChar) != charSet.end()){
                charSet.erase(s[left]);
                left++;
            }

            charSet.insert(currentChar);
            int currentLength = right - left + 1;
            result = max(currentLength, result);
        }
        return result;
    }
};        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        /*
        unordered_set<char> windowCharacters;

        int left = 0;
        int result = 0;
        
        for(int right = 0; right < s.size(); right++){
            char currentCharacter = s[right];

            while(windowCharacters.find(s[right]) != windowCharacters.end()){
                windowCharacters.erase(s[left]);
                left++;
            }
            windowCharacters.insert(s[right]);
            int currentLength = right - left + 1;
            result = max(result, currentLength);
        }
        return result;
    }
};
*/
