#!/bin/bash

rootPath="$(
	cd "$(dirname "$0")"
	pwd -P
)";

libsUrl=(
	"https://gitlab.holidev.net/open-libs/Json/-/archive/master/Json-master.zip" "Json"
	"https://gitlab.holidev.net/open-libs/SmartEvent/-/archive/master/SmartEvent-master.zip" "SmartEvent"
);

importRepo() {
	url=$1;
	libName=$2;
	echo "Getting $libName from $url..."; 
	cd $rootPath;
	rm -rf $libName;
	mkdir .tmp;
	cd .tmp;
	if ! wget $url 2> /dev/null; then
		echo "Cannot get $url..." 1>&2;
		rm -rf ../.tmp;
		exit 1;
	fi
	unzip *.zip > /dev/null
	rm *.zip;
	mv * ../$libName;
	make -C ../$libName RELEASE=true > /dev/null;
	cd ..;
	rm -rf .tmp;
}

length=${#libsUrl[*]}; ##Get list length;
for (( i=0; i<=$(( $length -1 )); i+=2 )); do
	importRepo ${libsUrl[$i]} ${libsUrl[$i+1]};
done