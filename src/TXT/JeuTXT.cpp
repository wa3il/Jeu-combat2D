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

void txtAff(Jeu & j){

    //affichage des murs.
    for(int y=0; y<j.ter1.getDimy();++y){
        for(int x=0; x<j.ter1.getDimx();++x){
            if ((j.MP.getx() == x) && (j.MP.gety() == y) ){
                //affichage perso A
                mvprintw(j.MP.gety(),j.MP.getx(),"A");
            }
            /*if ((j.SP.getx() == x) && (j.SP.gety() == y) ){
                //affichage perso B
                mvprintw(j.SP.gety(),j.SP.getx(),"B");
            }*/
            else{
                if(j.ter1.getXY(x,y) == '_'){
                move(y,x);
                mvprintw(y,x," ");
            }
                if(j.ter1.getXY(x,y) == '#'){
                move(y,x);
                mvprintw(y,x,"#");
            }
            }
            
        }
    }
    
}

void txtBoucle(Jeu & j){


    /* Clear Screen */
    clrscr();

    j.MP.setxy(10,10);
    j.MP.setxy(15,10);

    bool ok = true;
    int c;
    do{
        txtAff(j);
        usleep(10000);

        c = getch();
        switch (c)
        {
        case 'z': //z
            j.actionsClavier('z');
            break;

        case 'q': //q
            j.actionsClavier('g');
            break;

        case 'd': //d
            j.actionsClavier('d');
            break;

        case 'j': //z
            j.actionsClavier('j');
            break;

        case 'i': //q
            j.actionsClavier('i');
            break;

        case 'l': //d
            j.actionsClavier('l');
            break;
        }
        
        //j.actionsAutomatique();

    } while (ok);

    refresh();
    endwin();

    //free();

}