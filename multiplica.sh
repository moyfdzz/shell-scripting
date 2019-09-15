#!/bin/bash
#
#Script para multiplicar entre sí todos los dígitos de un número
#y luego multiplicar el resultado por 2

number="$1"
result=2

for (( i=0; i<${#number}; i++ ))
do
   result=$(($result * ${number:i:1}))
done


echo $result