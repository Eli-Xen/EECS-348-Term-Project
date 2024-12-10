
implementation: AEE.o inputProcessor.o expo.o multDiv.o modulus.o addSubtract.o expressionTree.o
	g++ AEE.o inputProcessor.o expo.o multDiv.o modulus.o addSubtract.o expressionTree.o -o implementation


AEE.o: AEE.cpp
	g++ -c AEE.cpp


inputProcessor.o: inputProcessor.cpp
	g++ -c inputProcessor.cpp


expo.o: expo.cpp
	g++ -c expo.cpp


multDiv.o: multDiv.cpp
	g++ -c multDiv.cpp


modulus.o: modulus.cpp
	g++ -c modulus.cpp


addSubtract.o: addSubtract.cpp
	g++ -c addSubtract.cpp

expressionTree.o: expressionTree.cpp
	g++ -c expressionTree.cpp

clean:
	rm -f *.o implementation