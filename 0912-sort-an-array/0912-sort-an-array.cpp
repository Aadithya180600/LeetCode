class Solution {
public:
    void merge(vector<int>& nums, int lo, int hi, int mid){
        vector<int> left;
        vector<int> right;
        for(int i = lo;i<=mid;i++){
            left.push_back(nums[i]);
        }
        for(int i = mid+1;i<=hi;i++){
            right.push_back(nums[i]);
        }
        int i = 0, j = 0, k = lo;
        while(i<left.size() and j<right.size()){
            if(left[i] <= right[j]) {
                nums[k++] = left[i++]; 
            }
            else{
                nums[k++] = right[j++];
            }
        }
        while(i<left.size()){
            nums[k++] = left[i++];
        }
        while(j<right.size()){
            nums[k++] = right[j++];
        }
    }
    void merge_sort(vector<int>& nums, int lo, int hi)
    {
        if(lo != hi){
        int mid = lo + (hi - lo) / 2;
        merge_sort(nums, lo, mid);
        merge_sort(nums, mid+1, hi);
        merge(nums, lo, hi, mid);
        }
    }

    void insertion_sort(vector<int>& nums){
        int i, key, j;
        int n = nums.size();
        for (i = 1; i < n; i++) {
            key = nums[i];
            j = i - 1;
            while (j >= 0 && nums[j] > key) {
                nums[j + 1] = nums[j];
                j = j - 1;
            }
            nums[j + 1] = key;
        }
    }

    vector<int> sortArray(vector<int>& nums) {
        if(nums.size() < 10){
            insertion_sort(nums);
        }
        else {
            merge_sort(nums, 0, nums.size() - 1);
        }
        return nums;
    }
};