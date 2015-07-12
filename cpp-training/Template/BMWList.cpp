//
//  LinkedList.cpp
//  BMW-test
//
//  Created by Lei Gu on 15/7/12.
//  Copyright (c) 2015年 bmw. All rights reserved.
//

#include "BMWList.h"

BMWList::~BMWList()
{
    removeAll();
}

void BMWList::removeAll()
{
    if(mSize != 0)
    {
        for(int i=0; i<mSize; ++i)
        {
            Node* temp = mHead->mNext;
            delete mHead;
            mHead = temp;
        }
    }
    
    mSize = 0;
}

void BMWList::remove(LIST_POS pos)
{
    if(0 == mSize)
    {
        return;
    }
    
    if(NULL == pos)
    {
        return;
    }
    
    Node* pre = pos->mPre;
    Node* next = pos->mNext;
    
    if(NULL == pre) //remove head
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
    
    delete pos;
}

void BMWList::remove()
{
    if(NULL == mHead)
    {
        return;
    }
    
    Node* pNode = mTail;
    Node* tailPre = pNode->mPre;
    tailPre->mNext = NULL;
    
    delete mTail;
    
    mSize--;
}

void BMWList::print()
{
    Node* pNode = mHead;
    while (NULL != pNode)
    {
        cout << pNode->mData << " ";
        pNode = pNode->mNext;
    }
    
    cout << endl;
}

LIST_POS BMWList::add(int aData)
{
    Node* pNode = new Node(aData);
    
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
    
    return pNode;
}

LIST_POS BMWList::insert(int aData, LIST_POS aPos)
{

    Node* pNode = new Node(aData);
    
    if(aPos == mHead)
    {
        pNode->mPre = NULL;
        pNode->mNext = aPos;
        aPos->mPre = pNode;
        mHead = pNode;
    }
    else
    {
        Node* pre = aPos->mPre;
        pre->mNext = pNode;
        pNode->mPre = pre;
        pNode->mNext = aPos;
    }
    
    mSize++;
    return pNode;
}




