CC = g++
BINDIR = bin
SRCDIR = src
OBJDIR = obj
CPPFLAGS = -g -Wall

LIBSDL  = -lSDL2 -lSDL2main -lSDL2_ttf -lSDL2_image -lSDL2_mixer
INCLUDESDL = -I/usr/include/SDL2

OBJS_mainRPG = $(OBJDIR)/main.o $(OBJDIR)/Personnage.o $(OBJDIR)/Arme.o
OBJS_jeu = $(OBJDIR)/jeu.o $(OBJDIR)/Personnage.o $(OBJDIR)/Arme.o

all : $(BINDIR)/mainRPG $(BINDIR)/jeu

$(BINDIR)/jeu : $(OBJS_jeu)
	$(CC) $(CPPFLAGS) $(OBJS_jeu) -o $(BINDIR)/jeu $(LIBSDL)

$(BINDIR)/mainRPG: $(OBJS_mainRPG)
	$(CC) $(CPPFLAGS) $(OBJS_mainRPG) -o $(BINDIR)/mainRPG $(LIBSDL)

$(OBJDIR)/jeu.o: $(SRCDIR)/jeu.cpp $(SRCDIR)/jeu.h  $(SRCDIR)/Personnage.h $(SRCDIR)/Arme.h 
	$(CC) $(CPPFLAGS) -c $(SRCDIR)/jeu.cpp -o $(OBJDIR)/jeu.o

$(OBJDIR)/main.o: $(SRCDIR)/main.cpp $(SRCDIR)/Personnage.h $(SRCDIR)/Arme.h
	$(CC) $(CPPFLAGS) -c $(SRCDIR)/main.cpp -o $(OBJDIR)/main.o

$(OBJDIR)/Personnage.o: $(SRCDIR)/Personnage.h $(SRCDIR)/Personnage.cpp $(SRCDIR)/Arme.h
	$(CC) $(CPPFLAGS) -c $(SRCDIR)/Personnage.cpp -o $(OBJDIR)/Personnage.o

$(OBJDIR)/Arme.o: $(SRCDIR)/Arme.cpp $(SRCDIR)/Arme.h
	$(CC) $(CPPFLAGS) -c $(SRCDIR)/Arme.cpp -o $(OBJDIR)/Arme.o




clean:
	rm $(OBJDIR)/*.o
