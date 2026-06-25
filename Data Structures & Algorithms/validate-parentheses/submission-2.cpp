class Solution {
public:
    bool isValid(string s) {
        stack<char> st;

        for(char c : s){
            if(c == '(' || c == '[' || c == '{'){
                st.push(c);
            }

            if(c == ']'){
                if(st.empty() || st.top() != '['){
                    return false;
                }

                st.pop();
            }

            if(c == '}'){
                if(st.empty() || st.top() != '{'){
                    return false;
                }

                st.pop();
            }

            if(c == ')'){
                if(st.empty() || st.top() != '('){
                    return false;
                }

                st.pop();
            }
        }
        return st.empty();   
    }
};





























        /*
        stack<char> st;
        for(char c : s){
            if(c == '[' || c == '(' || c == '{'){
                st.push(c);
            }

            if(c == ']'){
                if(st.empty() || st.top() != '['){
                    return false;
                }
                st.pop();
            }

            else if(c == ')'){
                if(st.empty() || st.top() != '('){
                    return false;
                }
                st.pop();
            }

            else if(c == '}'){
                if(st.empty() || st.top() != '{'){
                    return false;
                }
                st.pop();
            }
        }
        return st.empty();
    }
};
*/
