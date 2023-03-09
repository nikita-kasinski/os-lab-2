f=-Iinclude
obj=obj/main.o
run: build
	./bin/main
build: dirs obj/main.o
	g++ $(f) $(obj) -o bin/main
obj/%.o: src/%.cpp
	g++ -c $< -o $@
dirs:
	mkdir -p obj bin
