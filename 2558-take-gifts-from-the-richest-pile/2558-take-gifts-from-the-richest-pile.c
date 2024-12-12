long long pickGifts(int* gifts, int giftsSize, int k)
{
    int i,j,max ;

    for(i=0;i<k;++i)
    {
        max = i;

        for(j=0;j<(giftsSize);++j)
        {
            if(gifts[j]>gifts[max])
            {
                max = j ;
            }
        }

        gifts[max] = floor(sqrt(gifts[max]));
    }

    long long sum=0 ;
    for(i=0;i<giftsSize;++i)
    {
        sum += gifts[i] ;
    }

    return sum ;
}