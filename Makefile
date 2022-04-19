CC = g++
BINDIR = bin
SRCDIR = src
OBJDIR = obj
CPPFLAGS = -g -Wall

LIBSDL  = -lSDL2 -lSDL2main -lSDL2_ttf -lSDL2_image -lSDL2_mixer -lncurses
INCLUDESDL = -I/usr/include/SDL2

OBJS_mainRPG = $(OBJDIR)/main.o $(OBJDIR)/Personnage.o $(OBJDIR)/Competence.o $(OBJDIR)/Physic.o $(OBJDIR)/Vector2D.o $(OBJDIR)/JeuSDL.o $(OBJDIR)/terrain.o $(OBJDIR)/Jeu.o
OBJS_mainTXT = $(OBJDIR)/mainTXT.o $(OBJDIR)/Personnage.o $(OBJDIR)/Competence.o $(OBJDIR)/Physic.o $(OBJDIR)/Vector2D.o $(OBJDIR)/JeuTXT.o $(OBJDIR)/terrain.o $(OBJDIR)/Jeu.o 

OBJS_JeuSDL = $(OBJDIR)/JeuSDL.o $(OBJDIR)/Personnage.o $(OBJDIR)/Competence.o $(OBJDIR)/Physic.o $(OBJDIR)/Vector2D.o $(OBJDIR)/terrain.o
OBJS_JeuTXT = $(OBJDIR)/JeuTXT.o $(OBJDIR)/Personnage.o $(OBJDIR)/Competence.o $(OBJDIR)/Physic.o $(OBJDIR)/Vector2D.o $(OBJDIR)/terrain.o


all:$(BINDIR)/mainRPG $(BINDIR)/mainTXT

startSdl:$(BINDIR)/mainRPG
	./$(BINDIR)/mainRPG

startTxt:$(BINDIR)/mainTXT
	./$(BINDIR)/mainTXT

$(BINDIR)/mainTXT: $(OBJS_mainTXT)
	$(CC) $(CPPFLAGS) $(OBJS_mainTXT) -o $(BINDIR)/mainTXT -lncurses

$(BINDIR)/mainRPG: $(OBJS_mainRPG)
	$(CC) $(CPPFLAGS) $(OBJS_mainRPG) -o $(BINDIR)/mainRPG $(LIBSDL)

$(OBJDIR)/mainTXT.o:$(SRCDIR)/TXT/mainTXT.cpp $(SRCDIR)/Personnage.h $(SRCDIR)/Competence.h $(SRCDIR)/Vector2D.h $(SRCDIR)/terrain.h $(SRCDIR)/TXT/JeuTXT.h $(SRCDIR)/Jeu.h $(SRCDIR)/Physic.h
	$(CC) $(CPPFLAGS) -c $(SRCDIR)/TXT/mainTXT.cpp -o $(OBJDIR)/mainTXT.o 

$(OBJDIR)/main.o:$(SRCDIR)/main.cpp $(SRCDIR)/Personnage.h $(SRCDIR)/Competence.h $(SRCDIR)/Vector2D.h $(SRCDIR)/terrain.h $(SRCDIR)/JeuSDL.h $(SRCDIR)/Jeu.h $(SRCDIR)/Physic.h
	$(CC) $(CPPFLAGS) -c $(SRCDIR)/main.cpp -o $(OBJDIR)/main.o            

$(OBJDIR)/JeuSDL.o: $(SRCDIR)/JeuSDL.cpp $(SRCDIR)/JeuSDL.h  $(SRCDIR)/Personnage.h $(SRCDIR)/Competence.h $(SRCDIR)/Vector2D.h $(SRCDIR)/terrain.h $(SRCDIR)/Jeu.h $(SRCDIR)/Physic.h
	$(CC) $(CPPFLAGS) -c $(SRCDIR)/JeuSDL.cpp -o $(OBJDIR)/JeuSDL.o $(LIBSDL)

$(OBJDIR)/JeuTXT.o: $(SRCDIR)/TXT/JeuTXT.cpp $(SRCDIR)/TXT/JeuTXT.h $(SRCDIR)/Personnage.h $(SRCDIR)/Competence.h $(SRCDIR)/Vector2D.h $(SRCDIR)/terrain.h $(SRCDIR)/Jeu.h $(SRCDIR)/Physic.h
	$(CC) $(CPPFLAGS) -c $(SRCDIR)/TXT/JeuTXT.cpp -o $(OBJDIR)/JeuTXT.o -lncurses

$(OBJDIR)/Jeu.o: $(SRCDIR)/Jeu.cpp $(SRCDIR)/Jeu.h $(SRCDIR)/Personnage.h $(SRCDIR)/terrain.h $(SRCDIR)/Competence.h $(SRCDIR)/Vector2D.h $(SRCDIR)/Physic.h
	$(CC) $(CPPFLAGS) -c $(SRCDIR)/Jeu.cpp -o $(OBJDIR)/Jeu.o $(LIBSDL)

$(OBJDIR)/Personnage.o: $(SRCDIR)/Personnage.h $(SRCDIR)/Personnage.cpp $(SRCDIR)/Competence.h $(SRCDIR)/Vector2D.h $(SRCDIR)/terrain.h $(SRCDIR)/Physic.h
	$(CC) $(CPPFLAGS) -c $(SRCDIR)/Personnage.cpp -o $(OBJDIR)/Personnage.o

$(OBJDIR)/Physic.o: $(SRCDIR)/Physic.cpp $(SRCDIR)/Physic.h $(SRCDIR)/Vector2D.h
	$(CC) $(CPPFLAGS) -c $(SRCDIR)/Physic.cpp -o $(OBJDIR)/Physic.o

$(OBJDIR)/Competence.o: $(SRCDIR)/Competence.cpp $(SRCDIR)/Competence.h
	$(CC) $(CPPFLAGS) -c $(SRCDIR)/Competence.cpp -o $(OBJDIR)/Competence.o

$(OBJDIR)/terrain.o: $(SRCDIR)/terrain.cpp $(SRCDIR)/terrain.h
	$(CC) $(CPPFLAGS) -c $(SRCDIR)/terrain.cpp -o $(OBJDIR)/terrain.o

$(OBJDIR)/Vector2D.o: $(SRCDIR)/Vector2D.cpp $(SRCDIR)/Vector2D.h
	$(CC) $(CPPFLAGS) -c $(SRCDIR)/Vector2D.cpp -o $(OBJDIR)/Vector2D.o



clean:
	rm $(OBJDIR)/*.o