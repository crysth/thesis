#!/bin/bash

DATADIR=./data
TEMPDIR=./tempdata/list

token=f8c360b1d45e5355d9af2c647dfa8e445881876c

characters=(a b c d e f g h i j k l m n o p q r s t u v w x y z 0 1 2 3 4 5 6 7 8 9)


# ------------------------------   Step 0: authentication to GitHub   ------------------------------

VERBOSE_MODE=false
	if [[ $1 == "-v" ]]
	then
		VERBOSE_MODE=true
	fi
	# Check whether the provided token is valid
	if [[ $VERBOSE_MODE == true ]]
	then
		echo "Checking token validity..."
		invalid=$(curl -s -H "Authorization: token $token" https://api.github.com/user | grep -c "Bad credentials")
		if (($invalid))
		then
			echo "Token not valid. Quitting."
			exit
		fi
		echo "   OK."
	fi

# ------------------------------   Step 1: Retrieve repositories informations from GitHub   ------------------------------

echo "Downloading repositories informations..."

# curl "https://api.github.com/search/repositories?q=%22ab%22+in:name+language:CPP&page=4&per_page=100" | grep full_name | wc -l
# https://api.github.com/search/repositories?q=%22+aa%22+in:name+language:CPP&page=1&per_page=100
# :(
# bacino alla cry

rm -fR $TEMPDIR
mkdir -p $TEMPDIR

available_requests="----"

for querystring in ${characters[@]}
do
	if [[ $available_requests != "----" && $available_requests < 20 ]]
	then
		echo -n -e "\r\033[KToo few reqests available. Waiting 60 seconds..."
		sleep 50
	fi

	echo -n -e "\r\033[KAvailable requests: $available_requests. Current query: \"$querystring\"."
	for ((startpage=1; startpage<=10; startpage++))
	do
		curl -s -D "$TEMPDIR/headers.txt" -H "Authorization: token $token" "https://api.github.com/search/repositories?q=$querystring+in:name+language:CPP&page=$startpage&per_page=100" > $TEMPDIR/temp.json
		pageresults=$(grep -c "    {" $TEMPDIR/temp.json)
		if [ $pageresults -gt 0 ]
		then
			awk '$0~/^    /' $TEMPDIR/temp.json >> $TEMPDIR/repositories_$querystring.json
		fi
		if (($startpage==10||$pageresults<100))
		then
			available_requests=$(awk 'BEGIN {RS="\r\n"} $1~/^X-RateLimit-Remaining/ {print $2}' $TEMPDIR/headers.txt)
		fi
		if [ $pageresults -lt 100 ]
		then
			break
		fi
	done
done
echo -e "\r\033[K   Repositories informations downloaded."


# ------------------------------   Step 2: Parse repositories information   ------------------------------
echo "Parsing repositories informations..."

mkdir -p $DATADIR
rm -f $TEMPDIR/parserepositories_tmp.dat

for file in $(find $TEMPDIR -name "repositories_*.json")
do
	echo -n -e "\r\033[KParsing ${file:${#TEMPDIR}+14:${#file}-${#TEMPDIR}-19}..."

	awk '$1~/"login"/ {print substr($2,2,length($2)-3)}' $file >> $TEMPDIR/login.dat
	awk '$1~/"name"/ {print substr($2,2,length($2)-3)}' $file >> $TEMPDIR/nomi.dat
	awk '$1~/"full_name"/ {print substr($2,2,length($2)-3)}' $file >> $TEMPDIR/fullnomi.dat
	awk '$1~/"forks"/ {print substr($2,1,length($2)-1)}' $file >> $TEMPDIR/forks.dat
	awk '$1~/"size"/ {print substr($2,1,length($2)-1)}' $file >> $TEMPDIR/size.dat
	awk '$1~/"watchers"/ {print substr($2,1,length($2)-1)}' $file >> $TEMPDIR/watchers.dat
	awk '$1~/"created_at"/ {print substr($2,2,length($2)-13)}' $file >> $TEMPDIR/createdat.dat
	awk '$1~/"updated_at"/ {print substr($2,2,length($2)-13)}' $file >> $TEMPDIR/updatedat.dat
	awk '$1~/"pushed_at"/ {print substr($2,2,length($2)-13)}' $file >> $TEMPDIR/pushedat.dat
done

paste $TEMPDIR/login.dat $TEMPDIR/nomi.dat $TEMPDIR/fullnomi.dat $TEMPDIR/forks.dat $TEMPDIR/size.dat $TEMPDIR/watchers.dat $TEMPDIR/createdat.dat $TEMPDIR/pushedat.dat $TEMPDIR/updatedat.dat > $TEMPDIR/parserepositories_tmp.dat

echo -n -e "\r\033[KRemoving duplicates..."
sort $TEMPDIR/parserepositories_tmp.dat | uniq > $DATADIR/repositories.dat

echo -e "\r\033[K   Parsing completed."

echo
echo "Found $(wc -l $DATADIR/repositories.dat | awk '{print $1}') repositories. They are listed:"
echo " * in this file:     $DATADIR/repositories.dat"
echo " * with this format: name || owner || full_name || forks || size || watchers || created_at || pushed_at || updated_at "

#if [[ $VERBOSE_MODE != true ]]
#then
#	rm -fr $TEMPDIR
#fi

