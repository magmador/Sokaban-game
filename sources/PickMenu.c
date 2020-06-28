 #include "main.h"
 
 int PickMenu(WINDOW *menuWnd)
 {
    switch(getchar())
    {
        case 's':
        {
           return SINGLE_PLAYER_FLAG;
           break; 
        }
        case 'm':
        {
            return MULTI_PLAYER_FLAG;
            break; 
        }
        case 'q':
        {
            return QUIT_FLAG;
            break; 
        }
        default:
        {
            break;  
        }      
    }
}
