CXX=g++
CXXFLAGS=-g -static


%.o:	%.cpp	%.hpp
	${CXX} ${CXXFLAGS} ${INCLUDES} -c $<


all :  bm.o BoyerMoore.o
	${CXX} ${CXXFLAGS} -o bm $^



clean:
	rm *.o *~ *.a bm

