/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

int LinearSearch(int *nums2,int key,int nums2Size)
{
    for(int i=0;i<nums2Size;++i)
    {
        if(nums2[i]==key)
        {
            return i ;
        }
    }
    return -1 ;
}

int NGE(int *nums2,int x,int nums2Size)
{
    for(int i=x;i<nums2Size;++i)
    {
        if(nums2[i]>nums2[x])
        {
            return nums2[i];
        }
    }
    return -1 ;
}

int* nextGreaterElement(int* nums1, int nums1Size, int* nums2, int nums2Size, int* returnSize) {
    int * ans = (int * )malloc(sizeof(int)*nums1Size);
    int ptr=0,i=0;
    

    while(ptr<nums1Size)
    {
        int x = LinearSearch(nums2,nums1[ptr],nums2Size);

        int y = NGE(nums2,x,nums2Size);

        ans[i]=y;

        ptr++ ;
        i++ ;
    }
    *returnSize = nums1Size;

    return ans ;
}