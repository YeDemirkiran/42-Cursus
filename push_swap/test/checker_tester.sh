#!/bin/bash

PS_PATH="../push_swap"
CHECKER_PATH="./checker_linux"

OUTPUT=$(${PS_PATH} "$@")
COUNT=$(printf "${OUTPUT}" | wc -l)

echo "Count: ${COUNT}" 

if [ ${COUNT} == 0 ]; then
	: | ${CHECKER_PATH} "$@"
else
	echo "${OUTPUT}" | ${CHECKER_PATH} "$@"
fi

exit 0