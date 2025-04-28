#include <cctype>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<string> splitIntoSentences(const string &text) {
  vector<string> sentences;
  string currentSentence;

  for (char ch : text) {
    currentSentence += ch;

    if (ch == '.' || ch == '!' || ch == '?') {
      sentences.push_back(currentSentence);
      currentSentence.clear();
    }
  }

  return sentences;
}

bool containsComma(const string &sentence) {
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

  vector<string> sentences = splitIntoSentences(text);

  for (const string &sentence : sentences) {
    if (!containsComma(sentence)) {
      cout << sentence << endl;
    }
  }

  return 0;
}
