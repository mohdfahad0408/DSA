class Solution {
public:
    int singleNonDuplicate(vector<int>& arr) {
        int lo=0,hi=arr.size()-1;

        while(lo<hi){
            int mid=lo+(hi-lo)/2;
            if(mid%2)mid--;
            if(arr[mid]==arr[mid+1])lo=mid+2;
            else hi=mid-1;
        }
        return arr[lo];
    }
};