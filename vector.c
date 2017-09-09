/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "../Homework1/vector.h"

void init_vector(struct vector* v)
{
	v->data = malloc(sizeof(int) * INIT_VECTOR_SIZE);
        v->frequency = malloc(sizeof(int) * INIT_VECTOR_SIZE);
	v->size = 0;
	v->capacity = INIT_VECTOR_SIZE;
}

int access_element_vector(struct vector* v, size_t index)
{
	if(index >= v->size)
		exit(OUT_OF_BOUNDS);
	return v->data[index];
}

void insert_element_vector(struct vector* v, int element_to_insert)
{
	if(v->capacity == v->size)
	{
		v->data = realloc(v->data, sizeof(int) * v->capacity * 2);
                v->frequency = realloc(v->frequency, sizeof(int) * v->capacity * 2);
		v->capacity *= 2;
	}
	v->data[v->size] = element_to_insert;
        v->frequency[v->size]=1;
	v->size += 1;
}

int* vector_get_ptr(struct vector* v)
{
	return v->data;
}

void free_vector(struct vector* v)
{
	free(v->data);
	v->size = 0;
}

int vector_size(struct vector* v)
{
    return v->size ;
}

void print_vector(struct vector* v)
{
    int i;
    int num;
    int freq;
    
    for(i=0; i<(v->size); i++){
        num = access_element_vector(v,i);
        freq = access_frequency(v,i);
        printf("%d---%d\n", num,freq);
    }
}
// l=left-index m=middle-index r=right-index
void merge(struct vector* v, int l, int m, int r)
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 =  r - m;
 
    // make temp arrays to copy into
    int* L = malloc(sizeof(int) * n1);
    int* R = malloc(sizeof(int) * n2);
 
    
    for (i = 0; i < n1; i++)
        L[i] = v->data[l + i];
    for (j = 0; j < n2; j++)
        R[j] = v->data[m + 1+ j];
 
    
    i = 0; // Initial index of first subarray
    j = 0; // Initial index of second subarray
    k = l; // Initial index of merged subarray
    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            v->data[k] = L[i];
            i++;
        }
        else
        {
            v->data[k] = R[j];
            j++;
        }
        k++;
    }
 
    while (i < n1)
    {
        v->data[k] = L[i];
        i++;
        k++;
    }
    
    while (j < n2)
    {
        v->data[k] = R[j];
        j++;
        k++;
    }
    
    free(L);
    free(R);
}

// l=left-index r=right-index
void mergeSort(struct vector* v, int l, int r)
{
    if (l < r){
        //navigate to the middle
        int m = l+(r-l)/2;
        // Sort first and second halves
        mergeSort(v, l, m);
        mergeSort(v, m+1, r);
 
        merge(v, l, m, r);
    }
}

int access_frequency(struct vector* v, size_t index)
{
	if(index >= v->size)
		exit(OUT_OF_BOUNDS);
	return v->frequency[index];
}

void set_frequency(struct vector* v)
{
    int i=0;
    int j=i+1;
    int s=0;
    
    for(i=0;i<v->size;i++){
        if(v->data[s]==v->data[j]){
            v->frequency[s]++;
            v->frequency[j]=0;
            j++;
        }
        else{
            s=j;
            j++;
        }
    }
}

void add_frequency_vector(struct vector* v, struct vector* vFreq)
{
    int i;
    int freq=0;
    int data=0;
    
    for(i=0;i<v->size;i++){
        data = access_element_vector(v,i);
        freq = access_frequency(v,i);
        if(freq>0){
            insert_frequency_vector(vFreq,data,freq);
        }
    }
} 

void insert_frequency_vector(struct vector* v, int vdata, int vfreq)
{
	if(v->capacity == v->size)
	{
		v->data = realloc(v->data, sizeof(int) * v->capacity * 2);
                v->frequency = realloc(v->frequency, sizeof(int) * v->capacity * 2);
		v->capacity *= 2;
                
	}
	v->data[v->size] = vdata;
        v->frequency[v->size]=vfreq;
	v->size += 1;
}

void Fmerge(struct vector* v, int l, int m, int r)
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 =  r - m;
 
    // make temp arrays to copy into
    int* L = malloc(sizeof(int) * n1);
    int* R = malloc(sizeof(int) * n2);
    int* L2 = malloc(sizeof(int) * n1);
    int* R2 = malloc(sizeof(int) * n2);
 
    
    for (i = 0; i < n1; i++){
        L[i] = v->frequency[l + i];
        L2[i] = v->data[l+i];
    }
    for (j = 0; j < n2; j++){
        R[j] = v->frequency[m + 1+ j];
        R2[j] = v->data[m + 1+ j];
    }
 
    
    i = 0; // Initial index of first subarray
    j = 0; // Initial index of second subarray
    k = l; // Initial index of merged subarray
    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            v->frequency[k] = L[i];
            v->data[k] = L2[i];
            i++;
        }
        else
        {
            v->frequency[k] = R[j];
            v->data[k] = R2[j];
            j++;
        }
        k++;
    }
 
    while (i < n1)
    {
        v->frequency[k] = L[i];
        v->data[k] = L2[i];
        i++;
        k++;
    }
    
    while (j < n2)
    {
        v->frequency[k] = R[j];
        v->data[k] = R2[j];
        j++;
        k++;
    }
    
    free(L);
    free(R);
    free(L2);
    free(R2);
}

// l=left-index r=right-index
void FmergeSort(struct vector* v, int l, int r)
{
    if (l < r){
        //navigate to the middle
        int m = l+(r-l)/2;
        // Sort first and second halves
        FmergeSort(v, l, m);
        FmergeSort(v, m+1, r);
 
        Fmerge(v, l, m, r);
    }
}

void Fprint_vector(struct vector* v)
{
    int i;
    int num;
    
    for(i=0; i<(v->size); i++){
        num = access_element_vector(v,i);
        printf("%d\n", num);
    }
}

void vector_write_file(struct vector* v, FILE* fp)
{
    int i;
    int num;
    
    for(i=0; i<(v->size); i++){
        num = access_element_vector(v,i);
        fprintf(fp, "%d\n", num);
    }
}