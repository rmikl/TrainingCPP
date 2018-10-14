#!/bin/bash


for i in `find -type f -name "*cpp"`;do g++ $i -Wall -Werror -o software; done

