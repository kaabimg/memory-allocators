#include <iostream>
#include <cstddef>
#include <vector>

#include "Benchmark.h"
#include "Allocator.h"
#include "StackAllocator.h"
#include "CAllocator.h"
#include "LinearAllocator.h"

int main(){
	const std::vector<std::size_t> ALLOCATION_SIZES {2, 4, 16, 32, 64, 256, 512, 1024};
	const std::vector<std::size_t> ALIGNMENTS {2, 4, 8, 8, 8, 8, 8, 8};

	Allocator * cAllocator = new CAllocator();
	Allocator * linearAllocator = new LinearAllocator(1e8);
	Allocator * stackAllocator = new StackAllocator(1e8);

	Benchmark benchmark(100, ALLOCATION_SIZES, ALIGNMENTS);
	
	std::cout << "C" << std::endl;
	benchmark.Allocation(cAllocator);
	benchmark.Free(cAllocator);
	benchmark.AllocationRandom(cAllocator);
	benchmark.FreeRandom(cAllocator);

	std::cout << "LINEAR" << std::endl;
	benchmark.Allocation(linearAllocator);
	benchmark.AllocationRandom(linearAllocator);

	std::cout << "STACK" << std::endl;
	benchmark.Allocation(stackAllocator);
	benchmark.Free(stackAllocator);
	benchmark.AllocationRandom(stackAllocator);
	benchmark.FreeRandom(stackAllocator);


	delete cAllocator;
	delete linearAllocator;
	delete stackAllocator;
	
	return 1;
}




