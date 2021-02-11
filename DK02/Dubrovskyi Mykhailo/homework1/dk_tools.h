#ifndef _DK_TOOLS_H_
#define _DK_TOOLS_H_

// Enums
enum Type {Int, Char, Long};

//to do: matrixes

int get_chrs_pos(char *charset, char *string, int chrs_buff_size, int str_buff_size);

void * rearrange(void *array, int size, enum Type t);

int word_counter(char *array);

int count_chrs(char *charset, char *string);

int base16_to_base10(char num[4]);

int base8_to_base10(char num[4]);

int base2_to_base10(char num[4]);

#endif
