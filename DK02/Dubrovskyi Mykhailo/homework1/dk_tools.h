#ifndef _DK_TOOLS_H_
#define _DK_TOOLS_H_

// Enums
enum Type {Int, Char, Long};

// Error codes
extern const int NOT_EXIST;
extern const int NULLPASS;
extern const int COLROW_ERR;
extern const int NOT_A_TYPE;
extern const int OVERSIZED;
extern const int NOT_A_HEX;
extern const int NOT_OCT;
extern const int NOT_A_BIN;
extern const int MATR_MULT_ERR;

extern const int OK;

int ** create_matrix(int columns, int rows);

int delete_matrix(int **matrix, int rows);

int ** sum_sub_matrixes(int **matrix1, int **matrix2, int rows, int columns);

int ** mult_matrixes(int **matrix1, int **matrix2, int r1, int c1, int r2, int c2);

int get_chrs_pos(char *charset, char *string, int chrs_buff_size, int str_buff_size);

int rearrange(void *array, int size, enum Type t);

int count_words(char *string, int str_buff_size);

int count_chrs(char *charset, char *string, int chrs_buff_size, int str_buff_size);

int base16_to_base10(char *num);

int base8_to_base10(char *num);

int base2_to_base10(char *num);

#endif
