CC = g++
BINDIR = bin
SRCDIR = src

COREDIR = src/core
SDLDIR  = src/sdl
TXTDIR  = src/txt

OBJDIR = obj
CPPFLAGS = -g -Wall

LIBSDL  = -lSDL2 -lSDL2main -lSDL2_ttf -lSDL2_image -lSDL2_mixer -lncurses
INCLUDESDL = -I/usr/include/SDL2

OBJS_JEU     = $(OBJDIR)/Jeu.o $(OBJDIR)/Personnage.o $(OBJDIR)/Competence.o $(OBJDIR)/Physic.o $(OBJDIR)/Vector2D.o $(OBJDIR)/Terrain.o $(OBJDIR)/Menu.o $(OBJDIR)/Texture.o
OBJS_mainSDL = $(OBJDIR)/mainSDL.o $(OBJDIR)/JeuSDL.o $(OBJS_JEU)
OBJS_mainTXT = $(OBJDIR)/mainTXT.o $(OBJDIR)/JeuTXT.o $(OBJS_JEU)


all:$(BINDIR)/mainSDL $(BINDIR)/mainTXT


startSdl:$(BINDIR)/mainSDL
	./$(BINDIR)/mainSDL

startTxt:$(BINDIR)/mainTXT
	./$(BINDIR)/mainTXT


#CORE
$(OBJDIR)/Jeu.o: $(COREDIR)/Jeu.cpp $(COREDIR)/Jeu.h 
	$(CC) $(CPPFLAGS) -c $(COREDIR)/Jeu.cpp -o $(OBJDIR)/Jeu.o $(LIBSDL)


#Version TXT
$(BINDIR)/mainTXT: $(OBJS_mainTXT)
	$(CC) $(CPPFLAGS) $(OBJS_mainTXT) -o $(BINDIR)/mainTXT -lncurses

$(OBJDIR)/mainTXT.o:$(TXTDIR)/mainTXT.cpp 
	$(CC) $(CPPFLAGS) -c $(TXTDIR)/mainTXT.cpp -o $(OBJDIR)/mainTXT.o 

$(OBJDIR)/JeuTXT.o: $(TXTDIR)/JeuTXT.cpp $(TXTDIR)/JeuTXT.h 
	$(CC) $(CPPFLAGS) -c $(TXTDIR)/JeuTXT.cpp -o $(OBJDIR)/JeuTXT.o -lncurses


#version SDL
$(BINDIR)/mainSDL: $(OBJS_mainSDL)
	$(CC) $(CPPFLAGS) $(OBJS_mainSDL) -o $(BINDIR)/mainSDL $(LIBSDL)

$(OBJDIR)/mainSDL.o:$(SDLDIR)/mainSDL.cpp 
	$(CC) $(CPPFLAGS) -c $(SDLDIR)/mainSDL.cpp -o $(OBJDIR)/mainSDL.o            

$(OBJDIR)/JeuSDL.o: $(SDLDIR)/JeuSDL.cpp $(SDLDIR)/JeuSDL.h 
	$(CC) $(CPPFLAGS) -c $(SDLDIR)/JeuSDL.cpp -o $(OBJDIR)/JeuSDL.o $(LIBSDL)


#Fichiers utilisés
$(OBJDIR)/Personnage.o: $(SRCDIR)/Personnage.h $(SRCDIR)/Personnage.cpp 
	$(CC) $(CPPFLAGS) -c $(SRCDIR)/Personnage.cpp -o $(OBJDIR)/Personnage.o

$(OBJDIR)/Physic.o: $(SRCDIR)/Physic.cpp $(SRCDIR)/Physic.h 
	$(CC) $(CPPFLAGS) -c $(SRCDIR)/Physic.cpp -o $(OBJDIR)/Physic.o

$(OBJDIR)/Competence.o: $(SRCDIR)/Competence.cpp $(SRCDIR)/Competence.h
	$(CC) $(CPPFLAGS) -c $(SRCDIR)/Competence.cpp -o $(OBJDIR)/Competence.o

$(OBJDIR)/Terrain.o: $(SRCDIR)/Terrain.cpp $(SRCDIR)/Terrain.h
	$(CC) $(CPPFLAGS) -c $(SRCDIR)/Terrain.cpp -o $(OBJDIR)/Terrain.o

$(OBJDIR)/Menu.o: $(SRCDIR)/Menu.cpp $(SRCDIR)/Menu.h
	$(CC) $(CPPFLAGS) -c $(SRCDIR)/Menu.cpp -o $(OBJDIR)/Menu.o

$(OBJDIR)/Vector2D.o: $(SRCDIR)/Vector2D.cpp $(SRCDIR)/Vector2D.h
	$(CC) $(CPPFLAGS) -c $(SRCDIR)/Vector2D.cpp -o $(OBJDIR)/Vector2D.o

$(OBJDIR)/Texture.o: $(SRCDIR)/Texture.cpp $(SRCDIR)/Texture.h
	$(CC) $(CPPFLAGS) -c $(SRCDIR)/Texture.cpp -o $(OBJDIR)/Texture.o


clean:
	rm $(OBJDIR)/*.o