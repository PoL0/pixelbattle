all:
	g++ *.cpp -lsfml-graphics -lsfml-window -lsfml-system -o app
clean:
	$(RM) *.o
	$(RM) app