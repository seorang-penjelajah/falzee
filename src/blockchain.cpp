#include "blockchain.h"

//Implementasi Class Block

Block::Block(int idx, const std::string &timestamp, const std::string &data, const std::string &prevHash, unsigned long nonce)
  : index(idx), timestamp(timestamp), data(data), previousHash(prevHash), nonce(nonce) {
  hash = calculateHash();
}

std::string Block::calculateHash() const {
  std::stringstream ss;
  ss << index << timestamp << data << previousHash << nonce;
  return sha256(ss.str());
}

std::string Block::sha256(const std::string &input) const {
  unsigned char hash[SHA256_DIGEST_LENGTH];
  SHA256_CTX sha256;
  SHA256_Init(&sha256);
  SHA256_Update(&sha256, input.c_str(), input.size());
  SHA256_Final(hash, &sha256);
  
  std::stringstream ss;
  for (int i = 0; i < SHA256_DIGEST_LENGTH; i++) {
    ss << std::hex << std::setw(2) << std::setfill('0') << ((int)hash[i] & 0xff);
  }
  
  return ss.str();
}

// Implememtasi Class Blockchain

Blockchain::Blockchain() {
  chain.push_back(createGenesisBlock());
}

Block Blockchain::createGenesisBlock() const {
  return Block(0, "Genesis Timestamp", "Genesis Block", "0", 0);
}

void Blockchain::addBlock(const std::string &timestamp, const std::string &data, unsigned long nonce) {
  int newIndex = chain.size();
  std::string prevHash = chain.back().hash;
  Block newBlock(newIndex, timestamp, data, prevHash, nonce);
  chain.push_back(newBlock);
}

const Block &Blockchain::getLatestBlock() const {
  return chain.back();
}

const std::vector<Block> &Blockchain::getChain() const {
  return chain;
}

bool Blockchain::isChainValid() const {
  for (size_t i = 1; i < chain.size(); ++i) {
    const Block &current = chain[i];
    const Block &previous = chain[i - 1];
        
    if (current.hash != current.calculateHash())
      return false;
            
    if (current.previousHash != previous.hash)
      return false;
  }
  return true;
}