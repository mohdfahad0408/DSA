class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        unordered_map<int,int>um;
        vector<int>ans(arr.begin(),arr.end());

        sort(arr.begin(),arr.end());
        int c=0;

        for(int i=0;i<arr.size();i++){
            if(!(um[arr[i]])) c++;
            um[arr[i]]=c;
        }

        for(int i=0;i<ans.size();i++){
            ans[i]=um[ans[i]];
        }
        return ans;

    }
};