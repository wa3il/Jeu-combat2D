CC = g++
BINDIR = bin
SRCDIR = src
OBJDIR = obj
CPPFLAGS = -g -Wall
LIBSDL  = -lSDL2 -lSDL2main -lSDL2_ttf -lSDL2_image -lSDL2_mixer
INCLUDESDL = 


all : $(BINDIR)/mainRPG


$(BINDIR)/mainRPG: $(OBJDIR)/main.o $(OBJDIR)/Personnage.o $(OBJDIR)/Arme.o
	$(CC) $(CPPFLAGS) $(OBJDIR)/main.o $(OBJDIR)/Personnage.o $(OBJDIR)/Arme.o -o $(BINDIR)/mainRPG $(LIBSDL)

$(OBJDIR)/main.o: $(SRCDIR)/main.cpp $(SRCDIR)/Personnage.h $(SRCDIR)/Arme.h
	$(CC) $(CPPFLAGS) -c $(SRCDIR)/main.cpp -o $(OBJDIR)/main.o

$(OBJDIR)/Personnage.o: $(SRCDIR)/Personnage.h $(SRCDIR)/Personnage.cpp $(SRCDIR)/Arme.h
	$(CC) $(CPPFLAGS) -c $(SRCDIR)/Personnage.cpp -o $(OBJDIR)/Personnage.o

$(OBJDIR)/Arme.o: $(SRCDIR)/Arme.cpp $(SRCDIR)/Arme.h
	$(CC) $(CPPFLAGS) -c $(SRCDIR)/Arme.cpp -o $(OBJDIR)/Arme.o




clean:
	rm $(OBJDIR)/*.o
