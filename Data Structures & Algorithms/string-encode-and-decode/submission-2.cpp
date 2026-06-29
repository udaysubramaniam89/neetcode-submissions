class Solution {
public:

    string encode(vector<string>& strs) {
        string encoded;

        for(const string& word : strs){
            string wordLength = to_string(word.length());
            encoded += wordLength;
            encoded += '#';
            encoded += word;
        }
        return encoded;
    }

    vector<string> decode(string s) {
        vector<string> result;

        int i = 0;
        while(i < s.length()){
            int j = i;
            while(s[j] != '#'){
                j++;
            }

            int wordSize = stoi(s.substr(i, j - i));
            i = j + 1;
            int wordStart = i;

            result.push_back(s.substr(wordStart, wordSize));
            i = wordStart + wordSize;
        }
        return result;
    }
};
