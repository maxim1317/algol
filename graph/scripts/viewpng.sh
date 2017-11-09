#!/bin/bash
for i in tmp/*.png
do
    xdg-open $i &
done