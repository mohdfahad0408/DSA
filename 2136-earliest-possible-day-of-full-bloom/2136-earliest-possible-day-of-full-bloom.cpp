class Solution {
public:
    int earliestFullBloom(vector<int>& plantTime, vector<int>& growTime) {
        int n=plantTime.size();
        vector<pair<int,int>>v;

        for(int i=0;i<n;i++){
            v.push_back({growTime[i],plantTime[i]});
        }

        sort(v.rbegin(),v.rend());

        int pd=0,bd=0;

        for(int i=0;i<n;i++){
            int plant=v[i].second;
            int grow=v[i].first;
            pd+=plant;
            bd=max(bd,grow+pd);
        }
        return bd;
    }
};