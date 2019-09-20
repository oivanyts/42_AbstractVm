#!/usr/bin/env bash
for file in ./tests/*
do
echo "$file"
if [ -d "$file" ]
then
echo "$file is a directory"
else
echo "$file"
echo  "\n\nHIS<<<<<<<<<<<<<"
../AbstractVM/abstractVM  $file
echo  "\nMY>>>>>>>>>>>>>>"
./abstractVm  $file
echo  "\n"
fi
done
echo  "\n\tTEST END\n"
