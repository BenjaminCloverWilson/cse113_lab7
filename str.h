#ifndef STR_H_
#define STR_H

void squeeze(char s[], int c);
void psqueeze(char *s, int c);
void str_cat(char s[], char t[]);
void pstr_cat(char *s, char *t);
void pstr_ncpy(char *dest, char *src, int n);
int str_len(char *s);
int pstr_ncmp(char *s, char *t, int n);
void cswap(char *c, char *d);
void preverse(char *s);
char *pindex(char *s, int c);
#endif
