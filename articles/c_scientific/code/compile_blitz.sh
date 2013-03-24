#!/bin/bash
g++ $1 -lblitz `pkg-config blitz --libs --cflags`