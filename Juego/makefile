jueguito: main.o ventanaPrincipal.o ventanaPartida.o
	g++ -o jueguito main.o ventanaPrincipal.o ventanaPartida.o -lSDL2 -lSDL2_image -lSDL2_ttf

main.o: main.cpp ventanaPrincipal.h
	g++ -c main.cpp -lSDL2 -lSDL2_image -lSDL2_ttf

ventanaPrincipal.o: ventanaPrincipal.cpp ventanaPrincipal.h
	g++ -c ventanaPrincipal.cpp -lSDL2 -lSDL2_image -lSDL2_ttf

ventanaPartida.o: ventanaPartida.cpp ventanaPartida.h
	g++ -c ventanaPartida.cpp -lSDL2 -lSDL2_image -lSDL2_ttf
clean:
	rm jueguito \
		main.o ventanaPrincipal.o ventanaPartida.o
