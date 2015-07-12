//
//  StringOps.cpp
//  cpp-training
//
//  Created by Lei Gu on 15/7/12.
//  Copyright (c) 2015年 codefreeme. All rights reserved.
//

#include "StringOps.h"

StringOps::StringOps()
{
}

StringOps::~StringOps()
{
}

void StringOps::int2str(int aNum, char* aStr)
{
    if(NULL == aStr)
    {
        return;
    }
    
    char buf[10] = "";
    int i = 0;
    int length = 0;
    int temp = aNum < 0 ? -aNum : aNum;

    while (temp)
    {
        buf[i++] = (temp%10) + '0';
        temp = temp/10;
    }
    
    length = aNum < 0 ? ++i : i;
    aStr[i] = 0;
    while (1)
    {
        i--;
        if(buf[length - i - 1] == 0)
        {
            break;
        }
        
        aStr[i] = buf[length - i - 1];
    }
    
    if(i == 0)
    {
        aStr[i] = '-';
    }
    
}

char* StringOps::strcpy(char* aDest, char* aSource)
{
//    if(NULL == aDest || NULL == aSource)
//    {
//        return NULL;
//    }
//    
//    char* strDestCopy = aDest;
//    while ((*aDest++ = *aSource++) != '\0')
//    {
//        //do noting
//    }
//    
//    return strDestCopy;
    
    char* pSrouce = aSource;
    char* ret = aDest;
    
    while (*pSrouce != '\0')
    {
        *aDest = *pSrouce;
        aDest++;
        pSrouce++;
    }
    
    *(aDest) = '\0';
    
    return ret;
}

int StringOps::strLength(const char* aStr)
{
    int ret = 0;
    while (*aStr++ != '\0')
    {
        ++ret;
    }
    return ret;
}