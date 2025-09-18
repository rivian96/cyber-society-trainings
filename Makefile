all:
	gcc -fno-stack-protector -z execstack -D_FORTIFY_SOURCE=0 -no-pie shaolin.c -o vulnerable

clean:
	rm -rf vulnerable
