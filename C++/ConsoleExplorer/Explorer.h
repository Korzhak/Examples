#pragma once
#include <iostream>
#include <filesystem>
#include <vector>
#include <algorithm>
#include <exception>
#include "ExplorerExceptions.h"
#include <iomanip>


class Explorer
{
public:
	Explorer(std::string path_to_folder);
	
	void updateCurrentPath(std::string path_to_folder);

	const std::vector<std::filesystem::path> & getFileList();

	std::filesystem::path getFilePathByName(std::string filename);
	
	void updateFileList();

	void showFileList();

	void showFileListWithInfo();

	void showFileSize(const std::filesystem::path& file_path);
	int getFileSize(const std::filesystem::path& file_path);

	void showFileType(const std::filesystem::path& file_path);
	std::string getFileType(const std::filesystem::path& file_path);

	std::filesystem::path createDirectory(std::string dir_name);
	void removeDirectory(std::string dir_name);

	std::filesystem::path copyFile(std::string filename);

	// TODO: getFolderInfo, getFileInfo, creatingFile, 
	// removingFile, creatingFolder, removingFolder,
	// pathParser, sortingFile

private:
	std::vector<std::filesystem::path> file_list;
	std::string current_path;
	std::string before_path;
};

