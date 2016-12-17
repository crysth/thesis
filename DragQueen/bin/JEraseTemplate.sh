#!/bin/bash

bin="/home/cry/DragQueen/bin/"

from="data/senzaduepunti/"
to="data/DotInheritanceNT/"

mkdir $from

elenco=`ls data/DotInheritance/`

echo "Pulisco i Java!"

for i in $elenco
do
	if [ ! -f $from/$i ]
	then
		sed "s/::/./g" data/DotInheritance/$i | sed "s/\\\l//g"	> $from/$i
		echo $i;
	fi
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



