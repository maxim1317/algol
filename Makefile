all: png
	xdg-open tmp/graph1.png
	xdg-open tmp/graph2.png
png: compile
	mkdir -p tmp
	dot -Tpng graph1.dot -o tmp/graph1.png
	dot -Tpng graph2.dot -o tmp/graph2.png
compile:
	clang++ --std=c++11 graph.cpp -o graph
	./graph
clean:
	rm -r tmp/
	rm graph 