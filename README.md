# cms
Coverage Monitoring Service

## Installation

```
sudo dnf install autoconf automake libtool curl make unzip git gcc-c++ boost boost-devel zlib-devel -y
```
 
Get Coverage Monitoring Service
```
git clone https://github.com/ds4es/cms
```

Pull latest of all git submodules
```
git submodule update --init --recursive
```

Build and install submodule that needs to be
```
# protobuf
cd ./lib/protobuf && ./autogen.sh
./configure
make
sudo make install
# OSM-binary
make -C ./lib/OSM-binary/src
sudo make -C ./lib/OSM-binary/src install
# RoutingKit
make -C ./lib/RoutingKit
```
