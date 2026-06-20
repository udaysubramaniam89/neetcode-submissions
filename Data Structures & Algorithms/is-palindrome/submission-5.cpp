class Solution {
public:
    bool isPalindrome(string s) {
        int left = 0;
        int right = s.length() - 1;

        while(left < right){
        
            while((left < right) && !isalnum(static_cast<unsigned char>(s[left]))){
                left++;
            }

            while((left < right) && !isalnum(static_cast<unsigned char>(s[right]))){
                right--;
            }
        
            char leftCharacter = tolower(static_cast<unsigned char>(s[left]));
            char rightCharacter = tolower(static_cast<unsigned char>(s[right]));
            
            if(leftCharacter != rightCharacter){
                //mismatch, not a palindrome
                return false;
            }
            
            left++;
            right--;
        }
        return true;        
    }
};
