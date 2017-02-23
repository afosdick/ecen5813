BUILD=Debug
BUILD_DIR=build-$(BUILD)
INSTALL_DIR=$(BUILD_DIR)

.PHONY : 3rd-party
3rd-party : cmocka

.PHONY : cmocka
cmocka : FORCE
	mkdir -p $(BUILD_DIR)/$@;
	cd $(BUILD_DIR)/$@; cmake \
		-DCMAKE_INSTALL_PREFIX=.. \
		-DCMAKE_BUILD_TYPE=$(BUILD) \
		-DCC=$(CC) \
		-DWITH_STATIC_LIB=ON \
		../../cmocka; make install

.PHONY : clean
clean : FORCE
	-rm -rf *~

.PHONY : clobber
clobber : clean
	-rm -rf $(BUILD_DIR)

FORCE :
