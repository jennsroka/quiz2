#Jenn Sroka
#quiz 2 makefile

all: 
	make build
	make doczip

build:
	g++ *.cc

doc:
	doxygen Doxygen

myexe: college.o course.o collegemain.o
	g++ college.o course.o collegemain.o -o myexe

college.o: college.cc
	g++ -c college.cc

course.o: course.cc
	g++ -c course.cc

collegemain.o: collegemain.cc
	g++ -c collegemain.cc

doczip: 
	tar.gz

clean:
	rm *.o myexe
	rm -rf html
	rm -rf latex
