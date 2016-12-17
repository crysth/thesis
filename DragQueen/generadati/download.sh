#!/bin/bash

language="cpp"
#extension="*.h" -not -name "*.c" -not -name "*.H" -not -name "*.C" -not -name "*.hpp" -not -name "*.cpp" -not -name "*.cxx" -not -name "*.hxx" -not -name "*.hh" -not -name "*.cc" -not -name "*.c++" -not -name "*.h++"

DATADIR=./data
TEMPDIR=./tempdata
token=f8c360b1d45e5355d9af2c647dfa8e445881876c

#reposfile="prova.dat"
#n=3
reposfile="repositories.dat"
n=$(cat $DATADIR/$reposfile | wc -l)

# ------------------------------   Preparation tasks   ------------------------------

mkdir -p $TEMPDIR/repositories_tgz
mkdir -p $TEMPDIR/repositories_dir
mkdir -p $TEMPDIR/download
mkdir -p $TEMPDIR/dotfiles
mkdir -p $DATADIR/errori

	rm -f $TEMPDIR/repositories_with_errors.dat
	rm -f $DATADIR/errori/download_falliti.dat
	rm -f $DATADIR/errori/senza$language.dat
	rm -f $DATADIR/errori/senzadot.dat

repository_names=( $(awk -v n=$n 'NR<=n {print $3}' $DATADIR/$reposfile) )


#--------------------------------------------
for full_name in "${repository_names[@]}"
do
	((i++))
	echo "$full_name $i of $n" > running
# ------------------------------   Download of repositories   ------------------------------
	echo -n -e "\r\033[K\r\033[KRepository $i of $n ($full_name): downloading..."

	folder=$(echo $full_name | sed "s/[\/]/\-/g")

	curl --proxy 192.168.0.1:3128 -s -L -D "$TEMPDIR/download/$folder.txt" -H "Authorization: token $token" https://api.github.com/repos/$full_name/tarball/master > $TEMPDIR/repositories_tgz/$folder.tgz

	if [[ ! $(grep HTTP $TEMPDIR/download/$folder.txt | grep 200) ]]
	then
		echo "$full_name" >> $TEMPDIR/repositories_with_errors.dat
# ------------------------------   Extract repository   ------------------------------
	else
		echo -n -e "\r\033[KRepository $i of $n ($full_name): extracting..."
		rm -fr "$TEMPDIR/repositories_dir/$folder"
		mkdir "$TEMPDIR/repositories_dir/$folder"
		tar -x -C "$TEMPDIR/repositories_dir/$folder" --strip-components 1 -f "$TEMPDIR/repositories_tgz/$folder.tgz"
		rm -fr $TEMPDIR/repositories_tgz/$folder.tgz
# ------------------------------   Deletion of unnecessary files and directories   ------------------------------
		echo -n -e "\r\033[KRepository $i of $n ($full_name): removing any unnecessary file and directory..."
		find $TEMPDIR/repositories_dir/$folder -not -name "*.h" -not -name "*.c" -not -name "*.H" -not -name "*.C" -not -name "*.hpp" -not -name "*.cpp" -not -name "*.cxx" -not -name "*.hxx" -not -name "*.hh" -not -name "*.cc" -not -name "*.c++" -not -name "*.h++" -not -type d -delete
		find $TEMPDIR/repositories_dir/$folder -mindepth 1 -empty -type d -delete

		if find $TEMPDIR/repositories_dir/$folder -maxdepth 0 -empty | read
		then
			echo -e "\r\033[KWARNING: Repository \"$full_name\" doesn't contain any $language file."
			echo $full_name >> "$DATADIR/errori/senza$language.dat"
		else
			echo -n -e "\r\033[K\r\033[KRepository $i of $n ($full_name): doxygen..."
			CDottatore.sh "$folder"
		fi
		rm -fr $TEMPDIR/repositories_dir/$folder
		sleep 2
	fi
#--------------------------------------------------------------
done

# ------------------------------   Download: second attempt (only in case of errors)   ------------------------------

if [[ -s $TEMPDIR/repositories_with_errors.dat ]]
then
	repository_names=( $(awk '{print $1}' $TEMPDIR/repositories_with_errors.dat) )
	n=${#repository_names[@]}
	echo -e "\r\033[KThere were errors downloading $n repositories. Trying again to download..."
	for full_name in "${repository_names[@]}"
	do
		((j++))
		echo $full_name > running
		echo -n -e "\r\033[KDownloading repository \"$full_name\" ($j of $n)..."

		folder=$(echo $full_name | sed "s/[\/]/\-/g")

		curl --proxy 192.168.0.1:3128 -s -L -D "$TEMPDIR/download/$folder.txt" -H "Authorization: token $token" https://api.github.com/repos/$full_name/tarball/master > $TEMPDIR/repositories_tgz/$folder.tgz

		if [[ ! $(grep HTTP $TEMPDIR/download/$folder.txt | grep 200) ]]
		then
			echo "$full_name" >> $DATADIR/errori/download_falliti.dat
		else
			echo -n -e "\r\033[KRepository $j of $n ($full_name): extracting..."
			rm -fr "$TEMPDIR/repositories_dir/$folder"
			mkdir "$TEMPDIR/repositories_dir/$folder"
			tar -x -C "$TEMPDIR/repositories_dir/$folder" --strip-components 1 -f "$TEMPDIR/repositories_tgz/$folder.tgz"
			rm -fr $TEMPDIR/repositories_tgz/$folder.tgz
# ------------------------------   Deletion of unnecessary files and directories   ------------------------------
			echo -n -e "\r\033[KRepository $i of $n ($full_name): removing any unnecessary file and directory..."
			find $TEMPDIR/repositories_dir/$folder -not -name "*.h" -not -name "*.c" -not -name "*.H" -not -name "*.C" -not -name "*.hpp" -not -name "*.cpp" -not -name "*.cxx" -not -name "*.hxx" -not -name "*.hh" -not -name "*.cc" -not -name "*.c++" -not -name "*.h++" -not -type d -delete
			find $TEMPDIR/repositories_dir/$folder -mindepth 1 -empty -type d -delete

			if find $TEMPDIR/repositories_dir/$folder -maxdepth 0 -empty | read
			then
				echo -e "\r\033[KWARNING: Repository \"$full_name\" doesn't contain any $language file."
				echo $full_name >> "$DATADIR/errori/senza$language.dat"
			else
				echo -n -e "\r\033[K\r\033[KRepository $i of $n ($full_name): doxygen..."
				CDottatore.sh "$folder"
			fi
			rm -fr $TEMPDIR/repositories_dir/$folder
			sleep 2
		fi
#--------------------------------------------------------------
	done

# ------------------------------   Error reporting   ------------------------------
	if [[ -s $DATADIR/errori/download_falliti.dat ]]
	then
		echo -e "\r\033[K"
		echo "Can't download the following $(awk 'END {print NR}' $DATADIR/errori/download_falliti.dat) repositories:"
		cat $DATADIR/errori/download_falliti.dat
		echo "(tried 2 times for each one). Please check HTTP headers in $TEMPDIR."
		folders=( $(awk '{print $1}' $DATADIR/errori/download_falliti.dat) )
		n=${#folders[@]}
		for repository in "${folders[@]}"
		do
			rm -f $TEMPDIR/repositories_tgz/$repository.tgz
		done
	fi
fi

rm Doxyfile
rm running
echo -e "\r\033[KDone."



