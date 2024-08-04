if [ -d build ]; then
    echo "Found pre-existing build directory. Deleting it."
    rm -rf build
fi

echo "Generating build directory."
mkdir build
cd build

echo "Compiling binaries."
cmake ..
cmake --build .

cd target
./cautatoru