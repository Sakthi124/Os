#!/bin/bash

echo "Enter a number: "

read number

# Store the original number

originalNumber=$number

# Calculate the number of digits

numOfDigits=${#number}

# Initialize the sum

sum=0

# Iterate through each digit

while [ $number -gt 0 ]

do

 digit=$(( $number % 10 ))

 sum=$(( $sum + $digit**$numOfDigits ))

 number=$(( $number / 10 ))

EX NO:2b

 

SHELL PROGRAMMING

DATE:
12

done

# Check if the sum is equal to the original number

if [ $sum -eq $originalNumber ]

then

 echo "$originalNumber is an Armstrong number."

else

 echo "$originalNumber is not an Armstrong number."

fi
