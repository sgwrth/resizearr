MAIN = main
FUNCTIONS = resizearr
OUTPUT = out

output: $(MAIN).c
	gcc $(MAIN).c $(FUNCTIONS).c -o $(OUTPUT)

clean:
	rm $(OUTPUT).*
