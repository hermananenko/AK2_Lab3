all: compile

compile: object
	g++ cmd_parce_app.cpp -o cmd_parce_app
	make clean

object: 
	g++ -c cmd_parce_app.cpp

clean:
	rm -f *.o 
