bool lemonadeChange(int* bills, int billsSize) 
{
    int change_5=0,change_10=0,change_20=0 ;

    for(int i=0;i<billsSize;++i)
    {
        if(bills[i]==5)
        {
            change_5++ ;
        }

        if(bills[i]==10)
        {
            if(change_5==0)
            {
                return false ;
            }
            change_10++ ;
            change_5-- ;
        }

        if(bills[i]==20)
        {
            change_20++ ;

            if(change_10 > 0 && change_5 > 0)
            {
                change_10-- ;
                change_5-- ;
            }

            else if(change_10 == 0 && change_5 >2)
            {
                change_5 = change_5 - 3 ;
            }

            else 
            return false ;
        }
    }
    return true ;
}