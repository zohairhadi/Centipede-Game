CXXFLAGS =	-g3 -Wall -fmessage-length=0 #-Werror

OBJS =	Flea.o ScoreBoard.o MagicSeg.o LazySeg.o Centipede.o Segment.o Bomb.o MoveableObject.o Player.o Position.o Mushroom.o GameObject.o Board.o util.o game.o

LIBS = -L/usr/X11R6/lib -L/sw/lib -L/usr/sww/lib -L/usr/sww/bin -L/usr/sww/pkg/Mesa/lib -lglut -lGLU -lGL -lX11 -lfreeimage -pthread



TARGET =	game


$(TARGET):	$(OBJS) 
	$(CXX) -o $(TARGET) $(OBJS) $(LIBS)

all:	$(TARGET)

clean:
	rm -f $(OBJS) $(TARGET)
#
#
#PROJECT_ROOT = $(dir $(abspath $(lastword $(MAKEFILE_LIST))))
#
#OBJS = MoveableObject.o Player.o Position.o Mushroom.o GameObject.o Board.o util.o game.o
#
#ifeq ($(BUILD_MODE),debug)
#	CFLAGS += -g
#else ifeq ($(BUILD_MODE),run)
#	CFLAGS += -O2
#else
#	$(error Build mode $(BUILD_MODE) not supported by this Makefile)
#endif
#
#all:	Project
#
#lab14:	$(OBJS)
#	$(CXX) -o $@ $^
#
#%.o:	$(PROJECT_ROOT)%.cpp
#	$(CXX) -c $(CFLAGS) $(CXXFLAGS) $(CPPFLAGS) -o $@ $<
#
#%.o:	$(PROJECT_ROOT)%.c
#	$(CC) -c $(CFLAGS) $(CPPFLAGS) -o $@ $<
#
#clean:
#	rm -fr lab14 $(OBJS)
