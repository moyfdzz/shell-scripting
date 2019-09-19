#!/bin/bash

echo "Palabras en total:"
cat $1 | awk '{print $2}' | wc -l

echo "Palabras únicas en total:"
cat $1 | awk '{print $2}' | sort | uniq | wc -l