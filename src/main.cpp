#include <napi.h>
#include "blockchain.h"
#include "json.hpp"

using json = nlohmann::json;

class BlockchainWrapper : public Napi::ObjectWrap<BlockchainWrapper> {
public:
  static Napi::Object Init(Napi::Env env, Napi::Object exports) {
    Napi::Function func = DefineClass(env, "Blockchain", {
      InstanceMethod("addBlock", &BlockchainWrapper::AddBlock),
      InstanceMethod("getChain", &BlockchainWrapper::GetChain),
      InstanceMethod("isValid", &BlockchainWrapper::IsValid)
    });

    Napi::FunctionReference* constructor = new Napi::FunctionReference();
    *constructor = Napi::Persistent(func);
    env.SetInstanceData(constructor);

    exports.Set("Blockchain", func);
    return exports;
  }

  BlockchainWrapper(const Napi::CallbackInfo& info) 
    : Napi::ObjectWrap<BlockchainWrapper>(info) {
    blockchain = new Blockchain();
  }

  ~BlockchainWrapper() {
    delete blockchain;
  }

private:
  Blockchain* blockchain;

  Napi::Value AddBlock(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();
    if (info.Length() < 2) {
      Napi::TypeError::New(env, "timestamp dan data diperlukan").ThrowAsJavaScriptException();
      return env.Null();
    }

    std::string timestamp = info[0].As<Napi::String>();
    std::string data = info[1].As<Napi::String>();
    unsigned long nonce = 0;

    if (info.Length() >= 3 && info[2].IsNumber()) {
      nonce = info[2].As<Napi::Number>().Uint32Value();
    }

    blockchain->addBlock(timestamp, data, nonce);
    return env.Null();
  }

  Napi::Value GetChain(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();
    const std::vector<Block>& chain = blockchain->getChain();

    json jChain = json::array();
    for (const auto& b : chain) {
      jChain.push_back({
        {"index", b.index},
        {"timestamp", b.timestamp},
        {"data", b.data},
        {"previousHash", b.previousHash},
        {"hash", b.hash},
        {"nonce", b.nonce}
      });
    }

    return Napi::String::New(env, jChain.dump());
  }

  Napi::Value IsValid(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();
    bool valid = blockchain->isChainValid();
    return Napi::Boolean::New(env, valid);
  }
};

Napi::Object InitAll(Napi::Env env, Napi::Object exports) {
  return BlockchainWrapper::Init(env, exports);
}

NODE_API_MODULE(raw, InitAll)
