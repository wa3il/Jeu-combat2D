#include "JeuTXT.h"
#include <unistd.h>

void txtAff(WINDOW * haut,Jeu & j){
    
    terrain& terrain = j.ter1;
    Personnage& persoA = j.MP;
    Personnage& persoB = j.SP;

    wrefresh(haut);

    //affichage des murs.
    for(int x=0; x<j.ter1.getDimx();++x){
        for(int y=0; y<j.ter1.getDimy();++x){
            if(terrain.getXY(x,y) == '_'){
                mvwprintw(haut,x,y," ");
            }
            if(terrain.getXY(x,y) == '#'){
                mvwprintw(haut,x,y,"#");
            }
        }
    }
    //affichage perso A
    mvwprintw(haut,persoA.getx(),persoA.gety(),"A");

    //affichage perso B
    mvwprintw(haut,persoB.getx(),persoB.gety(),"B");
}

void txtBoucle(Jeu & j){

    WINDOW *haut, *bas;

    initscr();
    haut= subwin(stdscr, j.ter1.getDimx(), j.ter1.getDimy(), 0, 0);        // Créé une fenêtre de 'LINES / 2' lignes et de COLS colonnes en 0, 0
    bas= subwin(stdscr, LINES / 2, COLS, LINES / 2, 0); // Créé la même fenêtre que ci-dessus sauf que les coordonnées changent

    box(haut, ACS_VLINE, ACS_HLINE);
    box(bas, ACS_VLINE, ACS_HLINE);

    mvwprintw(haut, 0, 3, "terrain");
    mvwprintw(bas, 1, 1, "Ceci est la fenetre du bas");

    bool ok = true;
    int c;
    do{
        txtAff(haut,j);
        usleep(10000);

        c = getch();
        switch (c)
        {
        case 122: //z
            j.actionsClavier('z');
            break;

        case 113: //q
            j.actionsClavier('q');
            break;

        case 110: //d
            j.actionsClavier('d');
            break;

        }

    } while (ok);

    wrefresh(haut);
    wrefresh(bas);

    getch();
    endwin();

    free(haut);
    free(bas);

}