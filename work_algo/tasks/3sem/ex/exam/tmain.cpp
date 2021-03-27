/*
 *  �������� ���� ��� ������� ������ � �������.
 *  (2008-2009 ��.���, ����������������, 2 �����)
 *
 *  ����������� �����:
 *     tree.h  tmain.cpp  myfun.cpp  tree.o  tree.dat
 *
 *  ��������� ������ ������� �� ����� tree.dat
 *  � ������������� ��� �� ����� � � ���� tree.res.
 *  �������� ����������� ������� ��. � ����� tree.h
 *
 *  �������, ����������� ��� ��� ������� ������, �������
 *  ������� � ��������� ����� (������, myfun.cpp). � ����
 *  ������ ���������� � ������ ��������� ����� ����������
 *  �������� make (����������� makefile �����������), ����
 *  ������� ��������������� �� ��������� ������:
 *
 *    g++  tmain.cpp myfun.cpp tree.o
 *
 */
#include "tree.h"

int  main(void)
{
    FILE *fin, *fout;

    // ��������� � ��������� �����
    if (!(fout = fopen("tree.res","w")))
        { printf("\n Cannot open file tree.res\n"); return -1; }
    if (!(fin = fopen("tree.dat","r")))
        { printf("\n Cannot open file tree.dat\n"); return -1; }

    // ��������� ������ ������� �� �����
    Tree tr(fin);
    fclose(fin);

    // ����������� �������� ������
    printf("\nThe tree is :\n");
    T_Print(stdout,tr.root);
    T_Print(fout,tr.root);

    solve(tr.root);
    // ���� ������� �������� ������ ����� �������
    // ��� ������� ������������ ������

    // ��������� ���� ����������
    fclose(fout);
    return 0;
}

