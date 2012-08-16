#include <string.h>
#include <iostream>

#include "BoyerMoore.hpp"
using namespace std;
inline int max(int x, int y)
{
  return (x > y ? x : y);
}

void BoyerMoore(const char * text, 
		int textLength,
		const char * pattern, 
		int patternLength) {
    
  int	gsShift[ patternLength + 1];
  int	bcShift[ MAX_ALPHABET_SIZE ];
  
  computeBadCharacterShiftTable(pattern,patternLength,bcShift);
  computeGoodSuffixShiftTable(pattern,patternLength,gsShift);
  
  BoyerMooreWithoutPreProcessing(text,textLength,pattern,patternLength,bcShift,gsShift);
}

void BoyerMooreWithoutPreProcessing(const char * text, 
				    int textLength,
				    const char * pattern, 
				    int patternLength,
				    int badCharShiftTable[],
				    int  goodSuffixShiftTable[]) {
  
  int i=0;
  int j=0;
  while (i <= (textLength - patternLength) ) {
    for (j=patternLength-1; (j >= 0) && (text[i+j] == pattern[j]); --j);
    if (j < 0) {
      cout << i <<endl;
      i += goodSuffixShiftTable[j+1];
    }
    else {
      i += max(goodSuffixShiftTable[j+1],badCharShiftTable[ text[i+j] ]- patternLength + j + 1);
    }   
  }

}

void computeBadCharacterShiftTable(const char * const pattern , 
				   const int patternLength, 
				   int badCharShiftTable[]) 
{
  for(int i=0;i<MAX_ALPHABET_SIZE;i++) 
    badCharShiftTable[i] = patternLength;

  for(int j=0;j<patternLength-1;j++)
    badCharShiftTable[ pattern[j] ] = patternLength - j - 1;
}

void computeGoodSuffixShiftTable(const char * const pattern, 
				   const int patternLength, 
				   int goodSuffixShiftTable[])
{
  register int j = patternLength + 1;
  int f[j];
  f[ patternLength ] = j;
  
  memset(goodSuffixShiftTable,0,(patternLength + 1)*sizeof(int));	 // init array elements to 0

  for (int i=patternLength; i > 0; i--) {
    while ( (j <= patternLength) && ( pattern[i-1] != pattern[j-1]) ) {
      if (goodSuffixShiftTable[j] == 0)
	goodSuffixShiftTable[j] = j - i;
      j = f[j];
    }
    j--;
    f[i-1] = j;
  }

  int p = f[0];
  
  for (j=0;j <= patternLength; ++j) {
    if (goodSuffixShiftTable[j] == 0)
      goodSuffixShiftTable[j] = p;
    if(j == p)
      p = f[p];
  }
}

