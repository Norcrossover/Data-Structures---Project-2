CC = g++
CPPFLAGS = -g -std=c++11 -Wall
OBJS = app.o mgr.o line.o group.o stack.o contact.o

app: $(OBJS)

app.o: line.h group.h stack.h contact.h mgr.h

mgr.o: line.h group.h stack.h contact.h

line.o: line.h group.h stack.h contact.h 

group.o: group.h stack.h contact.h

stack.o: stack.h contact.h

contact.o: contact.h


clean:
	rm *.o app
