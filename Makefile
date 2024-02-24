OBJ = main.o connect.o escape.o heroes.o flyers.o hollow.o utils.o 
EXE = gamestimulator
CC = gcc -Wall 

$(EXE):	$(OBJ)
	$(CC) -o $(EXE) $(OBJ)

main.o:	main.c defs.h
	$(CC) -c main.c

connect.o:	connect.c defs.h
	$(CC) -c connect.c

escape.o: escape.c defs.h
	$(CC) -c escape.c

heroes.o: heroes.c defs.h
	$(CC) -c heroes.c

flyers.o: flyers.c defs.h
	$(CC) -c flyers.c

hollow.o: hollow.c defs.h
	$(CC) -c hollow.c

utils.o: utils.c defs.h
	$(CC) -c utils.c

clean:
	rm -f $(EXE) $(OBJ)

