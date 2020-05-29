# hybrid-benchmarks

Benchmarking node vs idiomatic c++11 vs vectorized c++

```
$ make
clang++ -O3 -g -std=c++11 glm.cpp -o glm
./glm
161.15
Timer Sort glm c++, elapsed time 4.10ms
clang++ -O3 -g -std=c++11 main.cpp -o main
./main
161.15
Timer Sort idiomatic c++, elapsed time 4.04ms
node main.js
31.03699475998758
Time taken: 19.68ms
```
