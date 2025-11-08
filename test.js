const falzee = require('./index.js');

const a = new Blockchain();

const data = JSON.stringify({message: 'Fisrt coy'});

a.addBlock(Date.now(), data);

const v = JSON.parse(a.getChain());

const p = JSON.parse(v[1].data);

console.log(JSON.stringify(v, null, 2))
console.log(p);
console.log(a.isValid());