int getCommon(int* nums1, int nums1Size, int* nums2, int nums2Size) 
{

    int count[10001] = {1} ;

    int i , ans ;

    for(i=0;i<nums1Size;++i)
    {
        count[nums1[i]]++ ;
    }

    for(i=0;i<nums2Size;++i)
    {
        count[nums2[i]]++ ;
    }

    for(i=0;i<10001;++i)
    {
        
        if(count[i]==2)
        {
          ans = i ;
          break ;
        }
    }
    
    return ans ;
}