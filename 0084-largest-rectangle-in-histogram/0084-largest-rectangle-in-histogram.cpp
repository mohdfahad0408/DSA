class Solution {
public:
    int largestRectangleArea(vector<int>& arr) {
        int n=arr.size(),area=0;
        vector<int>next(n,0);
        vector<int>prev(n,0);
        stack<int>st;
        for(int i=n-1;i>=0;i--){
            while(st.size() && arr[st.top()]>=arr[i]) st.pop();
            next[i]=st.size()?st.top():n;
            st.push(i);
        }

        while(st.size()) st.pop();

        for(int i=0;i<n;i++){
            while(st.size() && arr[st.top()]>=arr[i]) st.pop();
            prev[i]=st.size()?st.top():-1;
            st.push(i);
        }

        for(int i=0;i<n;i++){
            int width=next[i]-prev[i]-1;
            area=max(area,arr[i]*width);
        }
        return area;


    }
};