# Node Api File System Native Module with C++

## Introduction

This project leverages the power of Node.js and Node-API to create a file utility that enables reading from and writing to files using C++ functionality within JavaScript.

## Running the Project

### Prerequisites

- Node.js installed on your system
- Familiarity with JavaScript fundamentals
- Proficiency in C/C++ programming
- Comfort with navigating the command line interface

### Steps

1. **Clone the Repository**:
   ```
   git clone https://github.com/javedblch/napi-file-system-native-module.git
   ```

2. **Navigate to the Project Directory**:
   ```
   cd napi-file-system-native-module
   ```

3. **Install Dependencies**:
   ```
   npm install
   ```

4. **Build the Project**:
   ```
   node-gyp rebuild
   ```

5. **Run Tests**:
   ```
   npm test
   ```

6. **Integrate the File Utility**:
   Require the file utility module in your code:
   ```
   const FileUtil = require("./lib/binding.js");
   ```

7. **Use the File Utility Functions**:
   You can now use the `readFile` and `writeFile` functions in your project as needed:
   ```
   const text = "Lorem ipsum dolor sit amet, consectetur adipiscing elit, sed do eiusmod tempor incididunt ut labore et dolore magna aliqua.";
   const filePath = "yourfile.txt";

   // Write data to a file
   FileUtil.writeFile(filePath, text);

   // Read data from a file
   const result = FileUtil.readFile(filePath);
   console.log("Data read from file:", result);
   ```

## Conclusion

By following these steps, you can successfully run the project and integrate the file utility into your Node.js applications. This file utility leverages the power of Node-API to bridge the gap between JavaScript and native C/C++ code, enabling efficient file operations within Node.js projects.
