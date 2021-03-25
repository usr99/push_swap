#!/bin/bash

STR=""
TMP=""
START=1
END=$1

for i in `seq $START $END`
do
	TMP=$(($RANDOM % 4000000000))
	STR="$STR $TMP"
done

export ARG=$STR
