/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   vector.h
 * Author: Brian L
 *
 * Created on August 29, 2017, 8:15 PM
 */

#ifndef H_VECTOR_H
#define H_VECTOR_H

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define INIT_VECTOR_SIZE 512

enum vector_errors
{
	OUT_OF_BOUNDS = 0,
};

struct vector
{
	int* data;
	int size;
	int capacity;
        int* frequency;
};

void init_vector(struct vector* v);
int access_element_vector(struct vector* v, size_t index);
void insert_element_vector(struct vector* v, int element_to_insert);
void free_vector(struct vector* v);
int vector_size(struct vector* v);
void mergeSort(struct vector* v, int l, int r);
void merge(struct vector* v, int l, int m, int r);
void print_vector(struct vector* v);
void set_frequency(struct vector* v);
void add_frequency_vector(struct vector* v, struct vector* vFreq);
void insert_frequency_vector(struct vector* v, int vdata, int vfreq);
int access_frequency(struct vector* v, size_t index);
void FmergeSort(struct vector* v, int l, int r);
void Fmerge(struct vector* v, int l, int m, int r);
void Fprint_vector(struct vector* v);
void vector_write_file(struct vector* v, FILE* fp);
#endif


