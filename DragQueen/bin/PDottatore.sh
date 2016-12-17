#!/bin/bash

bin="/home/cry/DragQueen/bin"

DATADIR=./data
TEMPDIR=./tempdata

folder=$1

rm -rf $TEMPDIR/perpaperella
mkdir $TEMPDIR/perpaperella
mkdir -p $DATADIR/DotInheritance

FILE=`find $TEMPDIR/repositories_dir/$folder -name "*.py"`
# field separator as newline
IFS=$'\n'
FILES=( $FILE ) 

for ((i = 0; i < ${#FILES[@]}; i++))
do
	nome=${FILES[$i]}
	cat Doxygenerator > Doxyfile
	echo "OUTPUT_DIRECTORY       = \"$TEMPDIR/dotfiles/$folder\"" >>  Doxyfile
	echo "INPUT                  = \"$nome\"" >>  Doxyfile
	doxygen.1.8.8 2>&1 >/dev/null | grep -v pippo
	if ls $TEMPDIR/dotfiles/$folder/rtf/*inhe*.dot &> /dev/null;
	then
		mkdir $TEMPDIR/perpaperella/$i/
		mv -n $TEMPDIR/dotfiles/$folder/rtf/*inhe*.dot $TEMPDIR/perpaperella/$i/
	fi
	rm -r $TEMPDIR/dotfiles/$folder
done

if ls $TEMPDIR/perpaperella/*/*.dot &> /dev/null;
then
	echo -n -e "\r\033[K\r\033[K $folder : paperella!\n"
	gvpr -f $bin/Papera.gv $TEMPDIR/perpaperella/*/*.dot > $DATADIR/DotInheritance/$folder.dot
else
	echo -e "\r\033[KWARNING: Repository \"$folder\" doesn't contain any .dot file."
	echo $folder >> "$DATADIR/errori/senzadot.dat"
fi

rm -rf $TEMPDIR/perpaperella

