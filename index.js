const addon = require('./raw.node');

const p = new addon.Blockchain();

global.Blockchain = addon.Blockchain;

module.exports = addon.Blockchain;