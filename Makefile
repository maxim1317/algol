TMP=tmp
DOTS=tmp/dots

all: paint

paint: png
	@scripts/viewpng.sh
png: compile
	@scripts/dot2png.sh
compile:
	@mkdir -m 777 -p $(TMP)
	@mkdir -m 777 -p $(DOTS)
	@clang++ --std=c++11 graph.cpp -o graph
	@./graph

.PHONY: clean
clean: 
	@rm -rf $(TMP)
	@rm -f graph 
	@pkill -f ristretto

.PHONY: watch
watch:
	mplayer -mf fps=1:type=png mf://tmp/*.png