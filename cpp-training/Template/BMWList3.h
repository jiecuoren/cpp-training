//
//  BMWList3.h
//  BMW-test
//
//  Created by Lei Gu on 15/7/12.
//  Copyright (c) 2015年 bmw. All rights reserved.
//

#ifndef __BMW_test__BMWList3__
#define __BMW_test__BMWList3__

#include <stdio.h>
#include <iostream>
#include <string>
#include "BMWList2.h"

using namespace std;

template <>
class Node2<string*>
{
public:
    Node2<string*>* mPre;
    Node2<string*>* mNext;
    const string* mData;
    
    Node2(const string* aData, Node2* aPre = NULL, Node2* aNext = NULL)
    : mData(aData), mPre(aPre), mNext(aNext)
    {
    }
};

template <>
class LIST_POS2<string*>
{
public:
    LIST_POS2(Node2<string*>* aData) : mData(aData) {}
    LIST_POS2();
    Node2<string*>* mData;
};

template<>
class BMWList2<string*>
{
public:
    BMWList2() : mHead(NULL), mTail(NULL), mSize(0)
    {
    }
    
    ~BMWList2()
    {
        removeAll();
    }
    
    void removeAll()
    {
        if(0 != mSize)
        {
            for(int i=0; i<mSize; ++i)
            {
                Node2<string*>* temp = mHead->mNext;
                delete mHead;
                mHead = temp;
            }
        }
        mSize = 0;
    }
    
    void remove()
    {
        if(NULL == mHead)
        {
            return;
        }
        
        Node2<string*>* pNode = mTail;
        Node2<string*>* tailPre = pNode->mPre;
        tailPre->mNext = NULL;
        
        delete mTail;
        mSize--;
    }
    
    void remove(LIST_POS2<string*>* aPos)
    {
        if(0 == mSize)
        {
            return;
        }
        
        Node2<string*>* posData = aPos->mData;
        
        if(NULL == posData)
        {
            return;
        }
        
        Node2<string*>* pre = posData->mPre;
        Node2<string*>* next = posData->mNext;
        
        if(NULL == pre)
        {
            mHead = next;
            next->mPre = NULL;
        }
        else
        {
            pre->mNext = next;
            next->mPre = pre;
        }
        
        mSize--;
        delete posData;
    }
    
    void print()
    {
        Node2<string*>* pNode = mHead;
        while (NULL != pNode)
        {
            cout << *(pNode->mData) << ", ";
            pNode = pNode->mNext;
        }
        
        cout<<endl;
    }
    
    LIST_POS2<string*> add(string* aData)
    {
        Node2<string*>* pNode = new Node2<string*>(aData);
        
        if(0 == mSize)
        {
            mHead = pNode;
            mTail = pNode;
        }
        else if(1 == mSize)
        {
            mHead->mNext = pNode;
            mHead->mPre = NULL;
            
            pNode->mPre = mHead;
            pNode->mNext = NULL;
            
            mTail = pNode;
        }
        else
        {
            mTail->mNext = pNode;
            pNode->mPre = mTail;
            mTail = pNode;
        }
        
        mSize++;
        LIST_POS2<string*> newPos = LIST_POS2<string*>(pNode);
        
        return newPos;
    }
    
    LIST_POS2<string*> insert(string* aData, LIST_POS2<string*> aPos)
    {
        Node2<string*>* pNode = new Node2<string*>(aData);
        Node2<string*>* posNode = aPos.mData;
        
        if(posNode == mHead)
        {
            pNode->mPre = NULL;
            pNode->mNext = posNode;
            posNode->mPre = pNode;
            mHead = pNode;
        }
        else
        {
            Node2<string*>* pre = posNode->mPre;
            pre->mNext = pNode;
            pNode->mPre = pre;
            pNode->mNext = posNode;
        }
        
        mSize++;
        LIST_POS2<string*> newPos = LIST_POS2<string*>(pNode);
        return newPos;
    }
    
private:
    Node2<string*>* mHead;
    Node2<string*>* mTail;
    int mSize;
};

#endif /* defined(__BMW_test__BMWList3__) */
