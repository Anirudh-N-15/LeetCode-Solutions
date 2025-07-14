int maxProfit(int* prices, int pricesSize) 
{
    int i=0,j=1 ;
    int temp ;
    int max = 0 ;

    while(i<j && j<pricesSize)
    {
        if((prices[j]-prices[i]) > max)
        {
            max = prices[j] - prices[i] ; 
        }
        
        if(prices[j] < prices[i])
        {
            i = j;
        }
        j++ ;
    }
    
    if(max ==0)
    return 0 ;

    return max ;

}