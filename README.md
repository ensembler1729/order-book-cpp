## Validate Clang Format

```
clang-format -style=file -dump-config
```

## Default file for Clang Format
```
clang-format -style=llvm -dump-config > .clang-format
```

## Build Project

```
cmake -S . -B build -DCMAKE_BUILD_TYPE=Debug
```

```
cmake --build build
```
