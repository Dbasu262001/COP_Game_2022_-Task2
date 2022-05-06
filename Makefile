makefile:
	g++ -o game.out *.cpp -w -lSDL2 -lSDL2_image -lSDL2_ttf
del:
	rm *.out