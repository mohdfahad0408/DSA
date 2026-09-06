class Solution {
public:
    bool isValid(string s) {
        if(s.size()%2) return false;
        stack<char>st;
        for(char x:s){
            if(string("({[").contains(x)) st.push(x);
            else{
                if(st.size()==0) return false;
                if(x==']' && st.top()!='[' || 
                x=='}' && st.top()!='{' ||
                x==')' && st.top()!='(') return false;
                st.pop();
            }
        }
        if(st.size()) return false;
        return true;
    }
};