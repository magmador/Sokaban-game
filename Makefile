all: sources

.PHONY: sources
sources:
	make -C sources

.PHONY: sources-clean
sources-clean:
	make -C sources clean
