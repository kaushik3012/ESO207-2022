#include<iostream>
#include<vector>
#define int long long
using namespace std;

int countS[100001] = {};
vector<int> maina;

class Solution 
{
    public:

    int searchArray(vector<int> &arr, int low, int high, int x) {
        for(int i=low;i<=high;i++)
        {
            if(arr[i]==x)
                return i;
        }
        return -1;
    }

    int merge(vector<int> &nums, vector<int> &temp, int left, int mid, int right, int var) {
        int count = 0;
        int j = mid + 1;
        
        // Count all reverse pairs. O(n) operation as we are not moving j back to mid + 1.
        for(int i = left; i <= mid; i++) 
        {
            while(j <= right && nums[i]> var*nums[j])
            {
                j++;
            }
    
            count += (j - (mid + 1));

            //Searching index of the element in the main array
            int index = searchArray(maina, 0, maina.size() -1, nums[i]);
            countS[index] += (j - (mid+1));
        }
        
        // Now regular merge
        int i = left, k = left;
        j = mid + 1;
        
        while(i <= mid and j <= right) 
        {
            if(nums[i] <= nums[j])
                temp[k++] = nums[i++];
            else
                temp[k++] = nums[j++];
        }
        
        while(i <= mid)
            temp[k++] = nums[i++];
        while(j <= right)
            temp[k++] = nums[j++];
        
        for(int i = left; i <= right; i++)
            nums[i] = temp[i];

        return count;
    }
    
    //Function to perform the modified merge sort
    int mergeSort(vector<int> &nums, vector<int> &temp, int left, int right, int k) 
    {
        if(left >= right) 
            return 0;

        int mid = left + (right - left)/2;
        return mergeSort(nums, temp, mid+1, right, k)+
        mergeSort(nums, temp, left, mid, k) + merge(nums, temp, left, mid, right, k);
    }
    
    //Function to count reverse pairs
    int reversePairs(vector<int>& nums, int k) 
    {
        vector<int> temp(nums.size());
        return mergeSort(nums, temp, 0, nums.size()-1, k);
    }
};



int32_t main()
{
    int n,k;
    cin>>n>>k;
    
    vector<int> a;
    for(int i=0;i<n;i++)
    {
        int var;
        cin>>var;
        a.push_back(var);
        maina.push_back(var);
    }        

    Solution s;
    s.reversePairs(a,k);

    for(int i=0;i<n;i++)
    {
        cout<<countS[i]<<" ";
    }
    cout<<endl;

    return 0;
}