class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> stringFreqMap;

        for(int i = 0; i < strs.size(); i++){
            string nextWord = strs[i];
            sort(nextWord.begin(), nextWord.end());
            stringFreqMap[nextWord].push_back(strs[i]);
        }

        vector<vector<string>> result;

        for(auto const& entry : stringFreqMap){
            result.push_back(entry.second);
        }

        return result;
    }
};
