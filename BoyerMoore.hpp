#ifndef TurboBoyerMoore_h
#define TurboBoyerMoore_h


const int MAX_ALPHABET_SIZE = 256;

/** 
 * Performs an exact string search of the pattern in the text using the 
 * Turbo-BoyerMoore Algorithm (reference : Crochemore, String algorithms).
 * In fact it is a Boyer-Moore algo with factor memorization.
 *
 * @param	text	the text to search (supposed to be greater than the 
 * pattern
 *
 * @param	textLength	the number of chars of text to search
 *
 * @param	pattern		the pattern to search in the text
  *
  * @param	patternLength	the number of chars of pattern to search
 */

void TurboBoyerMoore(const char * text, 
	     int textLength,
	     const char * pattern, 
	     int patternLength);


/** 
 * Performs an exact string search of the pattern in the text using the 
 * BoyerMoore Algorithm (reference : Crochemore, String algorithms).
 *
 * -  performs the comparisons from right to left;
 * - 3n text character comparisons in the worst case when searching the first occurrence 
 *  of a non periodic pattern;
 * - O(nm) worst case time complexity when searching all the occurrences of a pattern;
 * - O(n/m) best performance. 
 *
 * @param	text	the text to search (supposed to be greater than the pattern
 *
 * @param	textLength	the number of chars of text to search
 *
 * @param	pattern		the pattern to search in the text
  *
  * @param	patternLength	the number of chars of pattern to search
 */

void BoyerMoore(const char * text, 
	     int textLength,
	     const char * pattern, 
	     int patternLength);

/** 
 * Performs an exact string search of the pattern in the text using the 
 * BoyerMoore Algorithm (reference : Crochemore, String algorithms).
 *
 * -  performs the comparisons from right to left;
 * - 3n text character comparisons in the worst case when searching the first occurrence 
 *  of a non periodic pattern;
 * - O(nm) worst case time complexity when searching all the occurrences of a pattern;
 * - O(n/m) best performance. 
 *
 * @param	text	the text to search (supposed to be greater than the pattern
 *
 * @param	textLength	the number of chars of text to search
 *
 * @param	pattern		the pattern to search in the text
 *
 * @param	patternLength	the number of chars of pattern to search
 *
 * @param	badCharShiftTable
 *
 * @param	goodSuffixShiftTable
 */

void BoyerMooreWithoutPreProcessing(const char * text, 
				    int textLength,
				    const char * pattern, 
				    int patternLength,
				    int badCharShiftTable[],
				    int  goodSuffixShiftTable[]);



/** computes the Bad Character function shift table 
*
* REQUIRES	badCharShiftTable	to have enough space for 256 ints
*
* -> for each a, it holds the distance between the right end and the rightmost occurrence of a
* badCharShiftTable[a] = min{j/ 1<= j< patternLength and pattern[patternLength - 1 -j]=a}, 
*			 or =m if a does not appear in x
* 
* @param	pattern		the word for which we compute the table
* @param	patternLength	the number of chars to be considered in pattern (starts from 0)
* @param	badCharShiftTable	a previously allocated array (of length 256) that will be filled	
*/
void computeBadCharacterShiftTable(const char *  const pattern, 
				   const int patternLength, 
				   int badCharShiftTable[]);

/** computes the Good Suffix Shift table 
*
* REQUIRES goodSuffixShiftTable to have enough space for patternLength + 1 ints
*
* let's define two conditions
* cond1(j,s) : for each k such that j<k<patternLength, s>=k or pattern[k-s]=pattern[k]
* cond2(j,s) : if s < j then pattern[j-s] != pattern[j]
*
* then for 0<= i <= patternLength;
*	goodSuffixShiftTable[i+1] = min{s>0/ cond1(i,s) and cond2(i,s) hold }
* 
* @param	pattern		the word for which we compute the table
* @param	patternLength	the number of chars to be considered in pattern (starts from 0)
* @param	goodSuffixShiftTable	a previously allocated array (of length patternLength + 1) that will be filled	
*/
void computeGoodSuffixShiftTable(const char * const pattern , 
				   const int patternLength, 
				   int goodSuffixShiftTable[]);


#endif				// TurboBoyerMoore_h
