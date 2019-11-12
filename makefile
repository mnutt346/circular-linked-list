###
### @file - lab7_makefile
### @author - Michael Nutt <nuttm@oregonstate.edu>
### @description - makefile for Lab 7 - Queue (Circular Linked-List)

#
# Queue (Circular Linked-List)
#

CXX = g++

CFLAGS = -std=c++11

.PHONY: clean

main: main.o menu.o inputValidation.o queue.o
	$(CXX) $(CFLAGS) -g main.o menu.o inputValidation.o queue.o -o queue

main.o: main.cpp
	$(CXX) $(CFLAGS) -c main.cpp
	
menu.o: menu.cpp menu.hpp
	$(CXX) $(CFLAGS) -c menu.cpp

inputValidation.o: inputValidation.cpp inputValidation.hpp
	$(CXX) $(CFLAGS) -c inputValidation.cpp

queue.o: queue.cpp queue.hpp
	$(CXX) $(CFLAGS) -c queue.cpp

clean:
	rm *.o queue