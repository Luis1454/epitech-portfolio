#!/bin/bash

bash mr_clean
git add .
git commit -m $1
git push
