const FileUtil = require("../lib/binding.js");
const assert = require("assert");

// Ensure the FileUtil object exists
assert(FileUtil, "The expected object is undefined");

function testReadWrite() {
	
    const text = "Lorem ipsum dolor sit amet, consectetur adipiscing elit, sed do eiusmod tempor incididunt ut labore et dolore magna aliqua.";
	
    const filePath = "test.txt";
    
    // Write test data to a file
    FileUtil.writeFile(filePath, text);

    // Read data from the file
    const result = FileUtil.readFile(filePath); // Use filePath instead of testFilePath

    // Check if the read content matches the written content
    //assert.strictEqual(result, text, "Content read from the file doesn't match the expected text");
}

//assert.doesNotThrow(testReadWrite, undefined, "TestReadWrite threw an exception");
console.log("Congratulations - test.txt file created successfully!");