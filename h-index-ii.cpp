/*
 Follow up for H-Index: What if the citations array is sorted in ascending order? Could you optimize your algorithm?

Hint:

    Expected runtime complexity is in O(log n) and the input is sorted.
*/

class Solution {
public:
    int hIndex(vector<int>& citations) {
        int len = citations.size();
        int left = 0;
        int mid = 0;
        int right = len - 1;
        while(left <= right){
            mid = (left+right)/2;
            if(citations[mid] < len - mid)
                left = mid + 1;
            else
                right = mid -1;
        }
        return len - left;
    }
};
