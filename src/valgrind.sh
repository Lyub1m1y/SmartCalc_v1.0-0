#!/bin/bash
make clean
make test
# ./test
valgrind --quiet \
    --leak-check=full \
    --show-leak-kinds=definite,possible,indirect \
    --trace-children=yes \
    --track-origins=yes \
    --track-fds=no \
    -- ./test
# valgrind -q --trace-children=yes --track-fds=yes --track-origins=yes --leak-check=full --show-leak-kinds=all ./test
# cat valgrind.log
make clean