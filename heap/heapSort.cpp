// problem link: https://leetcode.com/problems/sort-an-array/submissions/
class Solution {
    private:
    void heapify(vector<int>& nums,int n,int i){
        int largest=i;
        int left=2*i+1;
        int right=2*i+2;
        if(left<n&&nums[largest]<nums[left])
            largest=left;
        if(right<n&&nums[largest]<nums[right])
            largest=right;
        if(largest!=i)
        {swap(nums[largest],nums[i]);
         heapify(nums,n,largest);}
        else
            return;
    }
    void heapSort(vector<int>& nums,int n){
        int size=n;
        while(size>1){
           swap(nums[size-1],nums[0]);
            size--;
            heapify(nums,size,0);
        }
        
    }
public:
    vector<int> sortArray(vector<int>& nums) {
        int n=nums.size();
        // creating heap
        for(int i=n/2;i>=0;i--)
            heapify(nums,n,i);
        // sorting the heap
        heapSort(nums,n);
        return nums;
    }
};