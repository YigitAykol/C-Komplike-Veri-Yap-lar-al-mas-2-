hepsi: derle calistir

derle:
	g++ -I ./include/ -o ./lib/Node.o -c ./src/Node.cpp

	g++ -I ./include/ -o ./lib/avlNode.o -c ./src/avlNode.cpp
	
	g++ -I ./include/ -o ./lib/AvlAgaci.o -c ./src/AvlAgaci.cpp

	g++ -I ./include/ -o ./lib/riiAvl.o -c ./src/riiAvl.cpp

	g++ -I ./include/ -o ./lib/Stack.o -c ./src/Stack.cpp
	
	g++ -I ./include/ -o ./bin/Test ./lib/Node.o ./lib/avlNode.o ./lib/AvlAgaci.o ./lib/riiAvl.o ./lib/Stack.o ./src/Test.cpp
	
calistir:
	./bin/Test
