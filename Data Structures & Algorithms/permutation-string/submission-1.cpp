class Solution {
public:
    bool checkInclusion(string s1, string s2) {

        if(s1.size() > s2.size()){
            return false;
        }
        
        vector<int> s1Count(26, 0);
        vector<int> s2Count(26, 0);
        
        int left = 0;
        int windowCount = s1.size();

        for(int i = 0; i < windowCount; i++){
            s1Count[s1[i] - 'a']++;
            s2Count[s2[i] - 'a']++;
        }

        if(s1Count == s2Count){
            return true;
        }

        for(int right = windowCount; right < s2.size(); right++){
            
            int left = right - windowCount;
            s2Count[s2[left] - 'a']--;
            s2Count[s2[right] - 'a']++;

            if(s1Count == s2Count){
                return true;
            }
        }
        return false;
    }
};
