#!/bin/bash

cat Archivo3.txt | tr -d "[:punct:]" | tr " " "\n" | tr -d "¡" | tr -d "¿" | sort | uniq -ic | tail -1114