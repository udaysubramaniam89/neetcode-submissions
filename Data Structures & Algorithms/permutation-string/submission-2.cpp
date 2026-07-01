class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if(s1.size() > s2.size()){
            return false;
        }
        
        vector<int> s1count(26, 0);
        vector<int> s2count(26, 0);

        for(int i = 0; i < s1.size(); i++){
            s1count[s1[i] - 'a']++;
            s2count[s2[i] - 'a']++;
        }

        if(s1count == s2count){
            return true;
        }

        int keyCount = s1.size();
        int windowCount = s2.size();

        for(int right = keyCount; right < windowCount; right++){
            int left = right - keyCount;
            s2count[s2[left] - 'a']--;
            s2count[s2[right] - 'a']++;

            if(s1count == s2count){
                return true;
            }
        }
        return false;
    }
};
