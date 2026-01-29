class Solution {
public:
    bool check(vector<int>& nums) {
        int count= 0;
        int n= nums.size();
        for(int i=1; i<n; i++){//i=1 se isliye start kiya kyuki i=0 karte toh i-1 exist hi nahi karta
            if (nums[i-1]> nums[i]){
                count++;
            }
        }
        if (nums[n-1]> nums[0]){
            count++;
        }

        return count<=1;//will return true if count==1 otherwise false
    }
};