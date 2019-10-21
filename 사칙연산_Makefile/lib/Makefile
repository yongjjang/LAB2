OBJECTS = divi.o add.o sub.o mult.o
libshared.so.1.0.1 : $(OBJECTS)
	gcc -shared -Wl,-soname,libshared.so.1 -o libshared.so.1.0.1 $^
	ln -s libshared.so.1.0.1 libshared.so.1
	ln -s libshared.so.1.0.1 libshared.so
divi.o : divi.c
	gcc -c -fPIC $<
add.o : add.c
	gcc -c $<
sub.o : sub.c
	gcc -c $<
mult.o : mult.c
	gcc -c $<
clean :
	rm -f libshared.so.1.0.1 libshared.so.1 libshared.so staticlib.a $(OBJECTS) 


