//
//  Algorithm.cpp
//  bmw-training
//
//  Created by Lei Gu on 15/7/10.
//  Copyright (c) 2015年 codefreeme. All rights reserved.
//

#include "Algorithm.h"
#include <iostream>

using namespace std;

Algorithm::Algorithm()
{
    
}

Algorithm::~Algorithm()
{
    
}

void Algorithm::qSort(int aArray[], int aLeft, int aRight)
{
    if(aLeft >= aRight)
    {
        return;
    }
    
    int first = aLeft;
    int last = aRight;
    int key = aArray[first];
    
    while(first < last)
    {
        while (first < last && aArray[last] >= key)
        {
            --last;
        }
        
        aArray[first] = aArray[last];
        
        while (first < last && aArray[first] <= key) {
            ++first;
        }
        
        aArray[last] = aArray[first];
    }
    
    aArray[first] = key;
    qSort(aArray, aLeft, first-1);
    qSort(aArray, first+1, aRight);
}