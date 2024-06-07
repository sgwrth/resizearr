MAIN = main
FUNCTIONS = resizearr
EXECUTABLE = a

$(EXECUTABLE): $(MAIN).o $(FUNCTIONS).o
	gcc $(MAIN).o $(FUNCTIONS).o -o $(EXECUTABLE)

clean:
	rm *.o *.s $(EXECUTABLE)
