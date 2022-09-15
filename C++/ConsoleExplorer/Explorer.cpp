#include "Explorer.h"

using namespace std;
namespace fs = std::filesystem;


Explorer::Explorer(string path_to_folder) {
	this->current_path = path_to_folder;
	this->before_path = path_to_folder;
}

void Explorer::updateCurrentPath(std::string path_to_folder) {
	this->before_path = this->current_path;
	this->current_path = path_to_folder;
}

const std::vector<std::filesystem::path> & Explorer::getFileList() {
	return this->file_list;
}

void Explorer::updateFileList() {
	for (auto& entry : fs::directory_iterator(this->current_path))
		this->file_list.push_back(entry.path());
}


void Explorer::showFileList() {
	for (auto& file : this->file_list) {
		string filename = file.filename().string();
		replace(filename.begin(), filename.end(), '³', 'i');
		replace(filename.begin(), filename.end(), '²', 'I');
		cout << filename << endl;
	}
}


std::filesystem::path Explorer::getFilePathByName(std::string filename) {
	const auto file = find_if(this->file_list.begin(), this->file_list.end(), [filename](auto file) {
		return  file.filename() == filename;
		});

	if (file != this->file_list.cend())
		return *file;

	throw ExplorerExceptions("file or folder not found");
}


void Explorer::showFileSize(const std::filesystem::path& file_path) {
	cout << "\t\t" << fs::file_size(file_path) << " bytes";
}


int Explorer::getFileSize(const std::filesystem::path& file_path) {
	return fs::file_size(file_path);
}


void Explorer::showFileType(const std::filesystem::path & file_path) {
	auto status = fs::status(file_path);
	cout << "\t\t";
	switch (status.type())
	{
		case fs::file_type::none: 
			std::cout << "[`not-evaluated-yet`]"; 
			break;

		case fs::file_type::not_found: 
			std::cout << "does not exist"; 
			break;

		case fs::file_type::regular: 
			std::cout << "[regular file]"; 
			break;

		case fs::file_type::directory: 
			std::cout << "[directory]"; 
			break;

		case fs::file_type::symlink: 
			std::cout << "[symlink]"; 
			break;

		case fs::file_type::block: 
			std::cout << "[block device]"; 
			break;

		case fs::file_type::character: 
			std::cout << "[character device]"; 
			break;

		case fs::file_type::fifo: 
			std::cout << "[IPC pipe]"; 
			break;

		case fs::file_type::socket: 
			std::cout << "[IPC socket]"; 
			break;

		case fs::file_type::unknown: 
			std::cout << "[`unknown`]"; 
			break;

		default: 
			std::cout << "[`implementation-defined`]"; 
			break;
	}
}


string Explorer::getFileType(const std::filesystem::path& file_path) {
	auto status = fs::status(file_path);
	switch (status.type())
	{
	case fs::file_type::none:
		return "[`not-evaluated-yet`]";
		break;

	case fs::file_type::not_found:
		return "does not exist";
		break;

	case fs::file_type::regular:
		return "[regular file]";
		break;

	case fs::file_type::directory:
		return "[directory]";
		break;

	case fs::file_type::symlink:
		return "[symlink]";
		break;

	case fs::file_type::block:
		return "[block device]";
		break;

	case fs::file_type::character:
		return "[character device]";
		break;

	case fs::file_type::fifo:
		return "[IPC pipe]";
		break;

	case fs::file_type::socket:
		return "[IPC socket]";
		break;

	case fs::file_type::unknown:
		return "[`unknown`]";
		break;

	default:
		return "[`implementation-defined`]";
		break;
	}
}


void Explorer::showFileListWithInfo() {
	for (auto& file : this->file_list) {
		string filename = file.filename().string();
		replace(filename.begin(), filename.end(), '³', 'i');
		replace(filename.begin(), filename.end(), '²', 'I');
		auto size = getFileSize(file);
		auto type = getFileType(file);

		cout << setw(40);
		cout << left << (filename.length() > 38 ? filename.substr(0, 35) + "..." : filename);
		cout << setw(5);
		cout << left << (size > 1024 ? size/1024 : size) << (size > 2014 ? " kb" : "bytes");
		cout << right << setw(27) << type;

		cout << endl;
	}
}


std::filesystem::path Explorer::createDirectory(std::string dir_name) {
	if (fs::create_directories(this->current_path + "\\" + dir_name)) {
		updateFileList();
		return getFilePathByName(dir_name);
	}
		
	
	throw ExplorerExceptions("Error. Dir can't be created");
}