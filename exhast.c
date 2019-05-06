#include <stdio.h>
#include <time.h>
#include "aes_conf.h"
#include "util.h"
#include <stdlib.h>
#include <windows.h>

int main(){

          u1byte in_blk[16] = {0x00, 0x11, 0x22, 0x33, 0x44, 0x55, 0x66, 0x77,

                               0x88, 0x99, 0xaa, 0xbb, 0xcc, 0xdd, 0xee, 0xff };

          u1byte in_key[16] = {0x14, 0x6e, 0x3f, 0xac, 0x47, 0x62, 0xf7, 0x96,

                               0xe5, 0x3b, 0x26, 0x00, 0x00, 0x00, 0x00, 0x00 };

          u1byte out_blk[16] = {0x82, 0x3e, 0x4a, 0x7e, 0x85, 0xc9, 0xde, 0xfd,

                                0x32, 0x94, 0x77, 0xd8, 0x1a, 0x29, 0x33, 0xe6 };

          u1byte out_comp[16] = {0x00, } ; // ���� Ű�� ������ ���� ��ȣȭ�� ���� ���� ��

          u4byte key_len = 128;

          unsigned int clock1, clock2, clock_diff;

          double time;

          int a, b, c, d, e;
          clock1 = clock(); //���α׷� ����ð� ���� cpu����ð�

     for(a = 128; a < 159; a++){

    	 in_key[11] = a ;
    	 printf("�н���Ʈ ã�� ��.... %d\n", a);

       for( b = 0 ; b < 255; b++ ) {

    	   in_key[12] = b ;
    	   

          for( c = 0 ; c < 255; c++ ) {

                    in_key[13] = c ;

                    for( d = 0 ; d < 255; d++ ) {

                              in_key[14] = d ;

                              for( e = 0 ; e < 255 ; e++ ) {

                                        in_key[15] = e ;

                                        set_key(in_key, key_len) ;

                                        encrypt(in_blk, out_comp) ;

                                        if( compare(out_comp, out_blk) ) {

                                                  printfHex(in_key) ;
                                                  clock2 = clock();
                                                  clock_diff = clock2 - clock1;

                                                  time = (double) clock_diff / CLOCKS_PER_SEC;

                                                  printf("\n");
                                                  printf(" %10.3f sec \n", time);
                                                  system("pause");
                                                  exit(0) ;

                                        }

                              }

                    }


          }
       }
     }

          return(0) ;

    }
