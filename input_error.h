/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   input_error.h
 * Author: Brian L
 *
 * Created on August 29, 2017, 8:44 PM
 */

#ifndef H_ERRORS_H
#define H_ERRORS_H

/* 
 * These errors should be handled properly by detecting thme and
 * returning the proper status code by calling exit(enum error)
 *
 * NOTE:
 * An invalid character refers to anything that is NOT a non-negative
 * integer or a new line character.  Examples of invalid characters:
 * 		letters
 * 		negative numbers
 * 		tabs
 * 		spaces
 * 		symbols
 */

enum error {
    INCORRECT_NUMBER_OF_COMMAND_LINE_ARGUMENTS = 1,
    INPUT_FILE_FAILED_TO_OPEN,
    INPUT_FILE_FAILED_TO_CLOSE,
    OUTPUT_FILE_FAILED_TO_OPEN,
    OUTPUT_FILE_FAILED_TO_CLOSE,
    PARSING_ERROR_INVALID_CHARACTER_ENCOUNTERED,
    PARSING_ERROR_EMPTY_FILE,
};

/*
 * EXAMPLE: If fopen fails to open the file, exit the program with
 * the proper error code in this way:
 * 		exit(FILE_FAILED_TO_OPEN);
 * Check that the code returned is correct by running your
 * program in GDB.  The above example would return exit status 2.
 * Please do not print anything when you find an error in the input.
 * Just exit with the correct exit status.
 */ 

#endif


