#!/usr/bin/python3

a=5
b=12

remainder = a % b if a > b else b % a

print("remainder: {}".format(remainder))

#const remainder = (, b) => (a > b ? a % b : b % a)a
#if a > b:
#    return a % b
#return b % a
