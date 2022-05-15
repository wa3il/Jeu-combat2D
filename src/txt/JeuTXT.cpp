
    #include "JeuTXT.h"
#include <unistd.h>

/* Clear screen and set up Curses */
void clrscr() 
{
    /* Initialise the screen */
    initscr();
    erase();
    noecho();
    raw();
    move(0, 0);
    /* Cursor off */
    curs_set(0);
    refresh();
}

void JeuTxt :: menuaff(){
    
    clrscr();
    Jtxt.init();

    //on recupere window max y et x
    int yMax = getmaxy(stdscr);

    // pour utiliser les arrows key sur l'ecran
    keypad(stdscr,true);

    string choices[4]={Jtxt.menu.start.tex.lettre,Jtxt.menu.help.tex.lettre,Jtxt.menu.quit.tex.lettre,Jtxt.menu.back.tex.lettre};
    //string choices[3]={"Play","Help","quitter"};
    int choice;
    int highlight = 0;

    //affichage menu
    while(1){
        for(int i = 0;i < 4; i++){
            if(i == highlight) attron(A_REVERSE);
            mvprintw(i+yMax/2,3,choices[i].c_str());
            attroff(A_REVERSE);
        }
        choice = getch();

        // gestion du menu 
        switch(choice){
            case KEY_UP:
                highlight--;
                if(highlight == -1) highlight = 0;
                break;
        
            case KEY_DOWN:
                highlight++;
                if(highlight == 4) highlight = 3;
                break;
        }

    if(choice == 10) break;
    }

    if (choices[highlight] == "P") txtBoucle();
    
    //getch();
    endwin();

}

 void JeuTxt :: txtAff(){
    //affichage des murs.
    for(int y=0; y<Jtxt.ter1.getDimy();y++){
        for(int x=0; x<Jtxt.ter1.getDimx();x++){
            //move(y,x);
            if ((Jtxt.MP.phy.getPosx() == x) && (Jtxt.MP.phy.getPosy() == y) ){
                //affichage perso A
                mvprintw(y, x, Jtxt.MP.tex.lettre);
            }
            else if ((Jtxt.SP.phy.getPosx() == x) && (Jtxt.SP.phy.getPosy() == y) ){
                //affichage perso B
                mvprintw(y, x, Jtxt.SP.tex.lettre);
            }
            else{
                if(Jtxt.ter1.getXY(x,y) == '0'){
                mvprintw(y,x," ");
            }
                if(Jtxt.ter1.getXY(x,y) == '#'){
                mvprintw(y,x,Jtxt.ter1.tex.lettre);
            }
            }
            
        }
    }
    
}

void JeuTxt :: txtBoucle(){
    

    /* Clear Screen */
    clrscr();
    Jtxt.init();
/* 
    Jtxt.MP.phy.setPos (10,10);
    Jtxt.SP.phy.setPos(15,10); */

    bool ok = true;
    
    do{



        txtAff();
        usleep(10000);

        //j.actionsClavier();
        int c = getch();
        keypad(stdscr, true);
  

        switch (c)
        {
            //mouvements MP
            case 'z': //z
                Jtxt.MPClavierDown(0, 1);
            break;

            case 'q': //q
                Jtxt.MPClavierDown(1 , 1);
            break;

            case 'd': //d
                Jtxt.MPClavierDown(2 , 1);
            break;

            //S'accroupir MP
            case 's' :
                Jtxt.MPClavierDown(3 , 1);
            break;

            //attaquer MP
            case 'e':
                Jtxt.MPClavierDown(4 , 1);
            break;

            case 'a':
                Jtxt.MPClavierDown(5 , 1);
            break;



            //mouvements SP
            case KEY_UP: //z
                Jtxt.SPClavierDown(0 , 1);
            break;

            case KEY_LEFT: //q
                Jtxt.SPClavierDown(1 , 1);
            break;

            case KEY_RIGHT: //d
                Jtxt.SPClavierDown(2 , 1);
            break;

            //s'accroupir SP
            case KEY_DOWN:
                Jtxt.SPClavierDown(3 , 1);
            break;

            //attaquer SP
            case 'm':
                Jtxt.SPClavierDown(4 , 1);
            break;

            case 'l':
                Jtxt.SPClavierDown(5 , 1);
            break;

            case 'x':
                ok = false;
            break;

        }
        
     

    } while (ok);

    refresh();
    endwin();

    //free();

}