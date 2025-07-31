#!/bin/bash

PS_PATH="../push_swap"
CHECKER_PATH="./checker_linux"

OUTPUT=$(${PS_PATH} "$@")
COUNT=$(echo "${OUTPUT}" | wc -l)

echo "${OUTPUT}"

echo "Count: ${COUNT}" 

if [ ${COUNT} == 0 ]; then
	: | ${CHECKER_PATH} "$@"
else
	echo "${OUTPUT}" | ${CHECKER_PATH} "$@"
fi

exit 0