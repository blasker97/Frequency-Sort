/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: Brian L
 *
 * Created on August 29, 2017, 6:46 PM
 */

#include <stdio.h>
#include <stdlib.h>
#include "input_error.h"
#include <ctype.h>
#include "vector.h"

void parse_getline(FILE* fp, struct vector* arr);
void parse_linechar(int length, char* line);




/*
 * 
 */
int main(int argc, char** argv) {
    
    
    
    if (argc!=3)
        exit(INCORRECT_NUMBER_OF_COMMAND_LINE_ARGUMENTS);
    
    FILE* fp = fopen(argv[1],"r");
    
    if(!fp)
        exit(INPUT_FILE_FAILED_TO_OPEN);
    
    struct vector inputs;
    struct vector freqInputs;
    init_vector(&inputs);
    init_vector(&freqInputs);
    
    int vsize;
    int Fvsize;
    // add elements then get size after
    parse_getline(fp, &inputs);
    vsize=vector_size(&inputs);
    
    if (vector_size(&inputs)==0){
        exit(PARSING_ERROR_EMPTY_FILE);
    }
    
    if (fclose(fp) == EOF)
	exit(INPUT_FILE_FAILED_TO_CLOSE);
    
    //sort vector by sending left most index and right most index
    mergeSort(&inputs, 0, vsize-1);
    
    
    set_frequency(&inputs);
    add_frequency_vector(&inputs,&freqInputs);
    Fvsize=vector_size(&freqInputs);
    
    FmergeSort(&freqInputs, 0, Fvsize-1);
    
    fp = fopen(argv[2],"w");
    
    if(!fp)
        exit(OUTPUT_FILE_FAILED_TO_OPEN);
    vector_write_file(&freqInputs, fp);
    
    if (fclose(fp) == EOF)
        exit(OUTPUT_FILE_FAILED_TO_CLOSE);
    
    free_vector(&inputs);
    free_vector(&freqInputs);
    
    

    return (EXIT_SUCCESS);
}

void parse_getline(FILE* fp, struct vector*  arr) {
	char* line = NULL;
	size_t nbytes = 0;
        int i=0, linelen=0;
	while ((linelen=getline(&line, &nbytes, fp)) != -1) {
		line[linelen-1] = '\0'; //removing the newline and adding the NULL character
                
                //check char in line
                parse_linechar(linelen,line);
                insert_element_vector(arr, atoi(line));
                
		
                
       	}

	free(line);
}

void parse_linechar(int length, char* line) {
    
    int i;
    
    for(i=0; i<length-1; i++){
        if(isdigit(line[i])==0){
            exit(PARSING_ERROR_INVALID_CHARACTER_ENCOUNTERED);
        }
    }	
}

    