all:server client
server:server.cpp tcp.hpp
	g++ server.cpp -o server -lpthread

client:client.cpp tcp.hpp
	g++ client.cpp -o client

.PYONHY:clean
clean:
	rm server client
