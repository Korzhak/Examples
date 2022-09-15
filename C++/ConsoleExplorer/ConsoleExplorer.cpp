#include <iostream>
#include "Explorer.h"

//--------------------------------------------------------------------------//
using namespace std;
namespace fs = std::filesystem;

//--------------------------------------------------------------------------//
int main() {
    setlocale(LC_ALL, "ukr");
    string path_name = "C:\\Users\\user\\Downloads\\Telegram Desktop\\example";
    Explorer explorer(path_name);
    explorer.updateFileList();
    explorer.showFileListWithInfo();

    try {
        explorer.createDirectory("example_folder");
    }
    catch (const ExplorerExceptions & ex) {
        cout << ex.getMore() << endl;
    }

    explorer.showFileListWithInfo();

    

    try {
        auto file = explorer.getFilePathByName("папка1");
        cout << file << endl;
        explorer.showFileSize(file);
        explorer.showFileType(file);
    }
    catch (const ExplorerExceptions & ex) {
        cout << ex.getMore();
    }
}