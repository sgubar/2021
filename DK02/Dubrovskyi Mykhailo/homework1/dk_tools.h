#ifndef _DK_TOOLS_H_
#define _DK_TOOLS_H_

// Enums
enum Type {Int, Char, Long};

// Error codes
extern const int NOT_EXIST;
extern const int NOT_A_TYPE;
extern const int OVERSIZED;
extern const int NOT_A_HEX;
extern const int NOT_OCT;
extern const int NOT_A_BIN;

extern const int OK;

//to do: matrixes

int get_chrs_pos(char *charset, char *string, int chrs_buff_size, int str_buff_size);

int rearrange(void *array, int size, enum Type t);

int count_words(char *string, int str_buff_size);

int count_chrs(char *charset, char *string, int chrs_buff_size, int str_buff_size);

int base16_to_base10(char *num);

int base8_to_base10(char *num);

int base2_to_base10(char *num);

#endif
