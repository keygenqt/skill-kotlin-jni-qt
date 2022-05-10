#!/bin/bash

rm /usr/lib/libjni-qt.so*
cp ./build-jni-qt-Desktop_Qt_6_2_4_GCC_64bit-Debug/libjni-qt.so* /usr/lib/
echo "cp success"