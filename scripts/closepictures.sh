#!/bin/bash
for i in tmp/*.png
do
    fuser -k -TERM $i
done