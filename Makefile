loginsystem: main.o login.o database.o logged.o
	g++ main.o login.o database.o logged.o -o loginsystem

login.o: src/login.cpp src/include/login.h
	g++ -c src/login.cpp

database.o: src/database.cpp src/include/database.h
	g++ -c src/database.cpp

logged.o: src/logged.cpp src/include/logged.h
	g++ -c src/logged.cpp

main.o: src/main.cpp src/nlohmann/json.hpp
	g++ -c src/main.cpp

clean:
	del *.o