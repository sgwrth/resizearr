SOURCEFILE = resizearr
OUTPUTFILE = out

output: $(SOURCEFILE).c
	gcc $(SOURCEFILE).c -o $(OUTPUTFILE)

clean:
	rm $(OUTPUTFILE).*
