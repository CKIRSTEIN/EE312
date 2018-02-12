/* Project2.cpp
 * Carrington Kirstein
 * EE312, Summer 2017
 * Project 2, Matrix Multiplication
 */

#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include "MatrixMultiply.h"

void multiplyMatrices(
        double a[],
        const uint32_t a_rows,
        const uint32_t a_cols,
        double b[],
        const uint32_t b_cols,
        double c[]) {
    // https://en.wikipedia.org/wiki/Row-_and_column-major_order

    int count = 0;
    uint32_t i = 0;
    uint32_t j = 0;
    uint32_t d = 0;
    uint32_t e = 0;
    uint32_t f = 0;
    uint32_t g = 0;
    int k = 0;
    double sum = 0;
    double n = 0;

    while (count < (a_rows*b_cols)) {
        f=i;
        g=j;

       while(j<b_cols){
        k=0;            //reinitialize variables
        sum=0;
        d=i;
        e=j;
        while (k < a_cols) {
            n = a[i] * b[j];
            sum = sum + n;
            i++;
            j = j + b_cols;
            k++;
        }
        c[count] = sum;
        count++;
        i=d;
        j=e+1;
       }
        i=f+a_cols;
        j=g;
    }
}

double** multiplyMatricesPtr(
        double** a,
        const uint32_t a_rows,
        const uint32_t a_cols,
        double** b,
        const uint32_t b_cols) {

    int count2=0;
    int count = 0;
    double i=0;
    double* j;
   // double** d;
    int e = 0;
    int f = 0;
    int g = 0;
    int m =0;
    int q=0;
    int r=0;
    int k = 0;
    double sum = 0;
    double n = 0;
    double h=0;
    double* o;
    double** c;
    double* p;

    c = (double **)malloc(sizeof(double *) * b_cols);
    for (int i = 0; i < a_rows; i++) {
        *(c + i) = (double *)malloc(sizeof(double) * a_rows);
    }



    while (count2 < a_rows) {


       while (count < b_cols) {


            while (k < a_cols) {
                p=*(a+g);
                h=*(p+f);
                //h = **a;              //number in matrix
                //h=**(a+g);
                o = *(b + e);           //address of the next row
                i = *(o+m);
                n = h * i;
                sum = sum + n;
                f++;
                e++;
                k++;
            }
           //**(c+count)=sum;
           c[count2][count]=sum;
            k=0;
           sum=0;
            f=0;
            e=0;
            m++;
            count++;

       }
        count=0;
        count2++;
        g++;
        f=0;
        e=0;
        m=0;

    }

    return c;

    return NULL;
}

// https://en.wikipedia.org/wiki/Transpose
double** transposeMatrix(
         double** a,
         const uint32_t a_rows,
         const uint32_t a_cols) {

    double** transpose;
    double *j;
    double g;
    int num_count = 0;
    int col_count = 0;
    int count = 0;
    int count2 = 0;
    int count3=0;


   transpose = (double **) malloc(sizeof(double*)* a_rows);
    for (int i = 0; i <a_cols; i++) {
        *(transpose + i) = (double *) malloc(sizeof(double) *a_cols);
    }

//    transpose=&*(transpose);
  //  *(transpose)=&**(transpose);

    while (col_count < a_cols) {

        while (num_count < a_rows) {
            //transpose[count][col_count]=*(j + col_count);
            j = *(a + count);
            transpose[col_count][count]=*(j + col_count);
            //*(transpose+col_count)=j;
           // **(transpose + count2) = *(j + col_count);
            //g = **(transpose + count2);
            g=transpose[count][col_count];
            num_count++;
            count++;
            count2++;
        }
        //count3++;
        //*(transpose+count3)=&**(transpose+count2);
        num_count = 0;
        count = 0;
        col_count++;
    }

    return transpose;

    return NULL;

}

