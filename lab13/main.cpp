#include <algorithm>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

using namespace std;
namespace file_units {
class FileReader {
private:
  string filename;
  string content;

public:
  FileReader(const string &file) : filename(file) { read_file_content(); }

  void read_file_content() {
    ifstream file(filename);
    if (file.is_open()) {
      string line;
      while (getline(file, line)) {
        content += line + "\n";
      }
      file.close();
    } else {
      content = "файл не найден";
    }
  }

  void display_content() { cout << "Содержимое файла:\n" << content << endl; }
};

namespace dolgopolov {

int multiply(int a, int b) { return a * b; }

int cube(int x) { return x * x * x; }

void replaceSpaces(string &str) {
  for (char &c : str) {
    if (c == ' ')
      c = '#';
  }
}

int maxE(const vector<vector<int>> &arr) {
  int max = arr[0][0];
  for (const auto &row : arr) {
    for (int num : row) {
      if (num > max)
        max = num;
    }
  }
  return max;
}

const double ELECTRON_CHARGE = 1.6e-19;
} // namespace dolgopolov
} // namespace file_units

namespace vlad = file_units::dolgopolov;

int main() {
  file_units::FileReader reader("example.txt");
  reader.display_content();

  cout << "Умножение: " << vlad::multiply(5, 3) << endl;
  cout << "Куб: " << vlad::cube(4) << endl;

  string text = "Замененный текст";
  vlad::replaceSpaces(text);
  cout << "Текст с заменой: " << text << endl;

  vector<vector<int>> matrix = {{1, 2}, {3, 4}};
  cout << "Максимум в матрице: " << vlad::maxE(matrix) << endl;

  cout << "Заряд электрона: " << vlad::ELECTRON_CHARGE << " Кл" << endl;

  return 0;
}
