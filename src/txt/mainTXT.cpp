#include <ncurses.h>
#include <iostream>
#include "JeuTXT.h"

int main(int argc,char ** argv){


	JeuTxt J;
	J.init();
	J.update();
	//J.quit();


	return 0;
}