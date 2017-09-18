#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <cstring>
#include <stdlib.h>
#include <iomanip>

using std::cout;

//Word structure
struct words{
  std::string GermanWord;
  int category;
  std::string SpanishWord;
};

//Functions declarations
void startUp();
void readWords(std::vector<words>& wordlist);
void menu(std::vector<words>& wordlist);
void selection(std::vector<words>& wordlist);
void insertion(std::vector<words>& wordlist);
void saveWords(std::vector<words>& wordlist);
void spanishToGerman(std::vector<words>& wordlist);
void germanToSpanish(std::vector<words>& wordlist);
void irregularVerbs(std::vector<words>& wordlist);
void regularTerminations(std::vector<words>& wordlist);

//Functions
void startUp(){
  system("clear");
  std::cout << "-----------------------";
  std::cout << "\nWord Practice";
  std::cout << "\n-----------------------";
  std::cout << "\nby: escri11";
  std::cout << "\nCreated: 14/09/2017";
  std::cout << "\nLatest revision: 18/09/2017";
  std::cout << "\n";
  std::cout << "~~~~~~~~~~~~~~~~~~~~~~~";
}

void menu(std::vector<words>& wordlist){
  std::cout << "\nWord insertion [1]";
  std::cout << "\nSpanish to German practice [2]";
  std::cout << "\nGerman to Spanish practice [3]";
  std::cout << "\nIrregular verbs [4]";
  std::cout << "\nRegular verbs termination [5]";
  std::cout << "\nQuit [6]";
  std::cout << "\nInsert: ";

  selection(wordlist);
}

void selection(std::vector<words>& wordlist){
  int selector = 0;
  std::cin >> selector;
  switch(selector){
    case 1:
      insertion(wordlist);
      break;
    case 2:
      spanishToGerman(wordlist);
      break;
    case 3:
      germanToSpanish(wordlist);
      break;
    case 4:
      irregularVerbs(wordlist);
      break;
    case 5:
      regularTerminations(wordlist);
      break;
    case 6:
      saveWords(wordlist);
      break;
    default:
      std::cout << "Invalid choice, please input again:";
      selection(wordlist);
      break;
  }
}

void insertion(std::vector<words>& wordlist){
  std::cout << "-----------------------";
  std::cout << "\nWord Insertion";
  std::cout << "\nWrite [quit] to return to the menu";
  std::cout << "\n-----------------------";
  wordlist.push_back(words());
  int size = wordlist.size();
  std::string GermanWord;
  int category;
  std::string SpanishWord;
  std::cout << "\nGerman Word: ";
  std::cin.ignore (std::numeric_limits<std::streamsize>::max(), '\n');
  getline(std::cin, GermanWord);
  wordlist[size - 1].GermanWord = GermanWord;
  std::cout << "Spanish word: ";
  getline(std::cin, SpanishWord);
  wordlist[size - 1].SpanishWord = SpanishWord;
  std::cout << "Category(1: Everyday use; 2: Food; 3: Animals; 4: Adjectives; 5: Objects): ";
  std::cin >> category;
  wordlist[size - 1].category = category;
  menu(wordlist);
}

void spanishToGerman(std::vector<words>& wordlist){
  int type = 0;
  std::cout << "\n-----------------------";
  std::cout << "\nSpanish words to be translated to German";
  std::cout << "\nSelect category:";
  std::cout << "\n[1] Everything";
  std::cout << "\n[2] Everyday Use";
  std::cout << "\n[3] Food";
  std::cout << "\n[4] Animals";
  std::cout << "\n[5] Adjectives";
  std::cout << "\n[6] Objects";
  std::cout << "\n-----------------------";
  std::cout << "\nInsert: ";
  std::cin >> type;
  type = type - 1;
  int size = wordlist.size();
  for (int i = 0; i < size; i++) {
    if (type == wordlist[i].category) {
      std::cout << wordlist[i].SpanishWord << "\n";
      system("read");
      std::cout << wordlist[i].GermanWord << "\n";
      std::cout <<"\n";
    }
    else if (type == 0) {
      std::cout << wordlist[i].SpanishWord << "\n";
      system("read");
      std::cout << wordlist[i].GermanWord << "\n";
      std::cout <<"\n";
    }
  }
  std::cout << "Finished";
  std::cout << "\n-----------------------";
  std::cout << "\n";
  menu(wordlist);
}

void germanToSpanish(std::vector<words>& wordlist){
  int type = 0;
  std::cout << "\n-----------------------";
  std::cout << "\nGerman words to be translated to Spanish";
  std::cout << "\nSelect category:";
  std::cout << "\n[1] Everything";
  std::cout << "\n[2] Everyday Use";
  std::cout << "\n[3] Food";
  std::cout << "\n[4] Animals";
  std::cout << "\n[5] Adjectives";
  std::cout << "\n[6] Objects";
  std::cout << "\n-----------------------";
  std::cout << "\nInsert: ";
  std::cin >> type;
  type = type - 1;
  int size = wordlist.size();
  for (int i = 0; i < size; i++) {
    if (type == wordlist[i].category) {
      std::cout << wordlist[i].GermanWord << "\n";
      system("read");
      std::cout << wordlist[i].SpanishWord << "\n";
      std::cout <<"\n";
    }
    else if (type == 0) {
      std::cout << wordlist[i].GermanWord << "\n";
      system("read");
      std::cout << wordlist[i].SpanishWord << "\n";
      std::cout <<"\n";
    }
  }
  std::cout << "Finished";
  std::cout << "\n-----------------------";
  std::cout << "\n";
  menu(wordlist);
}

void saveWords(std::vector<words>& wordlist){
  std::ofstream data;
  data.open("data.txt");
  data << wordlist.size() << "\n";
  for (int i = 0; i < wordlist.size(); i++) {
    data << wordlist[i].GermanWord << "," << wordlist[i].SpanishWord << "," << wordlist[i].category;
    data << "\n";
  }
  data.close();
}

void readWords(std::vector<words>& wordlist){
  const int lField=150;
  char camp[lField];
  std::string line;
  int number_of_lines = 0;
  std::ifstream data("data.txt");
  data.getline(camp, lField,'\n');
  int maxline = atoi(camp);
  for (int i = 0; i < maxline; i++) {
    wordlist.push_back(words());
    data.getline(camp, lField,',');
    wordlist[i].GermanWord=camp;
    data.getline(camp, lField,',');
    wordlist[i].SpanishWord=camp;
    data.getline(camp, lField,'\n');
    wordlist[i].category=atoi(camp);
  }
	data.close();
}

void irregularVerbs(std::vector<words>& wordlist){
  //Lectura dels verbs i exercisi al mateix temps, s'han d'afegir a ma
  const int lField=150;
  char camp[lField];
  std::string line;
  std::ifstream verbs("verbs.txt");
  verbs.getline(camp, lField,'\n');
  int maxline = atoi(camp);
  for (int i = 0; i < maxline; i++) {
    verbs.getline(camp, lField,',');
    std::cout << "\n-----------------------";
    std::cout << "\nVerb: ";
    std::cout << camp;
    std::cout << "\n-----------------------";
    verbs.getline(camp, lField,',');
    std::cout << "\nich ";
    system("read");
    std::cout << camp;
    verbs.getline(camp, lField,',');
    std::cout << "\ndu ";
    system("read");
    std::cout << camp;
    verbs.getline(camp, lField,',');
    std::cout << "\ner/sie/es ";
    system("read");
    std::cout << camp;
    verbs.getline(camp, lField,',');
    std::cout << "\nwir ";
    system("read");
    std::cout << camp;
    verbs.getline(camp, lField,',');
    std::cout << "\nihr ";
    system("read");
    std::cout << camp;
    verbs.getline(camp, lField,'\n');
    std::cout << "\nsie ";
    system("read");
    std::cout << camp;
  }
  verbs.close();
  std::cout << "\n~~~~~~~~~~~~~~~~~~~~~~~";
  menu(wordlist);
}

void regularTerminations(std::vector<words>& wordlist){
  std::cout << "\n-----------------------";
  std::cout << "\nich ";
  system("read");
  std::cout << "-e";
  std::cout << "\ndu ";
  system("read");
  std::cout << "-st";
  std::cout << "\ner/sie/es ";
  system("read");
  std::cout << "-t";
  std::cout << "\nwir ";
  system("read");
  std::cout << "-en";
  std::cout << "\nihr ";
  system("read");
  std::cout << "-t";
  std::cout << "\nsie ";
  system("read");
  std::cout << "-en";
  std::cout << "\n-----------------------";
  menu(wordlist);
}

int main()
{
  std::vector<words> wordlist;
  readWords(wordlist);
  startUp();
  menu(wordlist);
}
