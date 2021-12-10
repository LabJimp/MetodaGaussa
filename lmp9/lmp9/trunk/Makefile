all:
	gcc -Wall --pedantic -lm src/*.c -o dane/gauss

test: all
	dane/gauss dane/zestawD0/BBB dane/zestawD0/b
testD0: all
	dane/gauss dane/zestawD0/BBB dane/zestawD0/b
testD1: all
	dane/gauss dane/zestawD1/CCC dane/zestawD1/c
testD2: all
	dane/gauss dane/zestawD2/CCCER1 dane/zestawD2/cER1
testD3: all
	dane/gauss dane/zestawD3/CCCER2 dane/zestawD3/cER2
testD4: all
	dane/gauss dane/zestawD4/CCCER3 dane/zestawD4/cER3
