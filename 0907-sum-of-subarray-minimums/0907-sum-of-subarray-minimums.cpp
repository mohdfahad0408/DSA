class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        stack<int> st ;
        int n=arr.size();
        vector<int>prev(n,0),next(n,0);
        int mod=1000000007;

        for(int i=0;i<n;i++){
            while(st.size() && arr[st.top()]>=arr[i]) st.pop();
            prev[i]=st.size()?st.top():-1;
            st.push(i);
        }
        while(st.size()) st.pop();

        for(int i=n-1;i>=0;i--){
            while(st.size() && arr[st.top()]>arr[i]) st.pop();
            next[i]=st.size()?st.top():n;
            st.push(i);
        }

        long long  sum=0;
        for(int i=0;i<n;i++){
            long long left=i-prev[i];
            long long right=next[i]-i;
            sum=(sum+(1LL*arr[i]*left%mod)*right)%mod;
        }
        return (int)sum%mod;
    }
};