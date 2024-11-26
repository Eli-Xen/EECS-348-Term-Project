#we will see if i know how to make this

#the following two lines describe how the object files (.o files) get to the destination file (implementation)
implementation: main.o inputProcessor.o expressionEval.o parenthesis.o expo.o multDiv.o modulus.o addSubtract.o
  g++ main.o inputProcessor.o expressionEval.o parenthesis.o expo.o multDiv.o modulus.o addSubtract.o -o implementation

#the following expressions describe how the object files are gotten from the source code
main.o: main.cpp
  g++ -c main.cpp

inputProcessor.o: inputProcessor.cpp
  g++ -c inputProcessor.cpp

expressionEval.o: expressionEval.cpp
  g++ -c expressionEval.cpp

parenthesis.o: parenthesis.cpp
  g++ -c parenthesis.cpp

expo.o: expo.cpp
  g++ -c expo.cpp

multDiv.o: multDiv.cpp
  g++ -c multDiv.cpp

modulus.o: modulus.cpp
  g++ -c modulus.cpp

addSubtract.o: addSubtract.cpp
  g++ -c addSubtract.cpp

#clears out any object files
clean:
  rm *.o
