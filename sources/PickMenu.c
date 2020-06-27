 #include "main.h"
 
 void PickMenu(WINDOW *menuWnd)
 {
    int ch = 0;
    bool selected = false;
    do
    {
        ch = getchar();
        switch(ch)
        {
           case 's':
            {
               delwin(menuWnd);
               clear();
               refresh();
               selected = true;  
               break; 
            }
            case 'm':
            {
                DrawMenu(menuWnd);
                getch();
                break; 
            }
            case 'q':
            {
                delwin(menuWnd);
                clear();
                refresh(); 
                endwin();
                selected = true;
                exit(1); 
                break; 
            }
            default:
            {
                //DrawMenu(menuWnd);
                //getch();
                break;  
            }      
        }
    }while(!selected);
}
