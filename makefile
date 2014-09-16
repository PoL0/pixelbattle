all:
	g++ -std=c++11 *.cpp -lsfml-graphics -lsfml-window -lsfml-system -o app
clean:
	$(RM) *.o
	$(RM) app