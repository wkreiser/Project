
#include <stdio.h>
#include <string.h>
#include "surfin_bird.h"

int main(void)
{
	int i = 0;
	int numTestsRun = 0;
	int numTestsPassed = 0;
	int putErrorCodeHere = DEFAULT_ERROR_CODE;
	char * tempReturnValue_ptr = NULL;
	char testChar1 = 0; // DEBUGGING
	char testChar2 = 0; // DEBUGGING

						/* TEST INPUT */
						// Three normal strings
	char testInput0[] = { "Good luck to you on this lab.\nI hope you do well." }; // Key: \n
	char testInput1[] = { "Normal test input.  'The' is the search key." }; // Key: The
	char testInput2[] = { "This is also normal input.  The 'bird' is the word." }; // Key: bird
																				   // Two strings that have duplicate keys
	char testInput3[] = { "This string is an example of a string that has two occurrences of the word 'is'." }; // Key: is
	char testInput4[] = { "The word 'the' is very common in the English language." }; // Key: the
																					  // Two strings that have multiple occurrences of the key
	char testInput5[] = { "Many English words are 'loan words', which is defined as 'a word that has been adopted from one language into another'." }; // Key: word
	char testInput6[] = { "The search keys don't have to be letters!  They could be any character or array of characters!  They could even be puntuation!  Maybe even non-printable characters!  Crazy, right?" }; // Key: "!  "
																																																				   // Two NULL strings to pass as sentence_ptr
	char * testInput7 = NULL; // Key: "Doesn't matter"
	char * testInput8 = NULL; // Key: "Don't bother"
							  // Two real strings to pass alongside a NULL searchWord
	char testInput9[] = { "It's a shame to waste a perfectly good sentence." }; // Key:  NULL
	char testInput10[] = { "It's a shame to waste a perfectly good null-terminated string." }; // Key:  NULL
																							   // Two real strings to pass alongside a NULL errorCode
	char testInput11[] = { "At least electrons are free." }; // Key: are
	char testInput12[] = { "Even if they're not free, there is are a plethora of electrons freely available." }; // Key: e
																												 // Two strings that will pass more NULL search keys
	char testInput13[] = { "You can't find a key here!" }; // Key: NULL
	char testInput14[] = { "Take a picture!  It'll last longer." }; // Key: NULL
																	// Two strings to pass long keys
	char testInput15[] = { "Now is the time for all good men to come to the aid of their country." }; // Key: "come to the aid"
	char testInput16[] = { "Sometimes it's hard to play the game the way it was intended to be played instead of following the game's rules as written." }; // Key: "play the game"
																																							// Edge cases that may break find_the_word()
	char testInput17[] = { "I hope you didn't find anything here!" }; // Key: '\0' (0x0)
	char testInput18[BUFF_SIZE] = { 0 }; // Key: "Don't do it!"
	char testInput19[] = { "Not a long string" }; // Key: "long string as a search key"
	char testInput20[] = { "part" }; // Key: "partial"
	char testInput21[BUFF_SIZE] = { 0 }; // Key: '\0' (0x0)
										 // Two strings whose keys are non printable characters
	char testInput22[] = { 0x1, 0x2, 0x3, 0x4, 0x5, 0x6, 0x7, 0x8, 0x9, 0xA, 0xB, 0xC, 0xD, 0xE, 0xF, 0x0 }; // Key: 0x8
	char testInput23[] = { 0x1A, 0x1B, 0x1C, 0x1D, 0x1E, 0x1F, 0x1E, 0x1D, 0x1C, 0x1B, 0x1A, 0x0 }; // Key: 0x1C
																									// Two strings that include characters from the extended ASCII codes
	char testInput24[] = { '\n', 0x5F, 0x5F, 0x5F, 0x5F, 0x5F, 0x5F, 0x5F, '\n', 0x7C, '$', '(', '5', ')', '$', 0x7C, '\n', 0xC4, 0xC4, 0xC4, 0xC4, 0xC4, 0xC4, 0xC4, '\n', 0x0 }; // Key: 0xC4
																																												   //	puts(testInput24); // DEBUGGING
	char testInput25[] = { 0xC4, 0x5C, 0x5F, 0x2, 0x5F, 0x2F, 0xC4, 0x0 }; // Key: 0x2F
																		   //	puts(testInput25); // DEBUGGING
	char testInput26[] = { "Sometimes keys are at the beggining of a string." }; // Key: "Sometime"
	char testInput27[] = { "When you lose an item, you always find it in the last place you look." }; // Key: "look."

	char * testInputArray[] = { \
		testInput0, testInput1, testInput2, \
		testInput3, testInput4, testInput5, \
		testInput6, testInput7, testInput8, \
		testInput9, testInput10, testInput11, \
		testInput12, testInput13, testInput14, \
		testInput15, testInput16, testInput17, \
		testInput18, testInput19, testInput20, \
		testInput21, testInput22, testInput23, \
		testInput24, testInput25, testInput26, \
		testInput27 };

	/* TEST SEARCH KEYS */
	char testKey0[] = { 10,0 };
	char testKey1[] = { "The" };
	char testKey2[] = { "bird" };
	char testKey3[] = { "is" };
	char testKey4[] = { "the" };
	char testKey5[] = { "word" };
	char testKey6[] = { "!  " };
	char testKey7[] = { "Doesn't matter" };
	char testKey8[] = { "Don't bother" };
	char * testKey9 = NULL;
	char * testKey10 = NULL;
	char testKey11[] = { "are" };
	char testKey12[] = { "e" };
	char * testKey13 = NULL;
	char * testKey14 = NULL;
	char testKey15[] = { "come to the aid" };
	char testKey16[] = { "play the game" };
	char testKey17[] = { 0x0, 0x0 };
	char testKey18[] = { "Don't do it!" };
	char testKey19[] = { "long string as a search key" };
	char testKey20[] = { "partial" };
	char testKey21[1] = { 0x0 };
	char testKey22[] = { 0x8, 0x0 };
	char testKey23[] = { 0x1C, 0x0 };
	char testKey24[] = { 0xC4, 0x0 };
	char testKey25[] = { 0x2F, 0x0 };
	char testKey26[] = { "Sometime" };
	char testKey27[] = { "look." };
	char * testKeyArray[] = { \
		testKey0, testKey1, testKey2, \
		testKey3, testKey4, testKey5, \
		testKey6, testKey7, testKey8, \
		testKey9, testKey10, testKey11, \
		testKey12, testKey13, testKey14, \
		testKey15, testKey16, testKey17, \
		testKey18, testKey19, testKey20, \
		testKey21, testKey22, testKey23, \
		testKey24, testKey25, testKey26, \
		testKey27 };

	/* TEST ERROR CODE POINTERS */
	int * errorCodePointerArray[] = { \
		&putErrorCodeHere, &putErrorCodeHere, &putErrorCodeHere, \
		&putErrorCodeHere, &putErrorCodeHere, &putErrorCodeHere, \
		&putErrorCodeHere, &putErrorCodeHere, &putErrorCodeHere, \
		&putErrorCodeHere, &putErrorCodeHere, NULL, \
		NULL, &putErrorCodeHere, &putErrorCodeHere, \
		&putErrorCodeHere, &putErrorCodeHere, &putErrorCodeHere, \
		&putErrorCodeHere, &putErrorCodeHere, &putErrorCodeHere, \
		&putErrorCodeHere, &putErrorCodeHere, &putErrorCodeHere, \
		&putErrorCodeHere, &putErrorCodeHere, &putErrorCodeHere, \
		&putErrorCodeHere };

	/* TEST RETURN VALUES */
	char * expectedReturnValueArray[] = { \
		&testInput0[29], &testInput1[21], &testInput2[33], \
		&testInput3[2], &testInput4[10], &testInput5[13], \
		&testInput6[40], testInput7, testInput8, \
		NULL, NULL, NULL, \
		NULL, NULL, NULL, \
		&testInput15[36], &testInput16[23], NULL, \
		NULL, NULL, NULL, \
		NULL, &testInput22[7], &testInput23[2], \
		&testInput24[17], &testInput25[5], &testInput26[0], \
		&testInput27[64] };

	/* TEST ERROR CODES */
	int expectedErrorCodeArray[] = { \
		ERROR_CODE_SUCCESS, ERROR_CODE_SUCCESS, ERROR_CODE_SUCCESS, \
		ERROR_CODE_SUCCESS, ERROR_CODE_SUCCESS, ERROR_CODE_SUCCESS, \
		ERROR_CODE_SUCCESS, ERROR_NULL_SENTENCE_POINTER, ERROR_NULL_SENTENCE_POINTER, \
		ERROR_NULL_SEARCH_POINTER, ERROR_NULL_SEARCH_POINTER, DEFAULT_ERROR_CODE, \
		DEFAULT_ERROR_CODE, ERROR_NULL_SEARCH_POINTER, ERROR_NULL_SEARCH_POINTER, \
		ERROR_CODE_SUCCESS, ERROR_CODE_SUCCESS, ERROR_SEARCH_NOT_FOUND, \
		ERROR_SEARCH_NOT_FOUND, ERROR_SEARCH_NOT_FOUND, ERROR_SEARCH_NOT_FOUND, \
		ERROR_SEARCH_NOT_FOUND, ERROR_CODE_SUCCESS, ERROR_CODE_SUCCESS, \
		ERROR_CODE_SUCCESS, ERROR_CODE_SUCCESS, ERROR_CODE_SUCCESS, \
		ERROR_CODE_SUCCESS };
	
	/* CALCULATE THE NUMBER OF TESTS */
	int numTotalTests = sizeof(testInputArray) / sizeof(testInputArray[0]);
	//	printf("The length of the test array is: %d \n", sizeof(testInputArray)/sizeof(testInputArray[0])); // DEBUGGING

	/* EXECUTE THE TESTS */
	for (i = 0; i < numTotalTests; i++)
	{
		wordFind test = { testInputArray[i], testKeyArray[i], expectedReturnValueArray[i], expectedErrorCodeArray[i], errorCodePointerArray[i] };
		/* 0. TEST HEADER */
		printf("\n");
		printf("************\n");
		printf("* TEST #%02d *\n", i);
		printf("************\n");
		tempReturnValue_ptr = find_the_word(test.inputString, test.searchWordString, test.errorCode);

		/* 1. TEST RETURN VALUE */
		numTestsRun++;
		printf("\tReturn Value Test:\t");
		if (tempReturnValue_ptr == test.expectedReturnValue)
		{
			puts("Pass");
			numTestsPassed++;
		}
		else
		{
			puts("FAIL!");
			printf("\t\tExpected pointer:\t%p\n", test.expectedReturnValue);
			printf("\t\tReceived pointer:\t%d\n", tempReturnValue_ptr);
		}

		/* 2. TEST ERROR CODE */
		numTestsRun++;
		printf("\tError Code Test:\t");
		if ((test.errorCode) == NULL)
		{
			puts("Pass");
			numTestsPassed++;
		}
		else if (*(test.errorCode) == test.expectedErrorCode)
		{
			puts("Pass");
			numTestsPassed++;
		}
		else
		{
			puts("FAIL!");
			printf("\t\tExpected error code:\t%d\n", test.expectedErrorCode);
			printf("\t\tReceived error code:\t%d\n", putErrorCodeHere);
			if (test.errorCode == DEFAULT_ERROR_CODE)
			{
				puts("\t\tError code not even updated!");
			}
		}

		putErrorCodeHere = DEFAULT_ERROR_CODE; // Reset error code // Reset error code
	}

	if (numTestsRun)
	{
		printf("\n\n\n*******************************\n");
		printf("Out of the %d tests that ran...\n", numTestsRun);
		printf("%d tests passed.\n", numTestsPassed);
		printf("*******************************\n");
	}
	getchar();
	getchar();
	return 0;
}

/*
* FUNCTION:   find_the_word(char * sentence_ptr, char * searchWord_ptr, int * errorCode_ptr)
*
* ARGUMENTS:  sentence_ptr is a char pointer to a null-terminated string to search
*             searchWord_ptr is a char pointer to a null-terminated string to find inside sentence_ptr
*             errorCode_ptr is an int pointer.  Store your error code at this memory address.
*
* RETURNS:	   char pointer to the first occurrence of the searchWord_ptr string found in the
*                 sentence_ptr string.  The char pointer should be a memory address in the
*                 sentence_ptr string and this memory address should represent the first 'index'
*                 of the searchWord_ptr string.  This memory address from the sentence_ptr string
*                 should dereference to a value equivalent to searchWord_ptr[0].
*             All other occurences should return NULL.  This includes, but is not limited to, the
*                 following:
*                     sentence_ptr is NULL
*                     searchWord_ptr is NULL
*                     errorCode_ptr is NULL
*                     the searchWord_ptr string is not found in the sentence_ptr string
*
* NOTES:      This function only utilizes address arithmetic to access information within the
*                 null-terminated char array found at both sentence_ptr and searchWord_ptr
*             Only access elements of the char array found at both sentence_ptr and searchWord_ptr
*                 using address arithmetic (AKA pointer math).  The definition of this function should
*                 be entirely devoid of the [ and ] characters.  (e.g., sentence_ptr[i] is forbidden)
*             The only guarantees for the arguments are:
*                 Any string found at sentence_ptr is null-terminated
*                 Any string found at searchWord_ptr is null-terminated
*             There is no guarantee sentence_ptr has an address (return NULL if it's NULL and assign the
*                 proper error code)
*             There is no guarantee searchWord_ptr has an address (return NULL if it's NULL and assign the
*                 proper error code)
*             There is no guarantee errorCode_ptr has an address (return NULL if it's NULL and assign the
*                 proper error code)
*             There is no guarantee the string found at sentence_ptr contains the string found at
*                 searchWord_ptr (return NULL if the string at searchWord_ptr is not found and assign the
*                 proper error code)
*             There is no guarantee the strings found at both sentence_ptr and searchWord_ptr will
*                 return a string length longer than zero (0)
*/

char * find_the_word(char * sentence_ptr, char * searchWord_ptr, int * errorCode_ptr)
{
	char * returnVal_ptr = NULL;
	int sentenceLength = 0;
	int searchLength = 0;
	int i = 0;
	int j = 0;

	if (!sentence_ptr)
	{
		returnVal_ptr = NULL;
		*errorCode_ptr = ERROR_NULL_SENTENCE_POINTER;
	}
	else if (!searchWord_ptr)
	{
		returnVal_ptr = NULL;
		*errorCode_ptr = ERROR_NULL_SEARCH_POINTER;
	}
	else if (!errorCode_ptr)
	{
		returnVal_ptr = NULL;
	}
	else
	{
		sentenceLength = strlen(sentence_ptr);
		searchLength = strlen(searchWord_ptr);
		if (searchLength > sentenceLength)
		{
			returnVal_ptr = NULL;
			*errorCode_ptr = ERROR_SEARCH_NOT_FOUND;
		}
		else
		{
			*errorCode_ptr = ERROR_SEARCH_NOT_FOUND;
			for (i = 0; i <= (sentenceLength - searchLength); i++)
			{
				if (*(sentence_ptr + i) == *(searchWord_ptr))
				{
					if (searchLength == 1)
					{
						returnVal_ptr = (sentence_ptr + i);
						*errorCode_ptr = ERROR_CODE_SUCCESS;
						return returnVal_ptr;
					}
					else
					{	//If searchLength greater than 1
						for (j = 1; j < searchLength; j++)
						{
							if (*(sentence_ptr + i + j) != *(searchWord_ptr + j))
							{
								break; //We cannot find the word My lord.
							}
							else if (j == (searchLength - 1))
							{
								returnVal_ptr = (sentence_ptr + i);
								*errorCode_ptr = ERROR_CODE_SUCCESS;
								return returnVal_ptr;
							}
						}
					}
				}
			}
		}
	}
	return returnVal_ptr;
}
