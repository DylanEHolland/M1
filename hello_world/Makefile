all: build

build: prep
	@-as -o build/hw.o hello_world.S;
	@-ld -macosx_version_min 12.0.0 -o build/hw build/hw.o -lSystem -syslibroot \
             `xcrun -sdk macosx --show-sdk-path` -e _start -arch arm64 

prep:
	@-[ ! -d build ] && mkdir build || rm -rf build/*;