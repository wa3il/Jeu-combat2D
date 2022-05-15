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
    for(int x=0; x<Jtxt.ter1.getDimx();++x){
        for(int y=0; y<Jtxt.ter1.getDimy();++y){
            //on cherche dans le modul terrain pour placer les murs
                if(Jtxt.ter1.getXY(x,y) == '0') mvprintw(x,y*4," ");
                if(Jtxt.ter1.getXY(x,y) == '#')mvprintw(x,y*4,Jtxt.ter1.tex.lettre);
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

    Jtxt.MP.phy.setPos (10,10);
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
            case 'z' :  Jtxt.actionsClavier('z', 1); break;
            case 'q' :  Jtxt.actionsClavier('g', 1); break;
            case 'd' : Jtxt.actionsClavier('d', 1); break;

            //S'accroupir MP
            case 's' : Jtxt.actionsClavier('s', 1); break;
            //attaquer MP
            case 'e' : Jtxt.actionsClavier('t', 1); break;
            case 'a' : Jtxt.actionsClavier('w', 1); break;

            //mouvements SP
            case KEY_UP:  Jtxt.actionsClavier('j', 1); break;
            case KEY_LEFT:  Jtxt.actionsClavier('i', 1); break;
            case KEY_RIGHT: Jtxt.actionsClavier('l', 1); break;
            //s'accroupir SP
            case KEY_DOWN: Jtxt.actionsClavier('k', 1); break;
            //attaquer SP
            case 'm': Jtxt.actionsClavier('b', 1); break;
            case 'l': Jtxt.actionsClavier('n', 1); break;
            //endwin 
            case 'x': ok = false; break;
        }
        

    } while (ok);

    refresh();
    endwin();
    
    //free();

}