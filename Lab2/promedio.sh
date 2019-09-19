#!/bin/bash
#
#Script para calcular el promedio de 5 números enteros
#

for number in "$@"
do
	sum=$(($sum + $number))
done

echo $(($sum / 5))