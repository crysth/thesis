#!/bin/bash

bin="/home/cry/DragQueen/bin/"
from="data/DotInheritance/"
to="data/DotInheritanceNT/"

echo "Controllo i loops ..."
for i in `ls $from`
do
	acyclic -n $from/$i
	echo $i $? | grep -v 0
done > data/OriginalFilesWithLoops.dat

echo "Elimino file molesti ..."
for j in `awk '{print $1}' data/OriginalFilesWithLoops.dat`
do
	echo "elimino $j"
	rm $from/$j
done

echo "Limetto!"
mkdir $to
elenco=`ls $from`

for i in $elenco
do
	if [ ! -f $to/$i ]
	then
		gvpr -f $bin/Bilimetta.gv $from/$i > $to/$i	
		echo $i;
	fi
done
