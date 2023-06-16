#!/usr/bin/env sh
# sh script that sends the signal SIGQUIT to a proces

if [ $# != 1 ]
then
	echo "Usage: $0 <pid>"
	exit 1
fi
kill -QUIT "$1"