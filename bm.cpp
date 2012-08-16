#include <iostream>
#include <string.h>
#include "BoyerMoore.hpp"


using namespace std;
int main(int argc,char* argv[]) {
  if (argc < 3 ) {
    cout << "Give 2 args: text pattern\n";
  }
  const char *text = argv[1];
  const char* pattern = argv[2];
  BoyerMoore(text,strlen(text),pattern,strlen(pattern));
}
