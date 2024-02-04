const NApiFileSystemNativeModule = require("../lib/binding.js");
const assert = require("assert");

assert(NApiFileSystemNativeModule, "The expected function is undefined");

function testBasic()
{
    const result =  NApiFileSystemNativeModule("hello");
    assert.strictEqual(result, "world", "Unexpected value returned");
}

assert.doesNotThrow(testBasic, undefined, "testBasic threw an expection");

console.log("Tests passed- everything looks OK!");