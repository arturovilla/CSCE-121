//
//  functions.cpp
//  differentdigits
//
//  Created by Arturo Villalobos on 9/13/19.
//  Copyright © 2019 Arturo Villalobos. All rights reserved.
//

#include <stdio.h>
int countDigitOccurrences (int n, int digit)
{
    
    int count = 0;
    while (n > 0)
    {
        if (digit== n % 10)
        {
            count++;
        }
        
        n = n / 10;
    }
    return count;
}
