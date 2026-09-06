class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& arr) {
        int n=arr.size();
        vector<int>ans(n,0);
        stack<int>st;
        for(int i=n-1;i>=0;i--) st.push(arr[i]);
        for(int i=n-1;i>=0;i--){
            while(st.size() && st.top()<=arr[i]) st.pop();
            ans[i]=st.size()?st.top():-1;
            st.push(arr[i]);
        }
        return ans;
    }
};