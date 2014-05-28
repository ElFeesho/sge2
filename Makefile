OBJS=main.o graphics.o inputevents.o engine.o scriptengine.o
LIBS=-llua `sdl-config --libs`
CXXFLAGS=-g -std=c++11 `sdl-config --cflags`
PROG=sgetest

all:$(OBJS)
	g++ -o $(PROG) $(OBJS) $(LIBS)

%o:%cpp
	g++ $(CXXFLAGS) $< -c

clean:
	rm -f $(PROG) $(OBJS)
