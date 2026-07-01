class Solution {
public:
    string minWindow(string s, string t) {
        if(t.size() > s.size()){
            return "";
        }

        unordered_map<char, int> need;
        unordered_map<char, int> current;

        int resultStart = 0, resultLength = 0;
        int left = 0;
        int have = 0;
        int minSubstringLength = INT_MAX;
        string shortestSubstring = "";

        for(char c : t){
            need[c]++;
        }
        int needCount = need.size();

        for(int right = 0; right < s.size(); right++){
            char rightChar = s[right];
            current[rightChar]++;

            if(need[rightChar] && (current[rightChar] == need[rightChar])){
                have++;
            }

            while(have == needCount){
                resultLength = right - left + 1;

                if(resultLength < minSubstringLength){
                    minSubstringLength = resultLength;
                    resultStart = left;
                    shortestSubstring = s.substr(resultStart, resultLength);
                }

                int leftChar = s[left];
                current[leftChar]--;

                if(need[leftChar] && (current[leftChar] < need[leftChar])){
                    have--;
                }

                left++;
            }
        }
        return shortestSubstring;
    }
};
