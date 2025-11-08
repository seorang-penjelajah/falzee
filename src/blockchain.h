#ifndef BLOCKCHAIN_H
#define BLOCKCHAIN_H

#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <ctime>
#include <iomanip>
#include <openssl/sha.h>

// Class Block

class Block {
  public:
    int index;
    std::string timestamp;
    std::string data;
    std::string previousHash;
    std::string hash;
    unsigned long nonce;
    
    Block(int idx, 
      const std::string &timestamp,
      const std::string &data, 
      const std::string &prevHash, 
      unsigned long nonce = 0);
    
    std::string calculateHash() const;
    
  private:
    std::string sha256(const std::string &input) const;
};

// Class Blockchain

class Blockchain {
  public:
    Blockchain();
    
    void addBlock(const std::string &timestamp, 
      const std::string &data,
      unsigned long nonce = 0);
    const Block &getLatestBlock() const;
    const std::vector<Block> &getChain() const;
    
    bool isChainValid() const;
    
  private:
    std::vector<Block> chain;
    Block createGenesisBlock() const;
};

#endif