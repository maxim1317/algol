TMP=tmp
# DOTS=tmp/dots

all: paint

paint: png
	@scripts/viewpng.sh
png: compile
	@scripts/dot2png.sh
compile: clean
	@mkdir -p $(TMP)
	@mkdir -p $(DOTS)
	@clang++ --std=c++11 heap.cpp -o graph
	@./graph

.PHONY: clean
clean: 
	@rm -rf $(TMP)
	@rm -f graph
	@ristretto&
	@pkill -f ristretto

.PHONY: val
val:
	@mkdir -p $(TMP)
	@mkdir -p $(DOTS)
	@clang++ --std=c++11 graph.cpp -o graph
	@valgrind -v ./graph -v

.PHONY: watch
watch:
	mplayer -mf fps=1:type=png mf://tmp/*.png
#Попытка сделалать слайдшоу из картинок

.PHONY: gt
gt: clean
	@git reset
	@git add *