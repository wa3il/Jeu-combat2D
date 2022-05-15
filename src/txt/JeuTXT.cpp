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
    Jtxt.init();
    clrscr();

    //on recupere window max y et x
    int xMax = getmaxx(stdscr);
    int yMax = getmaxy(stdscr);

    // pour utiliser les arrows key sur l'ecran
    keypad(stdscr,true);

    string choices[3]={Jtxt.menu.start.tex.lettre, Jtxt.menu.quit.tex.lettre};
    //string choices[3]={"Play","Help","quitter"};
    int choice;
    int highlight = 0;

    //affichage menu
    while(1){
        for(int i = 0;i < 2; i++){
            if(i == highlight) attron(A_REVERSE);
            mvprintw(i+yMax/2,xMax/2,choices[i].c_str());
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
                if(highlight == 2) highlight = 1;
                break;
        }

    if(choice == 10) break;
    }

    if (choices[highlight] == Jtxt.menu.start.tex.lettre) txtBoucle();
    
    //getch();
    endwin();

}

 void JeuTxt :: txtAff(){
     
    //affichage des murs.
    for(int x=0; x<Jtxt.ter1.getDimx();++x){
        for(int y=0; y<Jtxt.ter1.getDimy();++y){
            //on cherche dans le modul terrain pour placer les murs
            if(Jtxt.ter1.getXY(x,y) == '0') mvprintw(x,y*10,"__________");
            if(Jtxt.ter1.getXY(x,y) == '#')mvprintw(x,y*10,Jtxt.ter1.tex.lettre);
        }
    }
    mvprintw(Jtxt.SP.phy.getPosy(),Jtxt.SP.phy.getPosx() , Jtxt.SP.tex.lettre);
    mvprintw(Jtxt.MP.phy.getPosy(),Jtxt.MP.phy.getPosx() , Jtxt.MP.tex.lettre);
}

void JeuTxt :: txtBoucle(){
    
    float NOW = clock();
    float LAST = 0;
    float deltaTime = 0;

    /* Clear Screen */
    clrscr();
    Jtxt.init();

    Jtxt.MP.phy.setPos(10,10);
    Jtxt.SP.phy.setPos(15,10);

    bool ok = true;
    
    do{

        //deltaTime
        LAST = NOW;
        NOW = clock();
        float deltaTime = (float)((NOW - LAST)/CLOCKS_PER_SEC);
        txtAff();
        usleep(10000);

        //j.actionsClavier();
        int c = getch();

        switch (c)
        {
        //mouvements MP
            case 'q' :  Jtxt.MPClavierDown(1); break;
            case 'd' : Jtxt.MPClavierDown(0); break;
            case 'z' :  Jtxt.MPClavierDown(2); break;
            //S'accroupir MP
            case 's' : Jtxt.MPClavierDown(3); break;
            //attaquer MP
            case 'e' : Jtxt.MPClavierDown(4); break;
            case 'a' : Jtxt.MPClavierDown(5); break;

            //mouvements SP
            case KEY_LEFT:  Jtxt.SPClavierDown(0); break;
            case KEY_RIGHT: Jtxt.SPClavierDown(1); break;
            case KEY_UP:  Jtxt.SPClavierDown(2); break;
            //s'accroupir SP
            case KEY_DOWN: Jtxt.SPClavierDown(3); break;
            //attaquer SP
            case 'm': Jtxt.SPClavierDown(4); break;
            case 'l': Jtxt.SPClavierDown(5); break;
            //endwin 
            case 'x': ok = false; break;
        }
        

    } while (ok);

    refresh();
    endwin();
    
    //free();

}