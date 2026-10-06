#!/bin/bash

cut -f 5 -d ':' | grep "\s$1" -i -c
