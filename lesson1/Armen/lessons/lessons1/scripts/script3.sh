#!/bin/bash

cd ..
cd output
rm U1/a.txt

cd U1/U2/U3/
mv a.txt ../U4/a.txt
mv b.txt ../U4/b.txt

echo "Mission Complete"