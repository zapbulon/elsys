all: drawing

Point.o: Point.cpp Point.hpp
Circle.o: Circle.cpp Circle.hpp Shape.hpp Point.hpp
Rectangle.o: Rectangle.cpp Rectangle.hpp Shape.hpp Point.hpp
Drawing.o: Drawing.cpp Drawing.hpp Shape.hpp
main.o: main.cpp Drawing.hpp Rectangle.hpp Circle.hpp Shape.hpp Point.hpp

drawing: main.o Drawing.o Rectangle.o Circle.o Point.o
	g++ main.o Drawing.o Rectangle.o Circle.o Point.o -o drawing

clean:
	rm -f *.o drawing