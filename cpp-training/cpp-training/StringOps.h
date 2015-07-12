//
//  StringOps.h
//  cpp-training
//
//  Created by Lei Gu on 15/7/12.
//  Copyright (c) 2015年 codefreeme. All rights reserved.
//

#ifndef __cpp_training__StringOps__
#define __cpp_training__StringOps__

#include <stdio.h>

class StringOps
{
public:
    StringOps();
    ~StringOps();
    
    void int2str(int aLength, char* aStr);
    char* strcpy(char* aDest, char* aSource);
    int strLength(const char* aStr);
};

#endif /* defined(__cpp_training__StringOps__) */
