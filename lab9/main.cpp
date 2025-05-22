#include <cctype>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<string> split(const string &text) {
  vector<string> sentences;
  string sent1;

  for (char ch : text) {
    sent1 += ch;

    if (ch == '.' || ch == '!' || ch == '?') {
      sentences.push_back(sent1);
      sent1.clear();
    }
  }

  return sentences;
}

bool is_comma(const string &sentence) {
  for (char ch : sentence) {
    if (ch == ',') {
      return true;
    }
  }
  return false;
}

int main() {
  setlocale(LC_ALL, "Russian");

  string filename = "file.txt";
  ifstream inputFile(filename);

  string text;
  string line;
  while (getline(inputFile, line)) {
    text += line + "\n";
  }
  inputFile.close();

  vector<string> sentences = split(text);

  for (const string &sentence : sentences) {
    if (!is_comma(sentence)) {
      cout << sentence << endl;
    }
  }

  return 0;
}
