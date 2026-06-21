class Solution {
public:
    string minWindow(string s, string t) {
        //unordered_map<char, int> freqStringS;
        unordered_map<char, int> need;
        unordered_map<char, int> wanted;
        
        int left = 0;
        int shortestSubstringLength = INT_MAX;

        //fill up unordered_map for string t
        for(char c : t){
            need[c]++;
        }

        int needCount = need.size();
        int have = 0;
        int resultStart = 0;

        for(int right = 0; right < s.size(); right++){
            
            char rightChar = s[right];

            wanted[rightChar]++;

            if(need.count(rightChar) && (wanted[rightChar] == need[rightChar])){
                have++;
            }

            while(have == needCount){
                
                int resultLength = right - left + 1;
                if(resultLength < shortestSubstringLength){
                    resultStart = left;
                    shortestSubstringLength = resultLength;
                }

                char leftChar = s[left];
                wanted[leftChar]--;

                if(need.count(leftChar) && (wanted[leftChar] < need[leftChar])){
                    have--;
                }
                left++;
            }
        }
        if(shortestSubstringLength == INT_MAX){
            return "";
        }

        else{
            return s.substr(resultStart, shortestSubstringLength);
        }
    }
};
