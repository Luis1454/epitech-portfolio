#!/bin/bash
sed "s/theo1/wile e. coyote/g" | sed "s/steven1/daffy duck/g" | sed "s/arnaud1/porky pig/g" | sed "s/pierre-jean/marvin the martian/g" | grep -E 'wile e. coyote|daffy duck|porky pig|marvin the martian'
