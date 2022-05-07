cmake -DCMAKE_EXPORT_COMPILE_COMMANDS=1 -B build
make -C build
mv build/LR08 .
