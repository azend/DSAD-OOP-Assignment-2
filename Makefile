
all: app docs

clean: app-clean docs-clean

app:
	$(MAKE) -C "Code"

docs: doxyconfig.doxygen
	doxygen doxyconfig.doxygen

app-clean:
	$(MAKE) -C "Code" clean

docs-clean:
	-rm -r "./Docs/Doxygen/*"
