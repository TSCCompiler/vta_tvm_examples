# Code Help UnderStand How TVM-VTA works

* 
  [add example and testbench](apps/verilator/add/verilog)

* build

```shell
git submodule init update
cd 3rdparty\verilator
git reset --hard v4.110
cd ../../
mkdir build
cd build
cmake -DTVM_DIR=D:\workspace\project\nn_compiler\tvm -DLANES=4 ../
make
```

* 微信交流群
![](docs/imgs/commuicate.png)


* tvm:
  https://github.com/apache/tvm