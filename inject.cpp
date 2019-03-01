#include <iostream>
#include <fstream>
#include <algorithm>
#include <string>
#include <filesystem>

using namespace std;
namespace fs = std::filesystem;

fs::path source = "C:\\...\\inject\\src"; // Inject's source folder location

void copy_file(string filename);
string parse_name(string);

int main(int argc, char* argv[]) {
  if (argc != 3) {
    printf("WARNING: DEVELOPMENT PROTOTYPE\n");
    printf("Sample usage: C:/.../SOME_DIR>inject html file\n");
  }
  if (argc == 3) {
    if (string(argv[2]) == "file")
      copy_file(string(argv[1]));
  }
  return 0;
}

// Description: Checks Inject's source files for [filename] and injects it into
//              the user's current directory if it exists
// Parameters:  [filename] <string> : The name of the file you want to inject
void copy_file(string filename) {
  // Look through Inject's source files to see if [filename] exists
  for (auto& p: fs::directory_iterator(source)) {
    if (fs::is_directory(p.path())) continue; // Skip directories
    fs::path it_filename = p.path().filename(); // Get just the filename of each file in source directory
    if (parse_name(filename) == parse_name(it_filename.string())) { // Parse both filenames and see if the iterator found it
      fs::copy_file(p.path(), fs::current_path().string() + "\\" + it_filename.string()); // File found! Copy it into user's current directory
    }
  }
}

// Description: Parses file names so that the user just has to type/remember "html" and not "HTML.html"
// Parameters:  [str] <string> : The name of a file
// Returns:     <string> : Standardized form of filenames for searching
string parse_name(string str) {
  // Send string to lowercase
  for (int i = 0; i < str.size(); i++) {
    if(str[i] <= 'Z' && str[i] >= 'A')
      str[i] = str[i] - ('Z' - 'z');
  }

  // Remove file extension
  str = str.substr(0, str.size() - (str.size() - str.rfind(".")));

  return str;
}
