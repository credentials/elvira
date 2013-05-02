PROJECT_NAME = elvira
PROJECT_VERSION = $(shell cat VERSION)

PROJECT = $(PROJECT_NAME)-$(PROJECT_VERSION)
PROJECT_DIR = $(PROJECT)/

BUILD_DIR = build
ARCHIVE_EXT = tar.gz
CHECKSUM = sha512sum

ARCHIVE_FILE = $(PROJECT).$(ARCHIVE_EXT)
ARCHIVE_CHECKSUM_FILE = $(ARCHIVE_FILE).$(CHECKSUM)

# Build the library
all: $(BUILD_DIR)/Makefile
	$(MAKE) -C $(BUILD_DIR)

# Clean up the build dir (i.e. remove it)
clean:
	rm -rf $(BUILD_DIR)

# Clean up the working dir
distclean: clean
	rm -f $(PROJECT_NAME)-*.$(ARCHIVE_EXT)*

# Create a source archive
archive:
	git archive master --prefix $(PROJECT_DIR) --output $(ARCHIVE_FILE)
	$(CHECKSUM) $(ARCHIVE_FILE) > $(ARCHIVE_CHECKSUM_FILE)

# Create the build directory
build:
	mkdir -p $(BUILD_DIR)

# Generate the Makefile using CMake
$(BUILD_DIR)/Makefile: $(BUILD_DIR)
	(cd $(BUILD_DIR) && cmake ..)	

.PHONY : all clean
