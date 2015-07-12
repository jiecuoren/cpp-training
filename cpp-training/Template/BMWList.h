//
//  LinkedList.h
//  BMW-test
//
//  Created by Lei Gu on 15/7/12.
//  Copyright (c) 2015年 bmw. All rights reserved.
//

#ifndef __BMW_test__LinkedList__
#define __BMW_test__LinkedList__

#include <stdio.h>
#include <iostream>
using namespace std;

class Node
{
public:
    int mData;
    Node* mPre;
    Node* mNext;
    
    Node(int aData, Node* thePrev = NULL, Node* theNext=NULL)
    :mData(aData),mPre(thePrev),mNext(theNext) {}
};

typedef Node* LIST_POS;

class BMWList
{
public:
    BMWList() : mHead(), mTail(), mSize(0) {}
    ~BMWList();
    
    void removeAll();
    void remove();
    void remove(LIST_POS pos);
    void print();
    
    LIST_POS add(int aData);
    LIST_POS insert(int aData, LIST_POS aPos);
    
private:
    Node* mHead;
    Node* mTail;
    int mSize;
};

#endif /* defined(__BMW_test__LinkedList__) */
