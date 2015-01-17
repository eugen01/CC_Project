all: sniffer fingerprint

sniffer: sniffer.c
	gcc -o sniffer sniffer.c

fingerprint: fingerprint.c
	gcc -o fingerprint fingerprint.c

clean:
	rm -f sniffer
	rm -f fingerprint
