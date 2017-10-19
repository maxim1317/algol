#!/bin/bash
for i in tmp/dots/*.dot
do
    dot -Tpng $i -o ${i%.dot}.png
    mv ${i%.dot}.png tmp/
done