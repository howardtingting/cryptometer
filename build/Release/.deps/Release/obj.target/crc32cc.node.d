cmd_Release/obj.target/crc32cc.node := g++ -shared -pthread -rdynamic -m64  -Wl,-soname=crc32cc.node -o Release/obj.target/crc32cc.node -Wl,--start-group Release/obj.target/crc32cc/addons/crc32.o Release/obj.target/crc32cc/cpp_srcs/crc32.o -Wl,--end-group -lnode
