#include <stdio.h>
#include "aes_conf.h"
#include "util.h"

void printfDiff( u1byte in_blk[16], u1byte out_blk[16] ) {
int num ; // 
u1byte diff[16] = {0, } ; //
int i ;
printf(" �Է�1: \n") ;
for( i = 0 ; i < 16 ; i++ ) {
printf("%02x ", in_blk[i]) ;
}
printfBit( in_blk ) ; // 
printf("\n") ;
printf(" �Է�2: \n") ;
for( i = 0 ; i < 16 ; i++ ) {
printf("%02x ", out_blk[i]) ;
}
printfBit( out_blk ) ;
for( i = 0 ; i < 16 ; i++ ) {
diff[i] = in_blk[i] ^ out_blk[i] ;
}
num = numOfOne( diff ) ; // 1 ��Ʈ �� �� ������ ����ϴ� �Լ�
printf(" �ٸ� ��Ʈ ��: %d \n\n", num) ;
}
// (4 , 32 ) �Է� ���� ��Ʈ ������ ��� ��Ʈ���� �� ĭ ��� ��Ʈ���� �� �� ���
void printfBit( u1byte in[16] ) {
int i, j ;
// 0��° �迭���� ���
for( i = 0 ; i < 16 ; i++ ) {
if( i % 4 == 0 ) { // 32��Ʈ ��� �� �� �� ���
printf("\n") ;
}
// �ֻ��� ��Ʈ���� �� ����Ʈ ���
for( j = 0 ; j < 8 ; j++ ) {
if( in[i] & ( MASK01 >> j ) ) {
printf("1 ") ;
}
else {
printf("0 ") ;
}
if( j % 4 == 0 ) { // 4��Ʈ ��� �� �� ĭ ���
printf(" ") ;
}
}
}
printf("\n") ;
}
// 1 �Է� ������ ��Ʈ ���� �� ������ ���
int numOfOne( u1byte in[16] ) {
int num = 0 ; // 1�� ����
int i, j ;
for( i = 0; i< 16; i++ )
for( j = 0; j < 8; j++ )
if( in[i] & ( MASK01 >> j ) ) {
num++ ;
}
return( num ) ;
}
int compare(u1byte array1[16], u1byte array2[16]) {

          int i = 0 ;

          int same = 1 ;


          while( i < 16 ) {

                    if( array1[i] == array2[i] )

                              i++ ;

                    else {

                              return(!same) ;

                    }

          }


          return(same) ;

}
void printfHex(u1byte in[16]) {

         int i ;


          for( i = 0 ; i < 16 ; i++ )

                    printf("%02x ", in[i]) ;

          printf("\n") ;

}
