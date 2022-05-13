CC = g++
BINDIR = bin
SRCDIR = src

COREDIR = core
SDLDIR = sdl
TXTDIR = txt

OBJDIR = obj
CPPFLAGS = -g -Wall

LIBSDL  = -lSDL2 -lSDL2main -lSDL2_ttf -lSDL2_image -lSDL2_mixer -lncurses
INCLUDESDL = -I/usr/include/SDL2

OBJS_mainSDL = $(OBJDIR)/mainSDL.o $(OBJDIR)/Personnage.o $(OBJDIR)/Competence.o $(OBJDIR)/Physic.o $(OBJDIR)/Vector2D.o $(OBJDIR)/JeuSDL.o $(OBJDIR)/Terrain.o $(OBJDIR)/Jeu.o $(OBJDIR)/Menu.o
OBJS_mainTXT = $(OBJDIR)/mainTXT.o $(OBJDIR)/Personnage.o $(OBJDIR)/Competence.o $(OBJDIR)/Physic.o $(OBJDIR)/Vector2D.o $(OBJDIR)/JeuTXT.o $(OBJDIR)/Terrain.o $(OBJDIR)/Jeu.o 

OBJS_JeuSDL = $(OBJDIR)/JeuSDL.o $(OBJDIR)/Personnage.o $(OBJDIR)/Competence.o $(OBJDIR)/Physic.o $(OBJDIR)/Vector2D.o $(OBJDIR)/Terrain.o $(OBJDIR)/Menu.o
OBJS_JeuTXT = $(OBJDIR)/JeuTXT.o $(OBJDIR)/Personnage.o $(OBJDIR)/Competence.o $(OBJDIR)/Physic.o $(OBJDIR)/Vector2D.o $(OBJDIR)/Terrain.o


all:$(BINDIR)/mainSDL $(BINDIR)/mainTXT

startSdl:$(BINDIR)/mainSDL
	./$(BINDIR)/mainSDL

startTxt:$(BINDIR)/mainTXT
	./$(BINDIR)/mainTXT

$(BINDIR)/mainTXT: $(OBJS_mainTXT)
	$(CC) $(CPPFLAGS) $(OBJS_mainTXT) -o $(BINDIR)/mainTXT -lncurses

$(BINDIR)/mainSDL: $(OBJS_mainSDL)
	$(CC) $(CPPFLAGS) $(OBJS_mainSDL) -o $(BINDIR)/mainSDL $(LIBSDL)

$(OBJDIR)/mainTXT.o:$(SRCDIR)/$(TXTDIR)/mainTXT.cpp $(SRCDIR)/Personnage.h $(SRCDIR)/Competence.h $(SRCDIR)/Vector2D.h $(SRCDIR)/Terrain.h $(SRCDIR)/$(TXTDIR)/JeuTXT.h $(SRCDIR)/$(COREDIR)/Jeu.h $(SRCDIR)/Physic.h
	$(CC) $(CPPFLAGS) -c $(SRCDIR)/$(TXTDIR)/mainTXT.cpp -o $(OBJDIR)/mainTXT.o 

$(OBJDIR)/mainSDL.o:$(SRCDIR)/$(SDLDIR)/mainSDL.cpp $(SRCDIR)/Personnage.h $(SRCDIR)/Competence.h $(SRCDIR)/Vector2D.h $(SRCDIR)/Terrain.h $(SRCDIR)/$(SDLDIR)/JeuSDL.h $(SRCDIR)/$(COREDIR)/Jeu.h $(SRCDIR)/Physic.h
	$(CC) $(CPPFLAGS) -c $(SRCDIR)/$(SDLDIR)/mainSDL.cpp -o $(OBJDIR)/mainSDL.o            

$(OBJDIR)/JeuSDL.o: $(SRCDIR)/$(SDLDIR)/JeuSDL.cpp $(SRCDIR)/$(SDLDIR)/JeuSDL.h  $(SRCDIR)/Personnage.h $(SRCDIR)/Competence.h $(SRCDIR)/Vector2D.h $(SRCDIR)/Terrain.h $(SRCDIR)/$(COREDIR)/Jeu.h $(SRCDIR)/Physic.h $(SRCDIR)/Menu.h
	$(CC) $(CPPFLAGS) -c $(SRCDIR)/$(SDLDIR)/JeuSDL.cpp -o $(OBJDIR)/JeuSDL.o $(LIBSDL)

$(OBJDIR)/JeuTXT.o: $(SRCDIR)/$(TXTDIR)/JeuTXT.cpp $(SRCDIR)/$(TXTXDIR)/JeuTXT.h $(SRCDIR)/Personnage.h $(SRCDIR)/Competence.h $(SRCDIR)/Vector2D.h $(SRCDIR)/Terrain.h $(SRCDIR)/Jeu.h $(SRCDIR)/Physic.h
	$(CC) $(CPPFLAGS) -c $(SRCDIR)/$(SDLDIR)/JeuTXT.cpp -o $(OBJDIR)/JeuTXT.o -lncurses

$(OBJDIR)/Jeu.o: $(SRCDIR)/$(COREDIR)/Jeu.cpp $(SRCDIR)/$(COREDIR)/Jeu.h $(SRCDIR)/Personnage.h $(SRCDIR)/Terrain.h $(SRCDIR)/Competence.h $(SRCDIR)/Vector2D.h $(SRCDIR)/Physic.h $(SRCDIR)/Menu.h
	$(CC) $(CPPFLAGS) -c $(SRCDIR)/$(COREDIR)/Jeu.cpp -o $(OBJDIR)/Jeu.o $(LIBSDL)

$(OBJDIR)/Personnage.o: $(SRCDIR)/Personnage.h $(SRCDIR)/Personnage.cpp $(SRCDIR)/Competence.h $(SRCDIR)/Vector2D.h $(SRCDIR)/Terrain.h $(SRCDIR)/Physic.h
	$(CC) $(CPPFLAGS) -c $(SRCDIR)/Personnage.cpp -o $(OBJDIR)/Personnage.o

$(OBJDIR)/Physic.o: $(SRCDIR)/Physic.cpp $(SRCDIR)/Physic.h $(SRCDIR)/Vector2D.h
	$(CC) $(CPPFLAGS) -c $(SRCDIR)/Physic.cpp -o $(OBJDIR)/Physic.o

$(OBJDIR)/Competence.o: $(SRCDIR)/Competence.cpp $(SRCDIR)/Competence.h
	$(CC) $(CPPFLAGS) -c $(SRCDIR)/Competence.cpp -o $(OBJDIR)/Competence.o

$(OBJDIR)/Terrain.o: $(SRCDIR)/Terrain.cpp $(SRCDIR)/Terrain.h
	$(CC) $(CPPFLAGS) -c $(SRCDIR)/Terrain.cpp -o $(OBJDIR)/Terrain.o

$(OBJDIR)/Menu.o: $(SRCDIR)/Menu.cpp $(SRCDIR)/Menu.h
	$(CC) $(CPPFLAGS) -c $(SRCDIR)/Menu.cpp -o $(OBJDIR)/Menu.o

$(OBJDIR)/Vector2D.o: $(SRCDIR)/Vector2D.cpp $(SRCDIR)/Vector2D.h
	$(CC) $(CPPFLAGS) -c $(SRCDIR)/Vector2D.cpp -o $(OBJDIR)/Vector2D.o



clean:
	rm $(OBJDIR)/*.o