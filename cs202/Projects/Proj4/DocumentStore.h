/****************************************************************
 * File:    DocumentStore.h
 * Project: CMSC 202 Project 4, Spring 2014
 * Author:  John Larson
 * Date:    11/22/2014
 * Section: all
 * E-mail:  larson3@umbc.edu 
 *
 *
 ****************************************************************/

#ifndef DOCUMENTSTORE_H
#define DOCUMENTSTORE_H
#include <string>
#include <vector>
#include "Document.h"

class DocumentStore {
public:
    DocumentStore();
    void CreateMemo();
    void CreateEmail();
    void CreateReport();
    void Display(int docID);
    void ListDocuments();
    void Search(std::string queryStr);
    void ClearDocuments();
    
private:
    // Used to help generate unique sequential ID #'s for documents
    int m_nextID;

    // Vector used to keep track of our active documents
    std::vector<Document *> m_active;
   

    static std::string InputText(const char *prompt);
    static std::string InputMultilineText(const char *prompt);



public:


private:


    
};

#endif
