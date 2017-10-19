all: png
	@ristretto tmp/graph1.png &
	@ristretto tmp/graph2.png &
	@ristretto tmp/graph3.png &
png: compile
	@dot -Tpng tmp/dots/graph1.dot -o tmp/graph1.png
	@dot -Tpng tmp/dots/graph2.dot -o tmp/graph2.png
	@dot -Tpng tmp/dots/graph3.dot -o tmp/graph3.png
compile:
	@mkdir -p tmp
	@mkdir -p tmp/dots
	@clang++ --std=c++11 graph.cpp -o graph
	@./graph

.PHONY: clean
clean: 
	@rm -rf tmp/
	@rm -f graph 
	@pkill -f ristretto
