OPTIONS = -D_JUDGE_ -D_GLIBCXX_DEBUG  -O2 -Wall -Wextra -Werror -Wno-sign-compare -std=c++11 -fno-extended-identifiers

CC_s = program.cc Boat.cc City.cc Product.cc ProductInventoryStats.cc ProductSet.cc River.cc Travel.cc
HH_s = BinTree.hh Boat.hh City.hh Product.hh ProductInventoryStats.hh ProductSet.hh River.hh Travel.hh

program.exe: program.o River.o City.o Travel.o Boat.o ProductInventoryStats.o ProductSet.o Product.o
	g++ -o program.exe program.o River.o City.o Travel.o Boat.o ProductInventoryStats.o ProductSet.o Product.o $(OPTIONS)

program.o: program.cc River.hh ProductSet.hh Product.hh Boat.hh
	g++ -c program.cc $(OPTIONS)

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

# --- --- cmd --- ---

clear: 
	rm -f *.o
	rm -f *.exe

tar:
	tar -cvf program.tar $(CC_s) $(HH_s) Makefile proof.pdf html.zip

# --- --- --- --- ---
