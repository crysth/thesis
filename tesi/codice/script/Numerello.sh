#!/bin/bash

bin="/home/cry/DragQueen/bin"
folderdata="data/DotInheritanceNT/"
foldernumeri="Numerelli"

echo "Controllo i loops ..."
for i in `ls $folderdata`
do
	acyclic -n $folderdata/$i
	echo $i $? | awk '$2==1'
done > data/FilesWithLoops.dat

echo "Elimino file molesti ..."
for j in `awk '{print $1}' data/FilesWithLoops.dat`
do
	echo "elimino $j"
	rm $folderdata/$j
done

elenco=`ls $folderdata/`
mkdir $foldernumeri

echo "Numerello!"
for i in $elenco
do
	if [ ! -f $foldernumeri/$i ]
	then
		nome=`echo $i | cut -d"." -f1`
		cat $folderdata/$i | ccomps -x | gvpr -f $bin/Numerello.gv > $foldernumeri/$nome.dat
		echo $i;
	fi
done
