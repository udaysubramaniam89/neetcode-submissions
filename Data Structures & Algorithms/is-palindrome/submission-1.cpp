class Solution {
public:
    bool isPalindrome(string s) {
        int left = 0;
        int right = s.length() - 1;

        while(left < right){
        
            while((left < right) && !isalnum(s[left])){
                left++;
            }

            while((left < right) && !isalnum(s[right])){
                right--;
            }
        
            char leftCharacter = tolower(s[left]);
            char rightCharacter = tolower(s[right]);
            
            if(leftCharacter != rightCharacter){
                //mismatch, not a palindrome
                return false;
                break;
            }
            
            if(leftCharacter == rightCharacter){
                left++;
                right--;
            }
        }
        return true;        
    }
};
