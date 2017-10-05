all: png
	@ristretto tmp/graph1.png &
	@ristretto tmp/graph2.png &
png: compile
	@dot -Tpng tmp/graph1.dot -o tmp/graph1.png
	@dot -Tpng tmp/graph2.dot -o tmp/graph2.png
compile:
	@mkdir -p tmp
	@clang++ --std=c++11 graph.cpp -o graph
	@./graph

.PHONY: clean
clean: 
	@rm -rf tmp/
	@rm -f graph 
	@pkill -f ristretto
