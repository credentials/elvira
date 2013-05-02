# Build the library
all: build/Makefile
	$(MAKE) -C build

# Clean up the build dir (i.e. remove it)
clean:
	rm -r build

# Create the build directory
build:
	mkdir -p build

# Generate the Makefile using CMake
build/Makefile: build
	(cd build && cmake ..)	

.PHONY : all clean
