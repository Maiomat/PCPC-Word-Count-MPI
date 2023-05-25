#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <glib.h>

#include "mpi.h"

//File Information and Directory List Management

typedef struct File_inf{

    double total_size;
    char * path;

} File_inf;

File_inf * get_info_file(char * file_paths);

GList * get_directory_files_info(char * dir_paths, double *files_size);

void free_files_info(GList * list, int num);

//Definitions, File Chunk Creation, and Reception

#define MAX_PACK_SIZE 8192
#define COMM_TAG 88
#define MASTER_RANK 0

#ifndef FILE_CHUNK
#define FILE_CHUNK
    typedef struct File_chunk{
        double start_offset;
        double end_offset;
        char path[260];
    } File_chunk;
#endif

File_chunk* create_file_chunk(double start_offset , double end_offset, char * path);

void create_chunk_datatype(MPI_Datatype *chunktype);

File_chunk * probe_recv_chunks(MPI_Datatype chunktype, MPI_Status Stat, int * chunk_number);

//Printing and Displaying File Chunks and Lists

void print_list(char *elem, char*user_data);

void print_file_chunk(File_chunk * chunk);

void printn_file_chunk(File_chunk chunk);

void print_file_chunk_array(File_chunk * chunks, int num_elements);

void print_received_chunks(File_chunk * chunks, int num_elements, int rank);

//Representation and Sorting of Word Occurrences

typedef struct Word_occurrence{

    int num;
    char word[46];

} Word_occurrence;

Word_occurrence * create_word_occurence(char * word ,int num);

void create_word_datatype(MPI_Datatype *wordtype);

void sort_occurrences(Word_occurrence ** p_occurences, int n);

//Chunk Lexeme Analysis and Word Frequency Calculation

Word_occurrence * get_lexeme_from_chunk(File_chunk *chunks_received, int chunk_number, int rank, int * num_word);