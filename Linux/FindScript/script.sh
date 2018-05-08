#!/bin/bash

rm -rf Folder/folder1 output.txt
cd Folder

#############################################
#Create folder
mkdir folder1 folder1/folder2 folder1/folder3 folder1/folder2/midfolder1 folder1/folder2/midfolder2 folder1/folder2/midfolder3 folder1/folder2/midfolder2/endfolder1 folder1/folder2/midfolder2/endfolder2 folder1/folder2/midfolder2/endfolder3

#Adding txt files to created folders
touch ../output.txt folder1/file1.txt folder1/folder2/file2.txt folder1/folder3/file3.txt folder1/folder2/midfolder1/file4.txt folder1/folder2/midfolder2/file5.txt folder1/folder2/midfolder3/file6.txt folder1/folder2/midfolder2/endfolder1/file7.txt folder1/folder2/midfolder2/endfolder2/file8.txt folder1/folder2/midfolder2/endfolder3/file9.txt

#Adding text
echo "admin" > folder1/file1.txt 
echo "asd" > folder1/folder2/file2.txt
echo "admin" > folder1/folder3/file3.txt
echo "dsa" > folder1/folder2/midfolder1/file4.txt
echo "asd" > folder1/folder2/midfolder2/file5.txt
echo "admin" > folder1/folder2/midfolder3/file6.txt
echo "qwerty" > folder1/folder2/midfolder2/endfolder1/file7.txt
echo "asd" > folder1/folder2/midfolder2/endfolder2/file8.txt
echo "admin" > folder1/folder2/midfolder2/endfolder3/file9.txt
#############################################

ff=`find ./* -name "*.txt"`

for i in $ff;
do
echo "$(basename $(dirname "$i")) : $(basename $i) : $(cat ${i})" >> ../output.txt
done


echo "******************************"
echo -e "Displaying the sorted file\n"
echo "******************************"
sort ../output.txt
echo "******************************"