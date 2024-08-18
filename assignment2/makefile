execute_run_catalog: catalog.o run_catalog.o
	g++ catalog.o run_catalog.o -o output
create_run_catalog.o: run_catalog.cpp
	g++ -c run_catalog.cpp
create_catalog.o: catalog.cpp catalog.h
	g++ -c catalog.cpp
clean:
	rm *.o output
final_check: catalog.o run_catalog.output
	valgrind --leak-check=full ./(exe file)
