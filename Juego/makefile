jueguito: main.o ventanaPrincipal.o
	g++ -o jueguito main.o ventanaPrincipal.o -lSDL2 -lSDL2_image

main.o: main.cpp ventanaPrincipal.h
	g++ -c main.cpp -lSDL2 -lSDL2_image

ventanaPrincipal.o: ventanaPrincipal.cpp ventanaPrincipal.h
	g++ -c ventanaPrincipal.cpp -lSDL2 -lSDL2_image

clean:
	rm jueguito \
		main.o ventanaPrincipal.o
