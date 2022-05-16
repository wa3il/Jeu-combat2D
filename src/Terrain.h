#include <iostream>
#include <string>
#include "Texture.h"
#include"Constantes.h"
#include"Vector2D.h"


class terrain{
    private:
        int dimx,dimy; // dimension du terrain
        const char* caract[WINDOW_SIZE_WIDTH][WINDOW_SIZE_HEIGHT]; //terrain
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
        const char* getXY(int x,int y);

        /** Mutateur et accesseur
         * @brief getDimension () => entier
         * 
         */
        int getDimx();
        int getDimy();

       
        void setDim(int dimx, int dimy);
        void setCaract(int x,int y ,const char* car);

        Texture tex;

};

class Tuiles{

    private:

    public:
    Tuiles();
    Texture tex;
    Vector2D pos;
    int width , height;
    
};