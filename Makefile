all: png
	xdg-open graph.png
png: compile
	dot -Tpng graph.dot -o graph.png
compile:
	clang++ --std=c++11 graph.cpp -o graph
	./graph
clean:
	rm *.dot
	rm *.png
	rm graph 