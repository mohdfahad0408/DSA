class Solution {
public:
    long long minimumReplacement(vector<int>& arr) {
        long long c=0;
        int n=arr.size();
        int prev=arr[n-1];
        for(int i=n-2;i>=0;i--){
            if(arr[i]<=prev) prev=arr[i];
            else {
                int p=arr[i]/prev;
                if(arr[i]%prev)p++;
                c+=p-1;
                prev=arr[i]/p;
            }
        }
        return c;
    }
};