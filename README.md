## Falzee

**Bahasa Indonesia:**  
Falzee adalah proyek eksperimen pribadi yang dibuat menggunakan **Node.js** dan **C++ (N-API)**.  
Tujuan utamanya hanya untuk **belajar**, **eksperimen**, dan **uji coba sederhana**.  
Tidak disarankan untuk digunakan dalam proyek **produksi** atau **finansial nyata**.

**English:**  
Falzee is a small experimental project built with **Node.js** and **C++ (N-API)**.  
It’s made purely for **learning**, **experimentation**, and **simple testing**.  
Not recommended for **production** or **real financial systems**.

---

## Installation

If you’re using it locally, install with:

```bash
npm install falzee
```

---

## Example Usage

```js
const falzee = require('falzee');

const chain = new Blockchain();

chain.addBlock("2025-11-08T10:00:00Z", { message: "Hello Falzee" }, 12345);

console.log(chain.getChain());
console.log("Is valid:", chain.isValid());
```

---

## Functions

### `new Blockchain()`
Creates a new blockchain instance stored in memory.  
Automatically includes a **Genesis Block** as the first block.

### `addBlock(timestamp, data, nonce)`
Adds a new block to the blockchain.

Parameter:

`timestamp` => `string` 
The block creation time. Can be a string, ISO timestamp, Unix timestamp, or any custom format the user prefers.

`data` => `any` 
Data to be stored in the block (string, object, etc.).

`nonce` => `number`
A random or custom number used to differentiate blocks, or for simple mining purposes.

### `getChain()`
Returns the entire blockchain as an array of blocks.

> ⚠️ Note: The result is a string.  
> You need to parse it with `JSON.parse()` in JavaScript before using it as an array or object.

Example usage:

```js
const chainString = chain.getChain();
const chainArray = JSON.parse(chainString);

console.log(JSON.stringify(chainArray));
```

Example output:
```json
[
  {
    "index": 0,
    "timestamp": "Genesis Timestamp",
    "data": "Genesis Block",
    "previousHash": "0",
    "hash": "12b7d245...",
    "nonce": 0
  }
]
```

### `isValid()`

Checks whether the blockchain is valid and all blocks are properly linked.
Returns true if valid, otherwise false.

---

## Thank You

Thank you for reading this far!
Feel free to experiment, learn, and provide feedback.