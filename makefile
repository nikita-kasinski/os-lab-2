f=-Iinclude
obj=obj/main.o obj/thread-functions.o
run: build
	./bin/main
build: dirs $(obj)
	g++ $(f) $(obj) -o bin/main
obj/%.o: src/%.cpp
	g++ $(f) -c $< -o $@
dirs:
	mkdir -p obj bin
