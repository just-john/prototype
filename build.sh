#!/bin/bash

source ./profile

mkdir -p ${PROJECT_ROOT}/bld
mkdir -p ${PROJECT_BIN_DIR}/lib

mkdir -p "${PROJECT_BUILD_DIR}"
cd "${PROJECT_BUILD_DIR}"

cmake -G Ninja \
    -DCMAKE_INSTALL_PREFIX=${PROJECT_BIN_DIR} \
    ../

ninja
ninja install

cd "${PROJECT_ROOT}"
