#!/bin/bash

cd ../output/
ff=`find ./* -name "*.txt"`
 
for i in $ff;
do
echo "$(basename $(dirname "$i")) : $(basename $i) : $(cat ${i})"
done



#cd ..
#cd output/U1
#echo "U1:a.txt: $(cat a.txt)"

#cd U2/U3/
#echo "U3:a.txt: $(cat a.txt)"
#echo "U3:b.txt: $(cat b.txt)"