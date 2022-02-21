/************************************************************
 *	File Name:		hangman.h                               *
 *	Author:         Michael Steets                          *
 *	Date Created:   10/23/2020                              *
 *	Date Modified:  10/26/2020                              *
 *	Purpose:  Header file for Hangman game					*
 ************************************************************/
#ifndef _HANGMAN_H
#define _HANGMAN_H

/*  Now we include the other headers we need */
#include <iostream>
#include <cstring>
#include <fstream>
#include <stdio.h>
#include <ctype.h>
#include <limits>

//dont forget to use the standard namespace

 
/*  Now we include all the function prototypes */
void printWord(char[], char[]);
void printStage(int stage);
void printLettersGuessed(bool[], char[]);

#endif