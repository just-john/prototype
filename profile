#!/bin/sh

export PROJECT_ROOT="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"

# build with clang?
#export CC=/usr/bin/clang
#export CXX=/usr/bin/clang++

compiler_banner=$(gcc --version)

if [ ! -z "${CXX}" ]; then
    compiler_banner=$(clang++ --version)
fi

echo "${compiler_banner}"
echo ""
echo -e "Building \e[32m${PROJECT_ROOT}..\e[39m"
echo ""

export PROJECT_BUILD_DIR="${PROJECT_ROOT}/bld"
export PROJECT_BIN_DIR="${PROJECT_ROOT}/bin"
export PROJECT_SRC_DIR="${PROJECT_ROOT}/src"


# 3rd party libraries live in /artifacts/
# it's your job to acquire and build them..for now
export ARTIFACT_ROOT="/artifacts"
export BOOST_ROOT="${ARTIFACT_ROOT}/boost_1_70_0"

export OPENSSL_ROOT_DIR="${ARTIFACT_ROOT}/openssl"
export OPENSSL_USE_STATIC_LIBS="TRUE"
