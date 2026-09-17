#!/bin/bash

cut -d ':' -f 1 | rev | tail -n +2 | sed -n 1~2p | sort -r | sed -n "${MY_LINE1}, ${MY_LINE2} p" | sed -z "s/\n/, /g" | sed "s/,\s\0/.\n/g" | sed "s/,\s$/.\n/"
