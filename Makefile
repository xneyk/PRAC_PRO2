OPTIONS = -D_JUDGE_ -D_GLIBCXX_DEBUG  -O2 -Wall -Wextra -Werror -Wno-sign-compare -std=c++11 -fno-extended-identifiers

program.exe: program.o River.o City.o Travel.o Boat.o ProductInventoryStats.o ProductSet.o Product.o
	g++ -o program.exe program.o River.o City.o Travel.o Boat.o ProductInventoryStats.o ProductSet.o Product.o $(OPTIONS)

program.o: program.cc River.hh ProductSet.hh Product.hh Boat.hh
	g++ -c program.cc $(OPTIONS)

program_test.exe: program_test.o River.o City.o Travel.o Boat.o ProductInventoryStats.o ProductSet.o Product.o
	g++ -o program_test.exe program_test.o River.o City.o Travel.o Boat.o ProductInventoryStats.o ProductSet.o Product.o $(OPTIONS)

program_test.o: program_test.cc River.hh ProductSet.hh Product.hh Boat.hh
	g++ -c program_test.cc $(OPTIONS)

test_river.exe: test_river.o River.o City.o ProductInventoryStats.o ProductSet.o Product.o
	g++ -o test_river.exe test_river.o River.o City.o ProductInventoryStats.o ProductSet.o Product.o $(OPTIONS)

test_river.o: test_river.cc River.hh ProductSet.hh
	g++ -c test_river.cc $(OPTIONS)

# --- --- --- --- ---

River.o: River.cc River.hh City.hh BinTree.hh
	g++ -c River.cc $(OPTIONS)

City.o: City.cc City.hh ProductSet.hh ProductInventoryStats.hh
	g++ -c City.cc $(OPTIONS)

ProductInventoryStats.o: ProductInventoryStats.cc ProductInventoryStats.hh
	g++ -c ProductInventoryStats.cc $(OPTIONS)

# --- --- --- --- ---

ProductSet.o: ProductSet.cc ProductSet.hh Product.hh
	g++ -c ProductSet.cc $(OPTIONS)

Product.o: Product.cc Product.hh
	g++ -c Product.cc $(OPTIONS)

# --- --- --- --- ---

Travel.o: Travel.cc Travel.hh Boat.hh
	g++ -c Travel.cc $(OPTIONS)

# --- --- --- --- ---

Boat.o: Boat.cc Boat.hh
	g++ -c Boat.cc $(OPTIONS)

# --- --- --- --- ---

clear: 
	rm -f *.o
	rm -f *.exe