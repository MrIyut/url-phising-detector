all: run

build:
	gcc -o my_av *.c header.h -lm

run:
	make build
	./my_av

clean:
	rm -f my_av
	rm urls-predictions.out