class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        //Step-1 : Max Heap banao and first k elements push karo
        priority_queue<int, vector<int>, greater<int>> pq;
        for(int i= 0; i< k; i++){
            pq.push(nums[i]);
        }
        
        //Step-2: for remaining elements apply condition
        for(int i= k; i< nums.size(); i++){
            if(nums[i] > pq.top()){
                pq.pop();
                pq.push(nums[i]);
            }
        }
        
        return pq.top();
    }
};