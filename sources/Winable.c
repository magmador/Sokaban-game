#include "main.h"

bool Winable(Object *Boxs, Object *Endpoints, size_t bCount, size_t eCount)
{
    bool win[eCount];
    memset(win,false,eCount);
    
    for(size_t eIndex = 0; eIndex < eCount; eIndex++)
    {
        for(size_t bIndex = 0; bIndex < bCount; bIndex++)
               if((Boxs[bIndex].yPos == Endpoints[eIndex].yPos) && (Boxs[bIndex].xPos == Endpoints[eIndex].xPos))
                   win[bIndex] = true;
    }

    bool winning = true;
    for(size_t winIndex = 0; winIndex < eCount; winIndex++)
        if(!win[winIndex]) { winning = false; break; }

    return winning ? true:false;
}