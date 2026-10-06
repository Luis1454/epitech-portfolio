#!/bin/bash

cut -f 3 -d ';' | grep -i "$1" | wc -l
