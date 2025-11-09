#include <iostream>
#include <dirent.h>
#include <unistd.h>
#include <sys/stat.h>
#include <filesystem>
#include <fstream>
#include <cstdio>
#include <cstring>
using namespace std;
namespace fs = std::filesystem;

// ---------- FUNCTION DECLARATIONS ----------
void listFiles(const string &path);
void changeDirectory(string &path);
void copyFile(const string &src, const string &dest);
void moveFile(const string &src, const string &dest);
void deleteFile(const string &filename);
void createFile(const string &filename);
void searchFile(const string &dir, const string &filename);
void showPermissions(const string &path);

// ---------- MAIN PROGRAM ----------
int main() {
    string currentDir = fs::current_path();
    int choice;
    while (true) {
        cout << "\n========== FILE EXPLORER ==========\n";
        cout << "Current Directory: " << currentDir << endl;
        cout << "1. List Files\n";
        cout << "2. Change Directory\n";
        cout << "3. Copy File\n";
        cout << "4. Move File\n";
        cout << "5. Delete File\n";
        cout << "6. Create File\n";
        cout << "7. Search File\n";
        cout << "8. Show File Permissions\n";
        cout << "9. Exit\n";
        cout << "Choose an option: ";
        cin >> choice;

        switch (choice) {
            case 1:
                listFiles(currentDir);
                break;
            case 2:
                changeDirectory(currentDir);
                break;
            case 3: {
                string src, dest;
                cout << "Enter source file: ";
                cin >> src;
                cout << "Enter destination file: ";
                cin >> dest;
                copyFile(src, dest);
                break;
            }
            case 4: {
                string src, dest;
                cout << "Enter source file: ";
                cin >> src;
                cout << "Enter destination file: ";
                cin >> dest;
                moveFile(src, dest);
                break;
            }
            case 5: {
                string filename;
                cout << "Enter file to delete: ";
                cin >> filename;
                deleteFile(filename);
                break;
            }
            case 6: {
                string filename;
                cout << "Enter file name to create: ";
                cin >> filename;
                createFile(filename);
                break;
            }
            case 7: {
                string filename;
                cout << "Enter file name to search: ";
                cin >> filename;
                searchFile(currentDir, filename);
                break;
            }
            case 8: {
                string filename;
                cout << "Enter file name: ";
                cin >> filename;
                showPermissions(filename);
                break;
            }
            case 9:
                cout << "Exiting... Goodbye!\n";
                return 0;
            default:
                cout << "Invalid option!\n";
        }
    }
}

// ---------- FUNCTION DEFINITIONS ----------

void listFiles(const string &path) {
    cout << "\nFiles in directory: " << path << endl;
    for (const auto &entry : fs::directory_iterator(path)) {
        cout << (entry.is_directory() ? "[DIR] " : "[FILE] ")
             << entry.path().filename().string() << endl;
    }
}

void changeDirectory(string &path) {
    string newDir;
    cout << "Enter directory name (.. for back): ";
    cin >> newDir;
    fs::path newPath = fs::path(path) / newDir;

    if (newDir == "..") {
        newPath = fs::path(path).parent_path();
    }

    if (fs::exists(newPath) && fs::is_directory(newPath)) {
        path = fs::canonical(newPath);
        fs::current_path(path);
        cout << "Changed to: " << path << endl;
    } else {
        cout << "Invalid directory.\n";
    }
}

void copyFile(const string &src, const string &dest) {
    try {
        fs::copy_file(src, dest, fs::copy_options::overwrite_existing);
        cout << "File copied successfully.\n";
    } catch (...) {
        cout << "Error copying file.\n";
    }
}

void moveFile(const string &src, const string &dest) {
    try {
        fs::rename(src, dest);
        cout << "File moved successfully.\n";
    } catch (...) {
        cout << "Error moving file.\n";
    }
}

void deleteFile(const string &filename) {
    try {
        if (fs::remove(filename))
            cout << "File deleted successfully.\n";
        else
            cout << "File not found.\n";
    } catch (...) {
        cout << "Error deleting file.\n";
    }
}

void createFile(const string &filename) {
    ofstream file(filename);
    if (file) {
        cout << "File created successfully.\n";
    } else {
        cout << "Error creating file.\n";
    }
}

void searchFile(const string &dir, const string &filename) {
    cout << "Searching for: " << filename << endl;
    bool found = false;
    for (const auto &entry : fs::recursive_directory_iterator(dir)) {
        if (entry.path().filename() == filename) {
            cout << "Found: " << entry.path() << endl;
            found = true;
        }
    }
    if (!found)
        cout << "File not found.\n";
}

void showPermissions(const string &path) {
    struct stat info;
    if (stat(path.c_str(), &info) == 0) {
        cout << "Owner: "
             << ((info.st_mode & S_IRUSR) ? "r" : "-")
             << ((info.st_mode & S_IWUSR) ? "w" : "-")
             << ((info.st_mode & S_IXUSR) ? "x" : "-") << endl;
        cout << "Group: "
             << ((info.st_mode & S_IRGRP) ? "r" : "-")
             << ((info.st_mode & S_IWGRP) ? "w" : "-")
             << ((info.st_mode & S_IXGRP) ? "x" : "-") << endl;
        cout << "Others: "
