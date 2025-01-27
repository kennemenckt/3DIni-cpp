# Build object dependencies
g++ -c 3D.cpp -o 3D.o
g++ -c Corden.cpp -o Corden.o
g++ -c GraphAdapter.cpp -o GraphAdapter.o
g++ -c KeyboardAdapter.cpp -o KeyboardAdapter.o
g++ -c KeyReader.cpp -o KeyReader.o
g++ -c VertexList.cpp -o VertexList.o
g++ -c FaceList.cpp -o FaceList.o
g++ -c Obj3D.cpp -o Obj3D.o
g++ -c Sprte.cpp -o Sprte.o
g++ -c MyTextGraph.cpp -o MyTextGraph.o

# Build main class
g++ 3Dini.cpp 3D.o Corden.o GraphAdapter.o KeyboardAdapter.o KeyReader.o VertexList.o FaceList.o Obj3D.o Sprte.o MyTextGraph.o -o 3Dini.out