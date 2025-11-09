# 🧭 File Explorer Application (C++ for Linux)

A **command-line File Explorer** built in **C++17** that lets you manage files and directories directly from the terminal.  
This project demonstrates how to use the **`<filesystem>`** library and system-level operations like file creation, copying, deletion, navigation, and permission handling in a Linux environment.

---

## 📂 Features

✅ List all files and folders in the current directory  
✅ Change the working directory  
✅ Copy and move files  
✅ Delete files safely  
✅ Create new files  
✅ Search for files recursively  
✅ Display file permissions (Owner, Group, Others)  
✅ Simple text-based menu interface  

---

## ⚙️ Requirements

- **Operating System:** Linux  
- **Compiler:** g++ (with C++17 support)  
- **Libraries Used:**  
  - `<filesystem>`  
  - `<dirent.h>`  
  - `<sys/stat.h>`  
  - `<fstream>`  
  - `<unistd.h>`  
  - `<cstdio>`  
  - `<cstring>`  

---

## 🚀 How to Compile and Run

1. **Clone the repository**
   ```bash
   git clone https://github.com/<your-username>/linux-file-explorer.git
   cd linux-file-explorer

## 📸 Output Screenshots

Below are sample outputs for each operation performed in the Linux terminal.

1️⃣ **List Files in Current Directory**

  - Displays all files and folders in the current path.

<img width="622" height="544" alt="List_file" src="https://github.com/user-attachments/assets/1df4a276-1c42-4e18-8ae2-9be41f716e3b" />

2️⃣ **Change Directory**

  - Allows navigation between directories (use .. to go back).

  <img width="517" height="386" alt="Change_dir" src="https://github.com/user-attachments/assets/97bdaba2-7aaa-47df-b709-eec065b37d29" />

3️⃣ **Copy File**

- Copies a file from the source path to a destination.

<img width="737" height="412" alt="copy_file" src="https://github.com/user-attachments/assets/d411e2e0-8de1-4430-8096-8c24f2e7923e" />

4️⃣ **Move File**

- Moves or renames a file from one location to another.

<img width="593" height="402" alt="move_file" src="https://github.com/user-attachments/assets/c57688f3-f49f-4c76-b9c3-e88891cb2198" />


5️⃣ **Delete File**

- Removes a file permanently from the directory.

<img width="474" height="378" alt="delete_file" src="https://github.com/user-attachments/assets/dcbdb70d-9078-47f1-b385-458382197ff0" />


6️⃣ **Create New File**

- Creates a new empty file with the specified name.

<img width="471" height="381" alt="create_file" src="https://github.com/user-attachments/assets/2ea84b84-5c7d-4c2e-9426-6a0cbd24a451" />


7️⃣ **Search File**

- Searches for a specific file name recursively in the directory.

<img width="447" height="406" alt="search_file" src="https://github.com/user-attachments/assets/693d56d2-0b00-4740-8063-3a300f5060b9" />

8️⃣ **Show File Permissions**

- Displays owner, group, and others permissions for a file.

<img width="447" height="426" alt="file_permission" src="https://github.com/user-attachments/assets/3cb76d02-8111-4aef-aa83-8df0df3442ce" />

## 📜 License

- This project is open-source and available under the MIT License.
