class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& arr, int k) {
        vector<int>ans;
        deque<int>dq;

        for(int i=0;i<k;i++){
            while(dq.size() && dq.back()<arr[i]) dq.pop_back();
            dq.push_back(arr[i]);
        }
        ans.push_back(dq.front());

        for(int i=k;i<arr.size();i++){
            if(dq.front() == arr[i-k])dq.pop_front();
            while(dq.size() && dq.back()<arr[i]) dq.pop_back();
            dq.push_back(arr[i]);
            ans.push_back(dq.front());
        }

        return ans;
    }
};