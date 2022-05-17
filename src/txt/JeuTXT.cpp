#include "JeuTXT.h"
#include <unistd.h>

/* Clear screen and set up Curses */
void JeuTxt :: init() 
{
    /* Initialise the screen */
    initscr();
    erase();
    haut= subwin(stdscr, LINES / 2, COLS, 0, 0);          
    bas = subwin(stdscr, LINES / 2, COLS, LINES / 2, 0); 
    box(haut, ACS_VLINE, ACS_HLINE);
    box(bas, ACS_VLINE, ACS_HLINE);
    
    refresh();
    noecho();
    raw();
    move(0, 0);
    /* Cursor off */
    curs_set(0);
   
    /*initialise le jeu */
    //init des joueurs
    Jtxt.init();
    
}

void JeuTxt :: update(){

    //on recupere window max y et x
    int xMax = getmaxx(haut);
    int yMax = getmaxy(haut);


    

    // pour utiliser les arrows key sur l'ecran
    keypad(haut,true);

    string choices[2]={Jtxt.menu.start.tex.lettre ,Jtxt.menu.quit.tex.lettre};

    int choice;
    int highlight = 0;

    mvwprintw(bas,2,2,"Appuyer Sur les flèches pour choisir et Entrer pour selectionner");
    wrefresh(bas);

    //affichage menu
    while(1){
        for(int i = 0;i < 2; i++){
            if(i == highlight) wattron(haut,A_REVERSE);
            mvwprintw(haut,i+yMax/2,xMax/2,choices[i].c_str());
            wattroff(haut,A_REVERSE);
        }
        choice = wgetch(haut);
        
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

   
    
    if (choices[highlight] == Jtxt.menu.start.tex.lettre){
    werase(haut);
    werase(bas);
    box(haut, ACS_VLINE, ACS_HLINE);
    box(bas, ACS_VLINE, ACS_HLINE);
    mvwprintw(bas,1,1,"partie commencée!");
    wattron(bas,A_DIM);
    mvwprintw(bas,yMax-2,1,"Appuyez sur x pour Quitter!");
   
    wrefresh(haut);
    wrefresh(bas);
    txtBoucle();
    }
    
    if (choices[highlight] == Jtxt.menu.quit.tex.lettre) endwin();

}

void JeuTxt :: txtAff(){
   
    
    werase(haut);
    /* affichage du sol.*/
    for(int i=0 ;i<Jtxt.ter1.getDimx();i++){
        Jtxt.ter1.setCaract(i,Jtxt.ter1.getDimy()-1,"#");
    }

    //platforme
    for (int j=Jtxt.ter1.getDimx()/4;j<3*Jtxt.ter1.getDimx()/4;j++){
        Jtxt.ter1.setCaract(j,Jtxt.ter1.getDimy()/2,"#");
    }

    for(int x=0; x<Jtxt.ter1.getDimx();x++){
        for(int y=0; y<Jtxt.ter1.getDimy();y++){
            mvwprintw(haut,y,x,Jtxt.ter1.getXY(x,y));
        }
    }  

    //affichage des joueurs
    mvwprintw(haut,Jtxt.SP.phy.getPosy(),Jtxt.SP.phy.getPosx(), Jtxt.SP.tex.lettre);
    mvwprintw(haut,Jtxt.MP.phy.getPosy(),Jtxt.MP.phy.getPosx(), Jtxt.MP.tex.lettre);
    //cdts MP
    if(Jtxt.MP.phy.getPosx()<1) Jtxt.MP.phy.setPosx(1);
    if(Jtxt.MP.phy.getPosx()> Jtxt.ter1.getDimx()-1) Jtxt.MP.phy.setPosx(Jtxt.ter1.getDimx()-1);
    if(Jtxt.MP.phy.getPosy()>Jtxt.ter1.getDimy()-2) Jtxt.MP.phy.setPosy(Jtxt.ter1.getDimy()-2);
    if(Jtxt.MP.phy.getPosy()<1) Jtxt.MP.phy.setPosy(1);
    
    //cdts SP
    if(Jtxt.SP.phy.getPosx()<1) Jtxt.SP.phy.setPosx(1);
    if(Jtxt.SP.phy.getPosx()>Jtxt.ter1.getDimx()-1) Jtxt.SP.phy.setPosx(Jtxt.ter1.getDimx()-1);
    if(Jtxt.SP.phy.getPosy()>Jtxt.ter1.getDimy()-2) Jtxt.SP.phy.setPosy(Jtxt.ter1.getDimy()-2);
    if(Jtxt.SP.phy.getPosy()<1) Jtxt.SP.phy.setPosy(1);
    

    wrefresh(haut);
     
}

void JeuTxt :: txtBoucle(){
    
    
    float NOW = clock();
    float LAST = 0;
    float deltaTime = 0;


    //on recupere window max y et x
    int xMax = getmaxx(haut);
    int yMax = getmaxy(haut);

    // declenchement partie
   
    //initialisaton des positions de joueurs
    Jtxt.ter1.setDim(xMax,yMax);
   
    Jtxt.MP.phy.setPos(Jtxt.ter1.getDimx()/4,Jtxt.ter1.getDimy()-2);
    Jtxt.SP.phy.setPos(3*Jtxt.ter1.getDimx()/4,Jtxt.ter1.getDimy()-2);
    

    bool ok = true;
   
    do{

        txtAff();
        //deltaTime
        LAST = NOW;
        NOW = clock();
        float deltaTime = (float)((NOW - LAST)/100);

        usleep(10000);


        nodelay (haut, TRUE);
       

        //Jtxt.updatePartie(deltaTime);
        Jtxt.MP.phy.ticks(deltaTime); //gravité MP
        Jtxt.SP.phy.ticks(deltaTime); //gravité SP
        int c = wgetch(haut);

        switch (c)
        {
        //mouvements MP
            case 'z' :  Jtxt.MP.phy.setPosy(Jtxt.MP.phy.getPosy()-2); break;
            case 'q' :  Jtxt.MP.phy.setPosx(Jtxt.MP.phy.getPosx()-1); break;
            case 'd' : Jtxt.MP.phy.setPosx(Jtxt.MP.phy.getPosx()+1); break;

            //S'accroupir MP
            case 's' : Jtxt.MPClavierDown(3); break;
            //attaquer MP
            case 'e' : Jtxt.MPClavierDown(4); break;
            case 'a' : Jtxt.MPClavierDown(5); break;

            //mouvements SP
            case KEY_UP:  Jtxt.SP.phy.setPosy(Jtxt.SP.phy.getPosy()-2); break;
            case KEY_LEFT:  Jtxt.SP.phy.setPosx(Jtxt.SP.phy.getPosx()-1); break;
            case KEY_RIGHT: Jtxt.SP.phy.setPosx(Jtxt.SP.phy.getPosx()+1); break;
            //s'accroupir SP
            case KEY_DOWN: Jtxt.SPClavierDown(3); break;
            //attaquer SP
            case 'm': Jtxt.SPClavierDown(4); break;
            case 'l': Jtxt.SPClavierDown(5); break;
            //endwin 
            case 'x': ok = false; break;
        }
       
        wrefresh(haut);
        if(c=='x'){
            endwin();
        }

    } while (ok);

    
}

void JeuTxt::quit(){
  refresh();
  free(haut);
  free(bas);
    
}