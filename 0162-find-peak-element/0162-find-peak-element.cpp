class Solution {
public:
    int findPeakElement(vector<int>& arr) {
        int lo=0,hi=arr.size()-1;
        if(hi==0 || arr[0]>arr[1]) return 0;
        if(arr[hi]>arr[hi-1]) return hi;
        while(lo<=hi){
            int mid=lo+(hi-lo)/2;
            if(arr[mid]<arr[mid+1])lo=mid+1;
            else if(arr[mid]<arr[mid-1])hi=mid-1;
            else return mid;
        }
        return 567;
    }
};