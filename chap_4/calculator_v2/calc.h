#ifndef CALC_BASE_H
#define CALC_BASE_H

#define NUMBER '0'


char getop(char s[]);

char getch(void);
void ungetch(char c);

void push(double f);
double pop();
void prt_top();
void swap();
void cp_top();
void reset();

#endif
