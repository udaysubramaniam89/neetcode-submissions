class Solution {
public:
    string minWindow(string s, string t) {

        if(t.size() > s.size()){
            return "";
        }
        
        unordered_map<char, int> need;
        unordered_map<char, int> wanted;

        int resultStart = 0, resultLength = 0;
        int left = 0;
        int have = 0;
        int shortestSubstringLength = INT_MAX;

        for(char c : t){
            need[c]++;
        }

        int needCount = need.size();

        for(int right = 0; right < s.size(); right++){

            char rightChar = s[right];
            wanted[rightChar]++;

            if(need.count(rightChar) && (wanted[rightChar] == need[rightChar])){
                have++;
            }

            while(have == needCount){
                resultLength = right - left + 1;
                
                if(resultLength < shortestSubstringLength){
                    shortestSubstringLength = min(shortestSubstringLength, resultLength);
                    resultStart = left;
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
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        /*
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
*/
