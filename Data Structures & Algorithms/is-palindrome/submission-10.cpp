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
            
            s[left] = tolower(s[left]);
            s[right] = tolower(s[right]);

            if(s[left] != s[right]){
                return false;
            }
            left++;
            right--;
        }
        return true;
    }
};
