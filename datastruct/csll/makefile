compiler =cc  #copiler is variable
target = add.o  csll.o  delete.o  other.o  print.o  search_sort.o
flag =-c	
        
outfile:$(target)
	$(copiler) $(target) -o outfile
add.o:add.c
	$(copiler) $(flag) add.c
csll.o:csll.c
	$(copiler) $(flag) csll.c
delete.o:delete.c
	$(copiler) $(flag) delete.c
other.o:other.c
	$(copiler) $(flag) other.c
print.o:print.c
	$(copiler) $(flag) print.c
search_sort.o:search_sort.c
	$(copiler) $(flag) search_sort.c
clear:
	@echo "cleaning up..."
	@rm -v *.o
