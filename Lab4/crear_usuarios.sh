#!/bin/bash

cut -f2 -d: Users.txt | sort | uniq |
    while read -r line
    do
        groupadd "$line"
    done

cat Users.txt |
    while read -r line
    do
        user=$(awk -F: '{print $1}' <<< "$line")
        group=$(awk -F: '{print $2}' <<< "$line")
        useradd -s /bin/bash -m -g "$group" "$user"
    done
