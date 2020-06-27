 #include "main.h"
 
 void PickMenu(WINDOW *menuWnd)
 {
     int ch = getchar();
     switch(ch)
     {
         case 's':
             delwin(menuWnd);
             clear();
             refresh();  
	     break; 
	case 'm':
            DrawMenu(menuWnd);
            getch();
	    break; 
	case 'q':
	    delwin(menuWnd);
	    clear();
	    refresh(); 
	    endwin();
	    exit(1); 
	    break; 
	default:
            DrawMenu(menuWnd);
            getch();
            break;        
      }
}
