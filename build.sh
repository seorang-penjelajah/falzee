#!/bin/bash

# Nama output
OUTPUT="raw.node"

# Direktori sumber dan include
SRC_DIR="./src"
INCLUDE_DIR="./include"

# File sumber utama
MAIN_CPP="$SRC_DIR/main.cpp"
BLOCKCHAIN_CPP="$SRC_DIR/blockchain.cpp"

# Compile command
echo "🔧 Building Node.js addon..."
g++ -std=c++17 -I"$INCLUDE_DIR" -fPIC -shared "$MAIN_CPP" "$BLOCKCHAIN_CPP" -o "$OUTPUT" -lssl -lcrypto

# Cek hasil build
if [ $? -eq 0 ]; then
  echo "✅ Build selesai! Hasil: $BUILD_DIR/$OUTPUT"
else
  echo "❌ Build gagal!"
  exit 1
fi
