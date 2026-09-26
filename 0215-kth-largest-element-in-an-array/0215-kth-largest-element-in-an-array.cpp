class Solution {
public:
    int findKthLargest(vector<int>& arr, int k) {
        priority_queue<int,vector<int>,greater<int>>pq(arr.begin(),arr.begin()+k);
        for(int i=k;i<arr.size();i++){
            if(arr[i]>pq.top()){
                pq.pop();
                pq.push(arr[i]);
            }
        }
        return pq.top();
    }
};