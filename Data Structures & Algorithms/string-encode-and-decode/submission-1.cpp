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
            int wordStart = j + 1;

            string nextWord = s.substr(wordStart, wordSize);
            result.push_back(nextWord);
            i = wordStart + wordSize;
        }
        return result;
    }
};




    
    
    
    
    
    
    
    
    
    
    
    
    
    
    /*
    string encode(vector<string>& strs) {
        string encoded;

        for(const string& word : strs){
            string wordSize = to_string(word.length());
            encoded += wordSize;
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
            int wordLength = stoi(s.substr(i, j-i));

            int wordStart = j + 1;
            string nextWord = s.substr(wordStart, wordLength);
            result.push_back(nextWord);
            i = wordStart + wordLength;
        }
        return result;
    }
};
*/