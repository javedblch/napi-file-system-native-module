const fileUtil = require('../build/Release/n-api-file-system-native-module-native');

module.exports = {
    readFile: fileUtil.readFile,
    writeFile: fileUtil.writeFile
};