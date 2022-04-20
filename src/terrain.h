#include <iostream>

class terrain{
    private:
        int dimx,dimy; // dimension du terrain
        char ter[10][17]; //terrain

    public:
        /** Constructeur/destructeur
         * @brief Construct a new terrain object
         * 
         */
        terrain();
        ~terrain(); 

        /** Fonction posisvalide
         * @brief position est valide (parametre : x et y ) => vrai ou faux
         *  
         */
        bool posisvalide(int x, int y);

        /** Fonction getXY
         * @brief caractère à une case (parametre : x et y ) => charactère
         * 
         */
        char getXY(int x,int y);

        /** Mutateur et accesseur
         * @brief getDimension () => entier
         * 
         */
        int getDimx();
        int getDimy();

};