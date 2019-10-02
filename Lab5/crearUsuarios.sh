#!/bin/sh

sudo useradd -m -g WK_IT $1 -p $2 -e $4
sudo passwd $1 -n $3