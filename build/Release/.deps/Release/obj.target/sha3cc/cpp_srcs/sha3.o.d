cmd_Release/obj.target/sha3cc/cpp_srcs/sha3.o := g++ '-DNODE_GYP_MODULE_NAME=sha3cc' '-DUSING_UV_SHARED=1' '-DUSING_V8_SHARED=1' '-DV8_DEPRECATION_WARNINGS=1' '-D_LARGEFILE_SOURCE' '-D_FILE_OFFSET_BITS=64' '-DBUILDING_NODE_EXTENSION' -I/usr/include/nodejs/include/node -I/usr/include/nodejs/src -I/usr/include/nodejs/deps/openssl/config -I/usr/include/nodejs/deps/openssl/openssl/include -I/usr/include/nodejs/deps/uv/include -I/usr/include/nodejs/deps/zlib -I/usr/include/nodejs/deps/v8/include  -fPIC -pthread -Wall -Wextra -Wno-unused-parameter -m64 -fPIC -O3 -fno-omit-frame-pointer -fno-rtti -fno-exceptions -std=gnu++1y -MMD -MF ./Release/.deps/Release/obj.target/sha3cc/cpp_srcs/sha3.o.d.raw   -c -o Release/obj.target/sha3cc/cpp_srcs/sha3.o ../cpp_srcs/sha3.cpp
Release/obj.target/sha3cc/cpp_srcs/sha3.o: ../cpp_srcs/sha3.cpp \
 ../cpp_srcs/sha3.h
../cpp_srcs/sha3.cpp:
../cpp_srcs/sha3.h:
