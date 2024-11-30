#include "objPosArrayList.h"

// Check lecture contents on general purpose array list construction, 
// and modify it to support objPos array list construction.

objPosArrayList::objPosArrayList()
{
    listSize = 0;
    arrayCapacity = ARRAY_MAX_CAP;
    aList = new objPos[ARRAY_MAX_CAP];
}

objPosArrayList::~objPosArrayList()
{
    delete aList;
}

int objPosArrayList::getSize() const
{
    return listSize;
}

void objPosArrayList::insertHead(objPos thisPos)
{
    int i = listSize;
    while (i > 0)
    {
        aList[i] = aList[i - 1];
        i--;
    }
    aList[0] = thisPos;
    listSize++;
}

void objPosArrayList::insertTail(objPos thisPos)
{
    aList[listSize] = thisPos;
    listSize+=1;
}

void objPosArrayList::removeHead()
{
    int i = 0;
    while (i < listSize - 1)
    {
        aList[i] = aList[i + 1];
        i++;
    }
    listSize--;
}

void objPosArrayList::removeTail()
{
    listSize-=1;
}

objPos objPosArrayList::getHeadElement() const
{
    return aList[0];
}

objPos objPosArrayList::getTailElement() const
{
    return aList[listSize-1];
}

objPos objPosArrayList::getElement(int index) const
{
    return aList[index];
}