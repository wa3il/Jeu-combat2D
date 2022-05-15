#ifndef _JEUTXT_H
#define _JEUTXT_H

#include <ncurses.h>
#include "JeuTXT.h"
#include "../core/Jeu.h"

class JeuTxt{
    public:
        Jeu Jtxt;

        void txtBoucle();
        void menuaff();
        void txtAff();

    private:

};


#endif