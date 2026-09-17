#!/usr/bin/python3

from random import randint

filename = "test.rdr"
a = b = 100
minT = 300
maxT = 5000

doc = open(filename, 'w')
doc.close()

doc = open(filename, 'a')
for i in range(15):
	s = f"A {randint(0, 1920)} {randint(0, 1080)} {randint(-a, a)} {randint(-b, b)}\n"
	doc.write(s)
for i in range(15):
	s = f"T {randint(0, 1920)} {randint(0, 1080)} {randint(minT, maxT)}\n"
	doc.write(s)
doc.close()
