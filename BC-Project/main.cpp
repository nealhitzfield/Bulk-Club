//***************************************************************************
// Names: _
//		  _
//		  _
//		  _
//		  _
//
// Team:
// Product Owner:
// Scurm Master:
//
// Class: CS-1C
// Project 1: Bulk Club
// Due date: 2/_/2018
//***************************************************************************

//***************************************************************************
// main.cpp: This program _
//***************************************************************************

#include "mainwindow.h"
#include <QApplication>

#include "header.h"

int main(int argc, char *argv[])
{
    //Variables.
    string s1 = "Hello World.";

    //GUI related code.
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    return a.exec();
}
