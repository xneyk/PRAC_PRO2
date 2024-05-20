OPTIONS = -D_JUDGE_ -D_GLIBCXX_DEBUG  -O2 -Wall -Wextra -Werror -Wno-sign-compare -std=c++11

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

clear: 
	rm *.o
	rm *.exe