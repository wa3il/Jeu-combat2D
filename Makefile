CC = g++
BINDIR = bin
SRCDIR = src
OBJDIR = obj
CPPFLAGS = -g -Wall

LIBSDL  = -lSDL2 -lSDL2main -lSDL2_ttf -lSDL2_image -lSDL2_mixer
INCLUDESDL = -I/usr/include/SDL2

OBJS_mainRPG = $(OBJDIR)/main.o $(OBJDIR)/Personnage.o $(OBJDIR)/Competence.o $(OBJDIR)/Vector2D.o $(OBJDIR)/Jeu.o
OBJS_Jeu = $(OBJDIR)/Jeu.o $(OBJDIR)/Personnage.o $(OBJDIR)/Competence.o $(OBJDIR)/Vector2D.o 

all:$(BINDIR)/mainRPG

startSdl:$(BINDIR)/mainRPG
	./$(BINDIR)/mainRPG


$(BINDIR)/mainRPG: $(OBJS_mainRPG)
	$(CC) $(CPPFLAGS) $(OBJS_mainRPG) -o $(BINDIR)/mainRPG $(LIBSDL)

$(OBJDIR)/main.o:$(SRCDIR)/main.cpp $(SRCDIR)/Personnage.h $(SRCDIR)/Competence.h $(SRCDIR)/Vector2D.h $(SRCDIR)/Jeu.h 
	$(CC) $(CPPFLAGS) -c $(SRCDIR)/main.cpp -o $(OBJDIR)/main.o            

$(OBJDIR)/Jeu.o: $(SRCDIR)/Jeu.cpp $(SRCDIR)/Jeu.h  $(SRCDIR)/Personnage.h $(SRCDIR)/Competence.h $(SRCDIR)/Vector2D.h
	$(CC) $(CPPFLAGS) -c $(SRCDIR)/Jeu.cpp -o $(OBJDIR)/Jeu.o $(LIBSDL)

$(OBJDIR)/Personnage.o: $(SRCDIR)/Personnage.h $(SRCDIR)/Personnage.cpp $(SRCDIR)/Competence.h $(SRCDIR)/Vector2D.h
	$(CC) $(CPPFLAGS) -c $(SRCDIR)/Personnage.cpp -o $(OBJDIR)/Personnage.o

$(OBJDIR)/Competence.o: $(SRCDIR)/Competence.cpp $(SRCDIR)/Competence.h
	$(CC) $(CPPFLAGS) -c $(SRCDIR)/Competence.cpp -o $(OBJDIR)/Competence.o

$(OBJDIR)/Vector2D.o: $(SRCDIR)/Vector2D.cpp $(SRCDIR)/Vector2D.h
	$(CC) $(CPPFLAGS) -c $(SRCDIR)/Vector2D.cpp -o $(OBJDIR)/Vector2D.o


clean:
	rm $(OBJDIR)/*.o