all:
	g++ -c main.cpp
	g++ main.o -o app -lsfml-graphics -lsfml-window -lsfml-system
clean:
	$(RM) main.o
	$(RM) app