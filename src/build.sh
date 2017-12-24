#!/bin/sh

rm -f ./my-resolver.out

gcc --version
ldd --version

gcc ./my-resolver.c -o ./my-resolver.out

./my-resolver.out
