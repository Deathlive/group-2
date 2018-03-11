#!/bin/bash

cd ../output
rm -rf U1

mkdir U1
mkdir U1/U2
mkdir U1/U2/U3
mkdir U1/U2/U4

touch U1/a.txt
touch U1/U2/U3/a.txt
touch U1/U2/U3/b.txt

echo "Script1 Finish"