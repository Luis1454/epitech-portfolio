#!/bin/bash

sed "s/theo1/Wile E. Coyote/g" \
| sed "s/steven1/Daffy Duck/g" \
| sed "s/arnaud1/Porky Pig/g" \
| sed "s/pierre-jean/Marvin the Martian/g" \
| grep -iE "Wile E. Coyote|daffy duck|porky pig|marvin the martian"
