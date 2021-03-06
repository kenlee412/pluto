

#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <math.h>

double X[N][N+20];
double A[N][N+20];
double B[N][N+20];

void init_arrays()
{
  int i, j;
  for (i=0; i<N; i++)
    for (j=0; j<N; j++)
      {
        A[i][j] = (1+(i*j)%1024)/2.0;
        B[i][j] = (1+(i*j)%1024)/3.0;
        X[i][j] = (1+(i*j)%1024)/3.0;
      }
}

double rtclock()
{
  struct timezone tzp;
  struct timeval tp;
  int stat;
  gettimeofday (&tp, &tzp);
  return (tp.tv_sec + tp.tv_usec*1.0e-6);
}

int main()
{
  init_arrays();

  double annot_t_start=0, annot_t_end=0, annot_t_total=0;
  int annot_i;

  for (annot_i=0; annot_i<REPS; annot_i++)
  {
    annot_t_start = rtclock();
    

#define ceild(n,d)  ceil(((double)(n))/((double)(d)))
#define floord(n,d) floor(((double)(n))/((double)(d)))
#define max(x,y)    ((x) > (y)? (x) : (y))
#define min(x,y)    ((x) < (y)? (x) : (y))

	#define S1(zT0,zT1,zT2,zT3,zT4,zT5,t,i1,i2)	{X[i1][i2]=X[i1][i2]-X[i1][i2-1]*A[i1][i2]/B[i1][i2-1];}
	#define S2(zT0,zT1,zT2,zT3,zT4,zT5,t,i1,i2)	{B[i1][i2]=B[i1][i2]-A[i1][i2]*A[i1][i2]/B[i1][i2-1];}
	#define S3(zT0,zT1,zT2,zT3,zT4,zT5,t,i1,i2)	{X[i1][i2]=X[i1][i2]-X[i1-1][i2]*A[i1][i2]/B[i1-1][i2];}
	#define S4(zT0,zT1,zT2,zT3,zT4,zT5,t,i1,i2)	{B[i1][i2]=B[i1][i2]-A[i1][i2]*A[i1][i2]/B[i1-1][i2];}

	int c1, c2, c3, c4, c5, c6, c7, c8, c9, c10;

	register int lbv, ubv;

/* Generated from PLuTo-produced CLooG file by CLooG v0.14.1 64 bits in 19.73s. */
for (c1=0;c1<=floord(T-1,256);c1++) {
  for (c2=max(0,ceild(256*c1-255,256));c2<=min(floord(T+N-2,256),floord(256*c1+N+254,256));c2++) {
    for (c3=max(max(ceild(256*c2-N-253,256),ceild(128*c1-127,128)),0);c3<=min(min(floord(256*c2+N+254,256),floord(T+N-1,256)),floord(256*c1+N+255,256));c3++) {
      for (c4=max(max(max(8*c1,0),ceild(256*c2-N-30,32)),ceild(256*c3-N-31,32));c4<=min(min(min(floord(256*c2+255,32),floord(128*c3+127,16)),8*c1+7),floord(T-1,32));c4++) {
        for (c5=max(max(max(ceild(256*c3-N-30,32),8*c2),ceild(32*c4-31,32)),0);c5<=min(min(min(8*c2+7,floord(T+N-2,32)),floord(32*c4+N+30,32)),floord(256*c3+N+253,32));c5++) {
          for (c6=max(max(max(8*c3,ceild(16*c4-15,16)),ceild(32*c5-N-29,32)),0);c6<=min(min(min(floord(32*c5+N+30,32),floord(32*c4+N+31,32)),8*c3+7),floord(T+N-1,32));c6++) {
            if ((c4 <= floord(32*c6-N,32)) && (c5 <= floord(32*c6-1,32)) && (c6 >= ceild(N,32))) {
              for (c8=max(32*c5,32*c6-N+1);c8<=min(32*c6-1,32*c5+31);c8++) {
                S3(c1,-c1+c2,-c1+c3,c4,-c4+c5,-c4+c6,32*c6-N,-32*c6+c8+N,N-1) ;
                S4(c1,-c1+c2,-c1+c3,c4,-c4+c5,-c4+c6,32*c6-N,-32*c6+c8+N,N-1) ;
              }
            }
            for (c7=max(max(max(32*c6-N+1,32*c5-N+1),0),32*c4);c7<=min(min(min(T-1,32*c4+31),32*c5-1),32*c6-N+31);c7++) {
              for (c8=32*c5;c8<=min(32*c5+31,c7+N-1);c8++) {
                for (c9=32*c6;c9<=c7+N-1;c9++) {
                  S1(c1,-c1+c2,-c1+c3,c4,-c4+c5,-c4+c6,c7,-c7+c8,-c7+c9) ;
                  S2(c1,-c1+c2,-c1+c3,c4,-c4+c5,-c4+c6,c7,-c7+c8,-c7+c9) ;
                  S3(c1,-c1+c2,-c1+c3,c4,-c4+c5,-c4+c6,c7,-c7+c8,-c7+c9-1) ;
                  S4(c1,-c1+c2,-c1+c3,c4,-c4+c5,-c4+c6,c7,-c7+c8,-c7+c9-1) ;
                }
                S3(c1,-c1+c2,-c1+c3,c4,-c4+c5,-c4+c6,c7,-c7+c8,N-1) ;
                S4(c1,-c1+c2,-c1+c3,c4,-c4+c5,-c4+c6,c7,-c7+c8,N-1) ;
              }
            }
            for (c7=max(max(max(32*c5,32*c6-N+1),0),32*c4);c7<=min(min(min(T-1,32*c4+31),32*c5+30),32*c6-N+31);c7++) {
              for (c9=32*c6;c9<=c7+N-1;c9++) {
                S1(c1,-c1+c2,-c1+c3,c4,-c4+c5,-c4+c6,c7,0,-c7+c9) ;
                S2(c1,-c1+c2,-c1+c3,c4,-c4+c5,-c4+c6,c7,0,-c7+c9) ;
              }
              for (c8=c7+1;c8<=32*c5+31;c8++) {
                for (c9=32*c6;c9<=c7+N-1;c9++) {
                  S1(c1,-c1+c2,-c1+c3,c4,-c4+c5,-c4+c6,c7,-c7+c8,-c7+c9) ;
                  S2(c1,-c1+c2,-c1+c3,c4,-c4+c5,-c4+c6,c7,-c7+c8,-c7+c9) ;
                  S3(c1,-c1+c2,-c1+c3,c4,-c4+c5,-c4+c6,c7,-c7+c8,-c7+c9-1) ;
                  S4(c1,-c1+c2,-c1+c3,c4,-c4+c5,-c4+c6,c7,-c7+c8,-c7+c9-1) ;
                }
                S3(c1,-c1+c2,-c1+c3,c4,-c4+c5,-c4+c6,c7,-c7+c8,N-1) ;
                S4(c1,-c1+c2,-c1+c3,c4,-c4+c5,-c4+c6,c7,-c7+c8,N-1) ;
              }
            }
            for (c7=max(max(max(0,32*c4),32*c5-N+1),32*c6-N+32);c7<=min(min(min(T-1,32*c4+31),32*c6+30),32*c5-1);c7++) {
              for (c8=32*c5;c8<=min(32*c5+31,c7+N-1);c8++) {
                for (c9=max(32*c6,c7+1);c9<=32*c6+31;c9++) {
                  S1(c1,-c1+c2,-c1+c3,c4,-c4+c5,-c4+c6,c7,-c7+c8,-c7+c9) ;
                  S2(c1,-c1+c2,-c1+c3,c4,-c4+c5,-c4+c6,c7,-c7+c8,-c7+c9) ;
                  S3(c1,-c1+c2,-c1+c3,c4,-c4+c5,-c4+c6,c7,-c7+c8,-c7+c9-1) ;
                  S4(c1,-c1+c2,-c1+c3,c4,-c4+c5,-c4+c6,c7,-c7+c8,-c7+c9-1) ;
                }
              }
            }
            for (c7=max(max(max(32*c5,32*c6-N+32),0),32*c4);c7<=min(min(min(T-1,32*c4+31),32*c5+30),32*c6+30);c7++) {
              for (c9=max(c7+1,32*c6);c9<=32*c6+31;c9++) {
                S1(c1,-c1+c2,-c1+c3,c4,-c4+c5,-c4+c6,c7,0,-c7+c9) ;
                S2(c1,-c1+c2,-c1+c3,c4,-c4+c5,-c4+c6,c7,0,-c7+c9) ;
              }
/*@ begin Loop(
transform UnrollJam(ufactor=8)
              for (c8=c7+1;c8<=32*c5+31;c8++) 
transform Unroll(ufactor=8)
                for (c9=max(32*c6,c7+1);c9<=32*c6+31;c9++) 
{
                  S1(c1,-c1+c2,-c1+c3,c4,-c4+c5,-c4+c6,c7,-c7+c8,-c7+c9) ;
                  S2(c1,-c1+c2,-c1+c3,c4,-c4+c5,-c4+c6,c7,-c7+c8,-c7+c9) ;
                  S3(c1,-c1+c2,-c1+c3,c4,-c4+c5,-c4+c6,c7,-c7+c8,-c7+c9-1) ;
                  S4(c1,-c1+c2,-c1+c3,c4,-c4+c5,-c4+c6,c7,-c7+c8,-c7+c9-1) ;
}
) @*/{ 

  for (c8 = c7 + 1; c8 <= 32 * c5 + 31 - 7; c8 = c8 + 8)     { 

      for (c9 = max(32 * c6, c7 + 1); c9 <= 32 * c6 + 31 - 7; c9 = c9 + 8)         { 
          S1(c1, -c1 + c2, -c1 + c3, c4, -c4 + c5, -c4 + c6, c7, -c7 + c8, -c7 + c9); 
          S2(c1, -c1 + c2, -c1 + c3, c4, -c4 + c5, -c4 + c6, c7, -c7 + c8, -c7 + c9); 
          S3(c1, -c1 + c2, -c1 + c3, c4, -c4 + c5, -c4 + c6, c7, -c7 + c8, -c7 + c9 - 1); 
          S4(c1, -c1 + c2, -c1 + c3, c4, -c4 + c5, -c4 + c6, c7, -c7 + c8, -c7 + c9 - 1); 
          S1(c1, -c1 + c2, -c1 + c3, c4, -c4 + c5, -c4 + c6, c7, -c7 + c8, -c7 + (c9 + 1)); 
          S2(c1, -c1 + c2, -c1 + c3, c4, -c4 + c5, -c4 + c6, c7, -c7 + c8, -c7 + (c9 + 1)); 
          S3(c1, -c1 + c2, -c1 + c3, c4, -c4 + c5, -c4 + c6, c7, -c7 + c8, -c7 + (c9 + 1) - 1); 
          S4(c1, -c1 + c2, -c1 + c3, c4, -c4 + c5, -c4 + c6, c7, -c7 + c8, -c7 + (c9 + 1) - 1); 
          S1(c1, -c1 + c2, -c1 + c3, c4, -c4 + c5, -c4 + c6, c7, -c7 + c8, -c7 + (c9 + 2)); 
          S2(c1, -c1 + c2, -c1 + c3, c4, -c4 + c5, -c4 + c6, c7, -c7 + c8, -c7 + (c9 + 2)); 
          S3(c1, -c1 + c2, -c1 + c3, c4, -c4 + c5, -c4 + c6, c7, -c7 + c8, -c7 + (c9 + 2) - 1); 
          S4(c1, -c1 + c2, -c1 + c3, c4, -c4 + c5, -c4 + c6, c7, -c7 + c8, -c7 + (c9 + 2) - 1); 
          S1(c1, -c1 + c2, -c1 + c3, c4, -c4 + c5, -c4 + c6, c7, -c7 + c8, -c7 + (c9 + 3)); 
          S2(c1, -c1 + c2, -c1 + c3, c4, -c4 + c5, -c4 + c6, c7, -c7 + c8, -c7 + (c9 + 3)); 
          S3(c1, -c1 + c2, -c1 + c3, c4, -c4 + c5, -c4 + c6, c7, -c7 + c8, -c7 + (c9 + 3) - 1); 
          S4(c1, -c1 + c2, -c1 + c3, c4, -c4 + c5, -c4 + c6, c7, -c7 + c8, -c7 + (c9 + 3) - 1); 
          S1(c1, -c1 + c2, -c1 + c3, c4, -c4 + c5, -c4 + c6, c7, -c7 + c8, -c7 + (c9 + 4)); 
          S2(c1, -c1 + c2, -c1 + c3, c4, -c4 + c5, -c4 + c6, c7, -c7 + c8, -c7 + (c9 + 4)); 
          S3(c1, -c1 + c2, -c1 + c3, c4, -c4 + c5, -c4 + c6, c7, -c7 + c8, -c7 + (c9 + 4) - 1); 
          S4(c1, -c1 + c2, -c1 + c3, c4, -c4 + c5, -c4 + c6, c7, -c7 + c8, -c7 + (c9 + 4) - 1); 
          S1(c1, -c1 + c2, -c1 + c3, c4, -c4 + c5, -c4 + c6, c7, -c7 + c8, -c7 + (c9 + 5)); 
          S2(c1, -c1 + c2, -c1 + c3, c4, -c4 + c5, -c4 + c6, c7, -c7 + c8, -c7 + (c9 + 5)); 
          S3(c1, -c1 + c2, -c1 + c3, c4, -c4 + c5, -c4 + c6, c7, -c7 + c8, -c7 + (c9 + 5) - 1); 
          S4(c1, -c1 + c2, -c1 + c3, c4, -c4 + c5, -c4 + c6, c7, -c7 + c8, -c7 + (c9 + 5) - 1); 
          S1(c1, -c1 + c2, -c1 + c3, c4, -c4 + c5, -c4 + c6, c7, -c7 + c8, -c7 + (c9 + 6)); 
          S2(c1, -c1 + c2, -c1 + c3, c4, -c4 + c5, -c4 + c6, c7, -c7 + c8, -c7 + (c9 + 6)); 
          S3(c1, -c1 + c2, -c1 + c3, c4, -c4 + c5, -c4 + c6, c7, -c7 + c8, -c7 + (c9 + 6) - 1); 
          S4(c1, -c1 + c2, -c1 + c3, c4, -c4 + c5, -c4 + c6, c7, -c7 + c8, -c7 + (c9 + 6) - 1); 
          S1(c1, -c1 + c2, -c1 + c3, c4, -c4 + c5, -c4 + c6, c7, -c7 + c8, -c7 + (c9 + 7)); 
          S2(c1, -c1 + c2, -c1 + c3, c4, -c4 + c5, -c4 + c6, c7, -c7 + c8, -c7 + (c9 + 7)); 
          S3(c1, -c1 + c2, -c1 + c3, c4, -c4 + c5, -c4 + c6, c7, -c7 + c8, -c7 + (c9 + 7) - 1); 
          S4(c1, -c1 + c2, -c1 + c3, c4, -c4 + c5, -c4 + c6, c7, -c7 + c8, -c7 + (c9 + 7) - 1); 
          S1(c1, -c1 + c2, -c1 + c3, c4, -c4 + c5, -c4 + c6, c7, -c7 + (c8 + 1), -c7 + c9); 
          S2(c1, -c1 + c2, -c1 + c3, c4, -c4 + c5, -c4 + c6, c7, -c7 + (c8 + 1), -c7 + c9); 
          S3(c1, -c1 + c2, -c1 + c3, c4, -c4 + c5, -c4 + c6, c7, -c7 + (c8 + 1), -c7 + c9 - 1); 
          S4(c1, -c1 + c2, -c1 + c3, c4, -c4 + c5, -c4 + c6, c7, -c7 + (c8 + 1), -c7 + c9 - 1); 
          S1(c1, -c1 + c2, -c1 + c3, c4, -c4 + c5, -c4 + c6, c7, -c7 + (c8 + 1), -c7 + (c9 + 1)); 
          S2(c1, -c1 + c2, -c1 + c3, c4, -c4 + c5, -c4 + c6, c7, -c7 + (c8 + 1), -c7 + (c9 + 1)); 
          S3(c1, -c1 + c2, -c1 + c3, c4, -c4 + c5, -c4 + c6, c7, -c7 + (c8 + 1), -c7 + (c9 + 1) - 1); 
          S4(c1, -c1 + c2, -c1 + c3, c4, -c4 + c5, -c4 + c6, c7, -c7 + (c8 + 1), -c7 + (c9 + 1) - 1); 
          S1(c1, -c1 + c2, -c1 + c3, c4, -c4 + c5, -c4 + c6, c7, -c7 + (c8 + 1), -c7 + (c9 + 2)); 
          S2(c1, -c1 + c2, -c1 + c3, c4, -c4 + c5, -c4 + c6, c7, -c7 + (c8 + 1), -c7 + (c9 + 2)); 
          S3(c1, -c1 + c2, -c1 + c3, c4, -c4 + c5, -c4 + c6, c7, -c7 + (c8 + 1), -c7 + (c9 + 2) - 1); 
          S4(c1, -c1 + c2, -c1 + c3, c4, -c4 + c5, -c4 + c6, c7, -c7 + (c8 + 1), -c7 + (c9 + 2) - 1); 
          S1(c1, -c1 + c2, -c1 + c3, c4, -c4 + c5, -c4 + c6, c7, -c7 + (c8 + 1), -c7 + (c9 + 3)); 
          S2(c1, -c1 + c2, -c1 + c3, c4, -c4 + c5, -c4 + c6, c7, -c7 + (c8 + 1), -c7 + (c9 + 3)); 
          S3(c1, -c1 + c2, -c1 + c3, c4, -c4 + c5, -c4 + c6, c7, -c7 + (c8 + 1), -c7 + (c9 + 3) - 1); 
          S4(c1, -c1 + c2, -c1 + c3, c4, -c4 + c5, -c4 + c6, c7, -c7 + (c8 + 1), -c7 + (c9 + 3) - 1); 
          S1(c1, -c1 + c2, -c1 + c3, c4, -c4 + c5, -c4 + c6, c7, -c7 + (c8 + 1), -c7 + (c9 + 4)); 
          S2(c1, -c1 + c2, -c1 + c3, c4, -c4 + c5, -c4 + c6, c7, -c7 + (c8 + 1), -c7 + (c9 + 4)); 
          S3(c1, -c1 + c2, -c1 + c3, c4, -c4 + c5, -c4 + c6, c7, -c7 + (c8 + 1), -c7 + (c9 + 4) - 1); 
          S4(c1, -c1 + c2, -c1 + c3, c4, -c4 + c5, -c4 + c6, c7, -c7 + (c8 + 1), -c7 + (c9 + 4) - 1); 
          S1(c1, -c1 + c2, -c1 + c3, c4, -c4 + c5, -c4 + c6, c7, -c7 + (c8 + 1), -c7 + (c9 + 5)); 
          S2(c1, -c1 + c2, -c1 + c3, c4, -c4 + c5, -c4 + c6, c7, -c7 + (c8 + 1), -c7 + (c9 + 5)); 
          S3(c1, -c1 + c2, -c1 + c3, c4, -c4 + c5, -c4 + c6, c7, -c7 + (c8 + 1), -c7 + (c9 + 5) - 1); 
          S4(c1, -c1 + c2, -c1 + c3, c4, -c4 + c5, -c4 + c6, c7, -c7 + (c8 + 1), -c7 + (c9 + 5) - 1); 
          S1(c1, -c1 + c2, -c1 + c3, c4, -c4 + c5, -c4 + c6, c7, -c7 + (c8 + 1), -c7 + (c9 + 6)); 
          S2(c1, -c1 + c2, -c1 + c3, c4, -c4 + c5, -c4 + c6, c7, -c7 + (c8 + 1), -c7 + (c9 + 6)); 
          S3(c1, -c1 + c2, -c1 + c3, c4, -c4 + c5, -c4 + c6, c7, -c7 + (c8 + 1), -c7 + (c9 + 6) - 1); 
          S4(c1, -c1 + c2, -c1 + c3, c4, -c4 + c5, -c4 + c6, c7, -c7 + (c8 + 1), -c7 + (c9 + 6) - 1); 
          S1(c1, -c1 + c2, -c1 + c3, c4, -c4 + c5, -c4 + c6, c7, -c7 + (c8 + 1), -c7 + (c9 + 7)); 
          S2(c1, -c1 + c2, -c1 + c3, c4, -c4 + c5, -c4 + c6, c7, -c7 + (c8 + 1), -c7 + (c9 + 7)); 
          S3(c1, -c1 + c2, -c1 + c3, c4, -c4 + c5, -c4 + c6, c7, -c7 + (c8 + 1), -c7 + (c9 + 7) - 1); 
          S4(c1, -c1 + c2, -c1 + c3, c4, -c4 + c5, -c4 + c6, c7, -c7 + (c8 + 1), -c7 + (c9 + 7) - 1); 
          S1(c1, -c1 + c2, -c1 + c3, c4, -c4 + c5, -c4 + c6, c7, -c7 + (c8 + 2), -c7 + c9); 
          S2(c1, -c1 + c2, -c1 + c3, c4, -c4 + c5, -c4 + c6, c7, -c7 + (c8 + 2), -c7 + c9); 
          S3(c1, -c1 + c2, -c1 + c3, c4, -c4 + c5, -c4 + c6, c7, -c7 + (c8 + 2), -c7 + c9 - 1); 
          S4(c1, -c1 + c2, -c1 + c3, c4, -c4 + c5, -c4 + c6, c7, -c7 + (c8 + 2), -c7 + c9 - 1); 
          S1(c1, -c1 + c2, -c1 + c3, c4, -c4 + c5, -c4 + c6, c7, -c7 + (c8 + 2), -c7 + (c9 + 1)); 
          S2(c1, -c1 + c2, -c1 + c3, c4, -c4 + c5, -c4 + c6, c7, -c7 + (c8 + 2), -c7 + (c9 + 1)); 
          S3(c1, -c1 + c2, -c1 + c3, c4, -c4 + c5, -c4 + c6, c7, -c7 + (c8 + 2), -c7 + (c9 + 1) - 1); 
          S4(c1, -c1 + c2, -c1 + c3, c4, -c4 + c5, -c4 + c6, c7, -c7 + (c8 + 2), -c7 + (c9 + 1) - 1); 
          S1(c1, -c1 + c2, -c1 + c3, c4, -c4 + c5, -c4 + c6, c7, -c7 + (c8 + 2), -c7 + (c9 + 2)); 
          S2(c1, -c1 + c2, -c1 + c3, c4, -c4 + c5, -c4 + c6, c7, -c7 + (c8 + 2), -c7 + (c9 + 2)); 
          S3(c1, -c1 + c2, -c1 + c3, c4, -c4 + c5, -c4 + c6, c7, -c7 + (c8 + 2), -c7 + (c9 + 2) - 1); 
          S4(c1, -c1 + c2, -c1 + c3, c4, -c4 + c5, -c4 + c6, c7, -c7 + (c8 + 2), -c7 + (c9 + 2) - 1); 
          S1(c1, -c1 + c2, -c1 + c3, c4, -c4 + c5, -c4 + c6, c7, -c7 + (c8 + 2), -c7 + (c9 + 3)); 
          S2(c1, -c1 + c2, -c1 + c3, c4, -c4 + c5, -c4 + c6, c7, -c7 + (c8 + 2), -c7 + (c9 + 3)); 
          S3(c1, -c1 + c2, -c1 + c3, c4, -c4 + c5, -c4 + c6, c7, -c7 + (c8 + 2), -c7 + (c9 + 3) - 1); 
          S4(c1, -c1 + c2, -c1 + c3, c4, -c4 + c5, -c4 + c6, c7, -c7 + (c8 + 2), -c7 + (c9 + 3) - 1); 
          S1(c1, -c1 + c2, -c1 + c3, c4, -c4 + c5, -c4 + c6, c7, -c7 + (c8 + 2), -c7 + (c9 + 4)); 
          S2(c1, -c1 + c2, -c1 + c3, c4, -c4 + c5, -c4 + c6, c7, -c7 + (c8 + 2), -c7 + (c9 + 4)); 
          S3(c1, -c1 + c2, -c1 + c3, c4, -c4 + c5, -c4 + c6, c7, -c7 + (c8 + 2), -c7 + (c9 + 4) - 1); 
          S4(c1, -c1 + c2, -c1 + c3, c4, -c4 + c5, -c4 + c6, c7, -c7 + (c8 + 2), -c7 + (c9 + 4) - 1); 
          S1(c1, -c1 + c2, -c1 + c3, c4, -c4 + c5, -c4 + c6, c7, -c7 + (c8 + 2), -c7 + (c9 + 5)); 
          S2(c1, -c1 + c2, -c1 + c3, c4, -c4 + c5, -c4 + c6, c7, -c7 + (c8 + 2), -c7 + (c9 + 5)); 
          S3(c1, -c1 + c2, -c1 + c3, c4, -c4 + c5, -c4 + c6, c7, -c7 + (c8 + 2), -c7 + (c9 + 5) - 1); 
          S4(c1, -c1 + c2, -c1 + c3, c4, -c4 + c5, -c4 + c6, c7, -c7 + (c8 + 2), -c7 + (c9 + 5) - 1); 
          S1(c1, -c1 + c2, -c1 + c3, c4, -c4 + c5, -c4 + c6, c7, -c7 + (c8 + 2), -c7 + (c9 + 6)); 
          S2(c1, -c1 + c2, -c1 + c3, c4, -c4 + c5, -c4 + c6, c7, -c7 + (c8 + 2), -c7 + (c9 + 6)); 
          S3(c1, -c1 + c2, -c1 + c3, c4, -c4 + c5, -c4 + c6, c7, -c7 + (c8 + 2), -c7 + (c9 + 6) - 1); 
          S4(c1, -c1 + c2, -c1 + c3, c4, -c4 + c5, -c4 + c6, c7, -c7 + (c8 + 2), -c7 + (c9 + 6) - 1); 
          S1(c1, -c1 + c2, -c1 + c3, c4, -c4 + c5, -c4 + c6, c7, -c7 + (c8 + 2), -c7 + (c9 + 7)); 
          S2(c1, -c1 + c2, -c1 + c3, c4, -c4 + c5, -c4 + c6, c7, -c7 + (c8 + 2), -c7 + (c9 + 7)); 
          S3(c1, -c1 + c2, -c1 + c3, c4, -c4 + c5, -c4 + c6, c7, -c7 + (c8 + 2), -c7 + (c9 + 7) - 1); 
          S4(c1, -c1 + c2, -c1 + c3, c4, -c4 + c5, -c4 + c6, c7, -c7 + (c8 + 2), -c7 + (c9 + 7) - 1); 
          S1(c1, -c1 + c2, -c1 + c3, c4, -c4 + c5, -c4 + c6, c7, -c7 + (c8 + 3), -c7 + c9); 
          S2(c1, -c1 + c2, -c1 + c3, c4, -c4 + c5, -c4 + c6, c7, -c7 + (c8 + 3), -c7 + c9); 
          S3(c1, -c1 + c2, -c1 + c3, c4, -c4 + c5, -c4 + c6, c7, -c7 + (c8 + 3), -c7 + c9 - 1); 
          S4(c1, -c1 + c2, -c1 + c3, c4, -c4 + c5, -c4 + c6, c7, -c7 + (c8 + 3), -c7 + c9 - 1); 
          S1(c1, -c1 + c2, -c1 + c3, c4, -c4 + c5, -c4 + c6, c7, -c7 + (c8 + 3), -c7 + (c9 + 1)); 
          S2(c1, -c1 + c2, -c1 + c3, c4, -c4 + c5, -c4 + c6, c7, -c7 + (c8 + 3), -c7 + (c9 + 1)); 
          S3(c1, -c1 + c2, -c1 + c3, c4, -c4 + c5, -c4 + c6, c7, -c7 + (c8 + 3), -c7 + (c9 + 1) - 1); 
          S4(c1, -c1 + c2, -c1 + c3, c4, -c4 + c5, -c4 + c6, c7, -c7 + (c8 + 3), -c7 + (c9 + 1) - 1); 
          S1(c1, -c1 + c2, -c1 + c3, c4, -c4 + c5, -c4 + c6, c7, -c7 + (c8 + 3), -c7 + (c9 + 2)); 
          S2(c1, -c1 + c2, -c1 + c3, c4, -c4 + c5, -c4 + c6, c7, -c7 + (c8 + 3), -c7 + (c9 + 2)); 
          S3(c1, -c1 + c2, -c1 + c3, c4, -c4 + c5, -c4 + c6, c7, -c7 + (c8 + 3), -c7 + (c9 + 2) - 1); 
          S4(c1, -c1 + c2, -c1 + c3, c4, -c4 + c5, -c4 + c6, c7, -c7 + (c8 + 3), -c7 + (c9 + 2) - 1); 
          S1(c1, -c1 + c2, -c1 + c3, c4, -c4 + c5, -c4 + c6, c7, -c7 + (c8 + 3), -c7 + (c9 + 3)); 
          S2(c1, -c1 + c2, -c1 + c3, c4, -c4 + c5, -c4 + c6, c7, -c7 + (c8 + 3), -c7 + (c9 + 3)); 
          S3(c1, -c1 + c2, -c1 + c3, c4, -c4 + c5, -c4 + c6, c7, -c7 + (c8 + 3), -c7 + (c9 + 3) - 1); 
          S4(c1, -c1 + c2, -c1 + c3, c4, -c4 + c5, -c4 + c6, c7, -c7 + (c8 + 3), -c7 + (c9 + 3) - 1); 
          S1(c1, -c1 + c2, -c1 + c3, c4, -c4 + c5, -c4 + c6, c7, -c7 + (c8 + 3), -c7 + (c9 + 4)); 
          S2(c1, -c1 + c2, -c1 + c3, c4, -c4 + c5, -c4 + c6, c7, -c7 + (c8 + 3), -c7 + (c9 + 4)); 
          S3(c1, -c1 + c2, -c1 + c3, c4, -c4 + c5, -c4 + c6, c7, -c7 + (c8 + 3), -c7 + (c9 + 4) - 1); 
          S4(c1, -c1 + c2, -c1 + c3, c4, -c4 + c5, -c4 + c6, c7, -c7 + (c8 + 3), -c7 + (c9 + 4) - 1); 
          S1(c1, -c1 + c2, -c1 + c3, c4, -c4 + c5, -c4 + c6, c7, -c7 + (c8 + 3), -c7 + (c9 + 5)); 
          S2(c1, -c1 + c2, -c1 + c3, c4, -c4 + c5, -c4 + c6, c7, -c7 + (c8 + 3), -c7 + (c9 + 5)); 
          S3(c1, -c1 + c2, -c1 + c3, c4, -c4 + c5, -c4 + c6, c7, -c7 + (c8 + 3), -c7 + (c9 + 5) - 1); 
          S4(c1, -c1 + c2, -c1 + c3, c4, -c4 + c5, -c4 + c6, c7, -c7 + (c8 + 3), -c7 + (c9 + 5) - 1); 
          S1(c1, -c1 + c2, -c1 + c3, c4, -c4 + c5, -c4 + c6, c7, -c7 + (c8 + 3), -c7 + (c9 + 6)); 
          S2(c1, -c1 + c2, -c1 + c3, c4, -c4 + c5, -c4 + c6, c7, -c7 + (c8 + 3), -c7 + (c9 + 6)); 
          S3(c1, -c1 + c2, -c1 + c3, c4, -c4 + c5, -c4 + c6, c7, -c7 + (c8 + 3), -c7 + (c9 + 6) - 1); 
          S4(c1, -c1 + c2, -c1 + c3, c4, -c4 + c5, -c4 + c6, c7, -c7 + (c8 + 3), -c7 + (c9 + 6) - 1); 
          S1(c1, -c1 + c2, -c1 + c3, c4, -c4 + c5, -c4 + c6, c7, -c7 + (c8 + 3), -c7 + (c9 + 7)); 
          S2(c1, -c1 + c2, -c1 + c3, c4, -c4 + c5, -c4 + c6, c7, -c7 + (c8 + 3), -c7 + (c9 + 7)); 
          S3(c1, -c1 + c2, -c1 + c3, c4, -c4 + c5, -c4 + c6, c7, -c7 + (c8 + 3), -c7 + (c9 + 7) - 1); 
          S4(c1, -c1 + c2, -c1 + c3, c4, -c4 + c5, -c4 + c6, c7, -c7 + (c8 + 3), -c7 + (c9 + 7) - 1); 
          S1(c1, -c1 + c2, -c1 + c3, c4, -c4 + c5, -c4 + c6, c7, -c7 + (c8 + 4), -c7 + c9); 
          S2(c1, -c1 + c2, -c1 + c3, c4, -c4 + c5, -c4 + c6, c7, -c7 + (c8 + 4), -c7 + c9); 
          S3(c1, -c1 + c2, -c1 + c3, c4, -c4 + c5, -c4 + c6, c7, -c7 + (c8 + 4), -c7 + c9 - 1); 
          S4(c1, -c1 + c2, -c1 + c3, c4, -c4 + c5, -c4 + c6, c7, -c7 + (c8 + 4), -c7 + c9 - 1); 
          S1(c1, -c1 + c2, -c1 + c3, c4, -c4 + c5, -c4 + c6, c7, -c7 + (c8 + 4), -c7 + (c9 + 1)); 
          S2(c1, -c1 + c2, -c1 + c3, c4, -c4 + c5, -c4 + c6, c7, -c7 + (c8 + 4), -c7 + (c9 + 1)); 
          S3(c1, -c1 + c2, -c1 + c3, c4, -c4 + c5, -c4 + c6, c7, -c7 + (c8 + 4), -c7 + (c9 + 1) - 1); 
          S4(c1, -c1 + c2, -c1 + c3, c4, -c4 + c5, -c4 + c6, c7, -c7 + (c8 + 4), -c7 + (c9 + 1) - 1); 
          S1(c1, -c1 + c2, -c1 + c3, c4, -c4 + c5, -c4 + c6, c7, -c7 + (c8 + 4), -c7 + (c9 + 2)); 
          S2(c1, -c1 + c2, -c1 + c3, c4, -c4 + c5, -c4 + c6, c7, -c7 + (c8 + 4), -c7 + (c9 + 2)); 
          S3(c1, -c1 + c2, -c1 + c3, c4, -c4 + c5, -c4 + c6, c7, -c7 + (c8 + 4), -c7 + (c9 + 2) - 1); 
          S4(c1, -c1 + c2, -c1 + c3, c4, -c4 + c5, -c4 + c6, c7, -c7 + (c8 + 4), -c7 + (c9 + 2) - 1); 
          S1(c1, -c1 + c2, -c1 + c3, c4, -c4 + c5, -c4 + c6, c7, -c7 + (c8 + 4), -c7 + (c9 + 3)); 
          S2(c1, -c1 + c2, -c1 + c3, c4, -c4 + c5, -c4 + c6, c7, -c7 + (c8 + 4), -c7 + (c9 + 3)); 
          S3(c1, -c1 + c2, -c1 + c3, c4, -c4 + c5, -c4 + c6, c7, -c7 + (c8 + 4), -c7 + (c9 + 3) - 1); 
          S4(c1, -c1 + c2, -c1 + c3, c4, -c4 + c5, -c4 + c6, c7, -c7 + (c8 + 4), -c7 + (c9 + 3) - 1); 
          S1(c1, -c1 + c2, -c1 + c3, c4, -c4 + c5, -c4 + c6, c7, -c7 + (c8 + 4), -c7 + (c9 + 4)); 
          S2(c1, -c1 + c2, -c1 + c3, c4, -c4 + c5, -c4 + c6, c7, -c7 + (c8 + 4), -c7 + (c9 + 4)); 
          S3(c1, -c1 + c2, -c1 + c3, c4, -c4 + c5, -c4 + c6, c7, -c7 + (c8 + 4), -c7 + (c9 + 4) - 1); 
          S4(c1, -c1 + c2, -c1 + c3, c4, -c4 + c5, -c4 + c6, c7, -c7 + (c8 + 4), -c7 + (c9 + 4) - 1); 
          S1(c1, -c1 + c2, -c1 + c3, c4, -c4 + c5, -c4 + c6, c7, -c7 + (c8 + 4), -c7 + (c9 + 5)); 
          S2(c1, -c1 + c2, -c1 + c3, c4, -c4 + c5, -c4 + c6, c7, -c7 + (c8 + 4), -c7 + (c9 + 5)); 
          S3(c1, -c1 + c2, -c1 + c3, c4, -c4 + c5, -c4 + c6, c7, -c7 + (c8 + 4), -c7 + (c9 + 5) - 1); 
          S4(c1, -c1 + c2, -c1 + c3, c4, -c4 + c5, -c4 + c6, c7, -c7 + (c8 + 4), -c7 + (c9 + 5) - 1); 
          S1(c1, -c1 + c2, -c1 + c3, c4, -c4 + c5, -c4 + c6, c7, -c7 + (c8 + 4), -c7 + (c9 + 6)); 
          S2(c1, -c1 + c2, -c1 + c3, c4, -c4 + c5, -c4 + c6, c7, -c7 + (c8 + 4), -c7 + (c9 + 6)); 
          S3(c1, -c1 + c2, -c1 + c3, c4, -c4 + c5, -c4 + c6, c7, -c7 + (c8 + 4), -c7 + (c9 + 6) - 1); 
          S4(c1, -c1 + c2, -c1 + c3, c4, -c4 + c5, -c4 + c6, c7, -c7 + (c8 + 4), -c7 + (c9 + 6) - 1); 
          S1(c1, -c1 + c2, -c1 + c3, c4, -c4 + c5, -c4 + c6, c7, -c7 + (c8 + 4), -c7 + (c9 + 7)); 
          S2(c1, -c1 + c2, -c1 + c3, c4, -c4 + c5, -c4 + c6, c7, -c7 + (c8 + 4), -c7 + (c9 + 7)); 
          S3(c1, -c1 + c2, -c1 + c3, c4, -c4 + c5, -c4 + c6, c7, -c7 + (c8 + 4), -c7 + (c9 + 7) - 1); 
          S4(c1, -c1 + c2, -c1 + c3, c4, -c4 + c5, -c4 + c6, c7, -c7 + (c8 + 4), -c7 + (c9 + 7) - 1); 
          S1(c1, -c1 + c2, -c1 + c3, c4, -c4 + c5, -c4 + c6, c7, -c7 + (c8 + 5), -c7 + c9); 
          S2(c1, -c1 + c2, -c1 + c3, c4, -c4 + c5, -c4 + c6, c7, -c7 + (c8 + 5), -c7 + c9); 
          S3(c1, -c1 + c2, -c1 + c3, c4, -c4 + c5, -c4 + c6, c7, -c7 + (c8 + 5), -c7 + c9 - 1); 
          S4(c1, -c1 + c2, -c1 + c3, c4, -c4 + c5, -c4 + c6, c7, -c7 + (c8 + 5), -c7 + c9 - 1); 
          S1(c1, -c1 + c2, -c1 + c3, c4, -c4 + c5, -c4 + c6, c7, -c7 + (c8 + 5), -c7 + (c9 + 1)); 
          S2(c1, -c1 + c2, -c1 + c3, c4, -c4 + c5, -c4 + c6, c7, -c7 + (c8 + 5), -c7 + (c9 + 1)); 
          S3(c1, -c1 + c2, -c1 + c3, c4, -c4 + c5, -c4 + c6, c7, -c7 + (c8 + 5), -c7 + (c9 + 1) - 1); 
          S4(c1, -c1 + c2, -c1 + c3, c4, -c4 + c5, -c4 + c6, c7, -c7 + (c8 + 5), -c7 + (c9 + 1) - 1); 
          S1(c1, -c1 + c2, -c1 + c3, c4, -c4 + c5, -c4 + c6, c7, -c7 + (c8 + 5), -c7 + (c9 + 2)); 
          S2(c1, -c1 + c2, -c1 + c3, c4, -c4 + c5, -c4 + c6, c7, -c7 + (c8 + 5), -c7 + (c9 + 2)); 
          S3(c1, -c1 + c2, -c1 + c3, c4, -c4 + c5, -c4 + c6, c7, -c7 + (c8 + 5), -c7 + (c9 + 2) - 1); 
          S4(c1, -c1 + c2, -c1 + c3, c4, -c4 + c5, -c4 + c6, c7, -c7 + (c8 + 5), -c7 + (c9 + 2) - 1); 
          S1(c1, -c1 + c2, -c1 + c3, c4, -c4 + c5, -c4 + c6, c7, -c7 + (c8 + 5), -c7 + (c9 + 3)); 
          S2(c1, -c1 + c2, -c1 + c3, c4, -c4 + c5, -c4 + c6, c7, -c7 + (c8 + 5), -c7 + (c9 + 3)); 
          S3(c1, -c1 + c2, -c1 + c3, c4, -c4 + c5, -c4 + c6, c7, -c7 + (c8 + 5), -c7 + (c9 + 3) - 1); 
          S4(c1, -c1 + c2, -c1 + c3, c4, -c4 + c5, -c4 + c6, c7, -c7 + (c8 + 5), -c7 + (c9 + 3) - 1); 
          S1(c1, -c1 + c2, -c1 + c3, c4, -c4 + c5, -c4 + c6, c7, -c7 + (c8 + 5), -c7 + (c9 + 4)); 
          S2(c1, -c1 + c2, -c1 + c3, c4, -c4 + c5, -c4 + c6, c7, -c7 + (c8 + 5), -c7 + (c9 + 4)); 
          S3(c1, -c1 + c2, -c1 + c3, c4, -c4 + c5, -c4 + c6, c7, -c7 + (c8 + 5), -c7 + (c9 + 4) - 1); 
          S4(c1, -c1 + c2, -c1 + c3, c4, -c4 + c5, -c4 + c6, c7, -c7 + (c8 + 5), -c7 + (c9 + 4) - 1); 
          S1(c1, -c1 + c2, -c1 + c3, c4, -c4 + c5, -c4 + c6, c7, -c7 + (c8 + 5), -c7 + (c9 + 5)); 
          S2(c1, -c1 + c2, -c1 + c3, c4, -c4 + c5, -c4 + c6, c7, -c7 + (c8 + 5), -c7 + (c9 + 5)); 
          S3(c1, -c1 + c2, -c1 + c3, c4, -c4 + c5, -c4 + c6, c7, -c7 + (c8 + 5), -c7 + (c9 + 5) - 1); 
          S4(c1, -c1 + c2, -c1 + c3, c4, -c4 + c5, -c4 + c6, c7, -c7 + (c8 + 5), -c7 + (c9 + 5) - 1); 
          S1(c1, -c1 + c2, -c1 + c3, c4, -c4 + c5, -c4 + c6, c7, -c7 + (c8 + 5), -c7 + (c9 + 6)); 
          S2(c1, -c1 + c2, -c1 + c3, c4, -c4 + c5, -c4 + c6, c7, -c7 + (c8 + 5), -c7 + (c9 + 6)); 
          S3(c1, -c1 + c2, -c1 + c3, c4, -c4 + c5, -c4 + c6, c7, -c7 + (c8 + 5), -c7 + (c9 + 6) - 1); 
          S4(c1, -c1 + c2, -c1 + c3, c4, -c4 + c5, -c4 + c6, c7, -c7 + (c8 + 5), -c7 + (c9 + 6) - 1); 
          S1(c1, -c1 + c2, -c1 + c3, c4, -c4 + c5, -c4 + c6, c7, -c7 + (c8 + 5), -c7 + (c9 + 7)); 
          S2(c1, -c1 + c2, -c1 + c3, c4, -c4 + c5, -c4 + c6, c7, -c7 + (c8 + 5), -c7 + (c9 + 7)); 
          S3(c1, -c1 + c2, -c1 + c3, c4, -c4 + c5, -c4 + c6, c7, -c7 + (c8 + 5), -c7 + (c9 + 7) - 1); 
          S4(c1, -c1 + c2, -c1 + c3, c4, -c4 + c5, -c4 + c6, c7, -c7 + (c8 + 5), -c7 + (c9 + 7) - 1); 
          S1(c1, -c1 + c2, -c1 + c3, c4, -c4 + c5, -c4 + c6, c7, -c7 + (c8 + 6), -c7 + c9); 
          S2(c1, -c1 + c2, -c1 + c3, c4, -c4 + c5, -c4 + c6, c7, -c7 + (c8 + 6), -c7 + c9); 
          S3(c1, -c1 + c2, -c1 + c3, c4, -c4 + c5, -c4 + c6, c7, -c7 + (c8 + 6), -c7 + c9 - 1); 
          S4(c1, -c1 + c2, -c1 + c3, c4, -c4 + c5, -c4 + c6, c7, -c7 + (c8 + 6), -c7 + c9 - 1); 
          S1(c1, -c1 + c2, -c1 + c3, c4, -c4 + c5, -c4 + c6, c7, -c7 + (c8 + 6), -c7 + (c9 + 1)); 
          S2(c1, -c1 + c2, -c1 + c3, c4, -c4 + c5, -c4 + c6, c7, -c7 + (c8 + 6), -c7 + (c9 + 1)); 
          S3(c1, -c1 + c2, -c1 + c3, c4, -c4 + c5, -c4 + c6, c7, -c7 + (c8 + 6), -c7 + (c9 + 1) - 1); 
          S4(c1, -c1 + c2, -c1 + c3, c4, -c4 + c5, -c4 + c6, c7, -c7 + (c8 + 6), -c7 + (c9 + 1) - 1); 
          S1(c1, -c1 + c2, -c1 + c3, c4, -c4 + c5, -c4 + c6, c7, -c7 + (c8 + 6), -c7 + (c9 + 2)); 
          S2(c1, -c1 + c2, -c1 + c3, c4, -c4 + c5, -c4 + c6, c7, -c7 + (c8 + 6), -c7 + (c9 + 2)); 
          S3(c1, -c1 + c2, -c1 + c3, c4, -c4 + c5, -c4 + c6, c7, -c7 + (c8 + 6), -c7 + (c9 + 2) - 1); 
          S4(c1, -c1 + c2, -c1 + c3, c4, -c4 + c5, -c4 + c6, c7, -c7 + (c8 + 6), -c7 + (c9 + 2) - 1); 
          S1(c1, -c1 + c2, -c1 + c3, c4, -c4 + c5, -c4 + c6, c7, -c7 + (c8 + 6), -c7 + (c9 + 3)); 
          S2(c1, -c1 + c2, -c1 + c3, c4, -c4 + c5, -c4 + c6, c7, -c7 + (c8 + 6), -c7 + (c9 + 3)); 
          S3(c1, -c1 + c2, -c1 + c3, c4, -c4 + c5, -c4 + c6, c7, -c7 + (c8 + 6), -c7 + (c9 + 3) - 1); 
          S4(c1, -c1 + c2, -c1 + c3, c4, -c4 + c5, -c4 + c6, c7, -c7 + (c8 + 6), -c7 + (c9 + 3) - 1); 
          S1(c1, -c1 + c2, -c1 + c3, c4, -c4 + c5, -c4 + c6, c7, -c7 + (c8 + 6), -c7 + (c9 + 4)); 
          S2(c1, -c1 + c2, -c1 + c3, c4, -c4 + c5, -c4 + c6, c7, -c7 + (c8 + 6), -c7 + (c9 + 4)); 
          S3(c1, -c1 + c2, -c1 + c3, c4, -c4 + c5, -c4 + c6, c7, -c7 + (c8 + 6), -c7 + (c9 + 4) - 1); 
          S4(c1, -c1 + c2, -c1 + c3, c4, -c4 + c5, -c4 + c6, c7, -c7 + (c8 + 6), -c7 + (c9 + 4) - 1); 
          S1(c1, -c1 + c2, -c1 + c3, c4, -c4 + c5, -c4 + c6, c7, -c7 + (c8 + 6), -c7 + (c9 + 5)); 
          S2(c1, -c1 + c2, -c1 + c3, c4, -c4 + c5, -c4 + c6, c7, -c7 + (c8 + 6), -c7 + (c9 + 5)); 
          S3(c1, -c1 + c2, -c1 + c3, c4, -c4 + c5, -c4 + c6, c7, -c7 + (c8 + 6), -c7 + (c9 + 5) - 1); 
          S4(c1, -c1 + c2, -c1 + c3, c4, -c4 + c5, -c4 + c6, c7, -c7 + (c8 + 6), -c7 + (c9 + 5) - 1); 
          S1(c1, -c1 + c2, -c1 + c3, c4, -c4 + c5, -c4 + c6, c7, -c7 + (c8 + 6), -c7 + (c9 + 6)); 
          S2(c1, -c1 + c2, -c1 + c3, c4, -c4 + c5, -c4 + c6, c7, -c7 + (c8 + 6), -c7 + (c9 + 6)); 
          S3(c1, -c1 + c2, -c1 + c3, c4, -c4 + c5, -c4 + c6, c7, -c7 + (c8 + 6), -c7 + (c9 + 6) - 1); 
          S4(c1, -c1 + c2, -c1 + c3, c4, -c4 + c5, -c4 + c6, c7, -c7 + (c8 + 6), -c7 + (c9 + 6) - 1); 
          S1(c1, -c1 + c2, -c1 + c3, c4, -c4 + c5, -c4 + c6, c7, -c7 + (c8 + 6), -c7 + (c9 + 7)); 
          S2(c1, -c1 + c2, -c1 + c3, c4, -c4 + c5, -c4 + c6, c7, -c7 + (c8 + 6), -c7 + (c9 + 7)); 
          S3(c1, -c1 + c2, -c1 + c3, c4, -c4 + c5, -c4 + c6, c7, -c7 + (c8 + 6), -c7 + (c9 + 7) - 1); 
          S4(c1, -c1 + c2, -c1 + c3, c4, -c4 + c5, -c4 + c6, c7, -c7 + (c8 + 6), -c7 + (c9 + 7) - 1); 
          S1(c1, -c1 + c2, -c1 + c3, c4, -c4 + c5, -c4 + c6, c7, -c7 + (c8 + 7), -c7 + c9); 
          S2(c1, -c1 + c2, -c1 + c3, c4, -c4 + c5, -c4 + c6, c7, -c7 + (c8 + 7), -c7 + c9); 
          S3(c1, -c1 + c2, -c1 + c3, c4, -c4 + c5, -c4 + c6, c7, -c7 + (c8 + 7), -c7 + c9 - 1); 
          S4(c1, -c1 + c2, -c1 + c3, c4, -c4 + c5, -c4 + c6, c7, -c7 + (c8 + 7), -c7 + c9 - 1); 
          S1(c1, -c1 + c2, -c1 + c3, c4, -c4 + c5, -c4 + c6, c7, -c7 + (c8 + 7), -c7 + (c9 + 1)); 
          S2(c1, -c1 + c2, -c1 + c3, c4, -c4 + c5, -c4 + c6, c7, -c7 + (c8 + 7), -c7 + (c9 + 1)); 
          S3(c1, -c1 + c2, -c1 + c3, c4, -c4 + c5, -c4 + c6, c7, -c7 + (c8 + 7), -c7 + (c9 + 1) - 1); 
          S4(c1, -c1 + c2, -c1 + c3, c4, -c4 + c5, -c4 + c6, c7, -c7 + (c8 + 7), -c7 + (c9 + 1) - 1); 
          S1(c1, -c1 + c2, -c1 + c3, c4, -c4 + c5, -c4 + c6, c7, -c7 + (c8 + 7), -c7 + (c9 + 2)); 
          S2(c1, -c1 + c2, -c1 + c3, c4, -c4 + c5, -c4 + c6, c7, -c7 + (c8 + 7), -c7 + (c9 + 2)); 
          S3(c1, -c1 + c2, -c1 + c3, c4, -c4 + c5, -c4 + c6, c7, -c7 + (c8 + 7), -c7 + (c9 + 2) - 1); 
          S4(c1, -c1 + c2, -c1 + c3, c4, -c4 + c5, -c4 + c6, c7, -c7 + (c8 + 7), -c7 + (c9 + 2) - 1); 
          S1(c1, -c1 + c2, -c1 + c3, c4, -c4 + c5, -c4 + c6, c7, -c7 + (c8 + 7), -c7 + (c9 + 3)); 
          S2(c1, -c1 + c2, -c1 + c3, c4, -c4 + c5, -c4 + c6, c7, -c7 + (c8 + 7), -c7 + (c9 + 3)); 
          S3(c1, -c1 + c2, -c1 + c3, c4, -c4 + c5, -c4 + c6, c7, -c7 + (c8 + 7), -c7 + (c9 + 3) - 1); 
          S4(c1, -c1 + c2, -c1 + c3, c4, -c4 + c5, -c4 + c6, c7, -c7 + (c8 + 7), -c7 + (c9 + 3) - 1); 
          S1(c1, -c1 + c2, -c1 + c3, c4, -c4 + c5, -c4 + c6, c7, -c7 + (c8 + 7), -c7 + (c9 + 4)); 
          S2(c1, -c1 + c2, -c1 + c3, c4, -c4 + c5, -c4 + c6, c7, -c7 + (c8 + 7), -c7 + (c9 + 4)); 
          S3(c1, -c1 + c2, -c1 + c3, c4, -c4 + c5, -c4 + c6, c7, -c7 + (c8 + 7), -c7 + (c9 + 4) - 1); 
          S4(c1, -c1 + c2, -c1 + c3, c4, -c4 + c5, -c4 + c6, c7, -c7 + (c8 + 7), -c7 + (c9 + 4) - 1); 
          S1(c1, -c1 + c2, -c1 + c3, c4, -c4 + c5, -c4 + c6, c7, -c7 + (c8 + 7), -c7 + (c9 + 5)); 
          S2(c1, -c1 + c2, -c1 + c3, c4, -c4 + c5, -c4 + c6, c7, -c7 + (c8 + 7), -c7 + (c9 + 5)); 
          S3(c1, -c1 + c2, -c1 + c3, c4, -c4 + c5, -c4 + c6, c7, -c7 + (c8 + 7), -c7 + (c9 + 5) - 1); 
          S4(c1, -c1 + c2, -c1 + c3, c4, -c4 + c5, -c4 + c6, c7, -c7 + (c8 + 7), -c7 + (c9 + 5) - 1); 
          S1(c1, -c1 + c2, -c1 + c3, c4, -c4 + c5, -c4 + c6, c7, -c7 + (c8 + 7), -c7 + (c9 + 6)); 
          S2(c1, -c1 + c2, -c1 + c3, c4, -c4 + c5, -c4 + c6, c7, -c7 + (c8 + 7), -c7 + (c9 + 6)); 
          S3(c1, -c1 + c2, -c1 + c3, c4, -c4 + c5, -c4 + c6, c7, -c7 + (c8 + 7), -c7 + (c9 + 6) - 1); 
          S4(c1, -c1 + c2, -c1 + c3, c4, -c4 + c5, -c4 + c6, c7, -c7 + (c8 + 7), -c7 + (c9 + 6) - 1); 
          S1(c1, -c1 + c2, -c1 + c3, c4, -c4 + c5, -c4 + c6, c7, -c7 + (c8 + 7), -c7 + (c9 + 7)); 
          S2(c1, -c1 + c2, -c1 + c3, c4, -c4 + c5, -c4 + c6, c7, -c7 + (c8 + 7), -c7 + (c9 + 7)); 
          S3(c1, -c1 + c2, -c1 + c3, c4, -c4 + c5, -c4 + c6, c7, -c7 + (c8 + 7), -c7 + (c9 + 7) - 1); 
          S4(c1, -c1 + c2, -c1 + c3, c4, -c4 + c5, -c4 + c6, c7, -c7 + (c8 + 7), -c7 + (c9 + 7) - 1); 
        } 

      for (; c9 <= 32 * c6 + 31; c9 = c9 + 1)         { 
          S1(c1, -c1 + c2, -c1 + c3, c4, -c4 + c5, -c4 + c6, c7, -c7 + c8, -c7 + c9); 
          S2(c1, -c1 + c2, -c1 + c3, c4, -c4 + c5, -c4 + c6, c7, -c7 + c8, -c7 + c9); 
          S3(c1, -c1 + c2, -c1 + c3, c4, -c4 + c5, -c4 + c6, c7, -c7 + c8, -c7 + c9 - 1); 
          S4(c1, -c1 + c2, -c1 + c3, c4, -c4 + c5, -c4 + c6, c7, -c7 + c8, -c7 + c9 - 1); 
          S1(c1, -c1 + c2, -c1 + c3, c4, -c4 + c5, -c4 + c6, c7, -c7 + (c8 + 1), -c7 + c9); 
          S2(c1, -c1 + c2, -c1 + c3, c4, -c4 + c5, -c4 + c6, c7, -c7 + (c8 + 1), -c7 + c9); 
          S3(c1, -c1 + c2, -c1 + c3, c4, -c4 + c5, -c4 + c6, c7, -c7 + (c8 + 1), -c7 + c9 - 1); 
          S4(c1, -c1 + c2, -c1 + c3, c4, -c4 + c5, -c4 + c6, c7, -c7 + (c8 + 1), -c7 + c9 - 1); 
          S1(c1, -c1 + c2, -c1 + c3, c4, -c4 + c5, -c4 + c6, c7, -c7 + (c8 + 2), -c7 + c9); 
          S2(c1, -c1 + c2, -c1 + c3, c4, -c4 + c5, -c4 + c6, c7, -c7 + (c8 + 2), -c7 + c9); 
          S3(c1, -c1 + c2, -c1 + c3, c4, -c4 + c5, -c4 + c6, c7, -c7 + (c8 + 2), -c7 + c9 - 1); 
          S4(c1, -c1 + c2, -c1 + c3, c4, -c4 + c5, -c4 + c6, c7, -c7 + (c8 + 2), -c7 + c9 - 1); 
          S1(c1, -c1 + c2, -c1 + c3, c4, -c4 + c5, -c4 + c6, c7, -c7 + (c8 + 3), -c7 + c9); 
          S2(c1, -c1 + c2, -c1 + c3, c4, -c4 + c5, -c4 + c6, c7, -c7 + (c8 + 3), -c7 + c9); 
          S3(c1, -c1 + c2, -c1 + c3, c4, -c4 + c5, -c4 + c6, c7, -c7 + (c8 + 3), -c7 + c9 - 1); 
          S4(c1, -c1 + c2, -c1 + c3, c4, -c4 + c5, -c4 + c6, c7, -c7 + (c8 + 3), -c7 + c9 - 1); 
          S1(c1, -c1 + c2, -c1 + c3, c4, -c4 + c5, -c4 + c6, c7, -c7 + (c8 + 4), -c7 + c9); 
          S2(c1, -c1 + c2, -c1 + c3, c4, -c4 + c5, -c4 + c6, c7, -c7 + (c8 + 4), -c7 + c9); 
          S3(c1, -c1 + c2, -c1 + c3, c4, -c4 + c5, -c4 + c6, c7, -c7 + (c8 + 4), -c7 + c9 - 1); 
          S4(c1, -c1 + c2, -c1 + c3, c4, -c4 + c5, -c4 + c6, c7, -c7 + (c8 + 4), -c7 + c9 - 1); 
          S1(c1, -c1 + c2, -c1 + c3, c4, -c4 + c5, -c4 + c6, c7, -c7 + (c8 + 5), -c7 + c9); 
          S2(c1, -c1 + c2, -c1 + c3, c4, -c4 + c5, -c4 + c6, c7, -c7 + (c8 + 5), -c7 + c9); 
          S3(c1, -c1 + c2, -c1 + c3, c4, -c4 + c5, -c4 + c6, c7, -c7 + (c8 + 5), -c7 + c9 - 1); 
          S4(c1, -c1 + c2, -c1 + c3, c4, -c4 + c5, -c4 + c6, c7, -c7 + (c8 + 5), -c7 + c9 - 1); 
          S1(c1, -c1 + c2, -c1 + c3, c4, -c4 + c5, -c4 + c6, c7, -c7 + (c8 + 6), -c7 + c9); 
          S2(c1, -c1 + c2, -c1 + c3, c4, -c4 + c5, -c4 + c6, c7, -c7 + (c8 + 6), -c7 + c9); 
          S3(c1, -c1 + c2, -c1 + c3, c4, -c4 + c5, -c4 + c6, c7, -c7 + (c8 + 6), -c7 + c9 - 1); 
          S4(c1, -c1 + c2, -c1 + c3, c4, -c4 + c5, -c4 + c6, c7, -c7 + (c8 + 6), -c7 + c9 - 1); 
          S1(c1, -c1 + c2, -c1 + c3, c4, -c4 + c5, -c4 + c6, c7, -c7 + (c8 + 7), -c7 + c9); 
          S2(c1, -c1 + c2, -c1 + c3, c4, -c4 + c5, -c4 + c6, c7, -c7 + (c8 + 7), -c7 + c9); 
          S3(c1, -c1 + c2, -c1 + c3, c4, -c4 + c5, -c4 + c6, c7, -c7 + (c8 + 7), -c7 + c9 - 1); 
          S4(c1, -c1 + c2, -c1 + c3, c4, -c4 + c5, -c4 + c6, c7, -c7 + (c8 + 7), -c7 + c9 - 1); 
        } 
    } 

  for (; c8 <= 32 * c5 + 31; c8 = c8 + 1)     { 

      for (c9 = max(32 * c6, c7 + 1); c9 <= 32 * c6 + 31 - 7; c9 = c9 + 8)         { 
          S1(c1, -c1 + c2, -c1 + c3, c4, -c4 + c5, -c4 + c6, c7, -c7 + c8, -c7 + c9); 
          S2(c1, -c1 + c2, -c1 + c3, c4, -c4 + c5, -c4 + c6, c7, -c7 + c8, -c7 + c9); 
          S3(c1, -c1 + c2, -c1 + c3, c4, -c4 + c5, -c4 + c6, c7, -c7 + c8, -c7 + c9 - 1); 
          S4(c1, -c1 + c2, -c1 + c3, c4, -c4 + c5, -c4 + c6, c7, -c7 + c8, -c7 + c9 - 1); 
          S1(c1, -c1 + c2, -c1 + c3, c4, -c4 + c5, -c4 + c6, c7, -c7 + c8, -c7 + (c9 + 1)); 
          S2(c1, -c1 + c2, -c1 + c3, c4, -c4 + c5, -c4 + c6, c7, -c7 + c8, -c7 + (c9 + 1)); 
          S3(c1, -c1 + c2, -c1 + c3, c4, -c4 + c5, -c4 + c6, c7, -c7 + c8, -c7 + (c9 + 1) - 1); 
          S4(c1, -c1 + c2, -c1 + c3, c4, -c4 + c5, -c4 + c6, c7, -c7 + c8, -c7 + (c9 + 1) - 1); 
          S1(c1, -c1 + c2, -c1 + c3, c4, -c4 + c5, -c4 + c6, c7, -c7 + c8, -c7 + (c9 + 2)); 
          S2(c1, -c1 + c2, -c1 + c3, c4, -c4 + c5, -c4 + c6, c7, -c7 + c8, -c7 + (c9 + 2)); 
          S3(c1, -c1 + c2, -c1 + c3, c4, -c4 + c5, -c4 + c6, c7, -c7 + c8, -c7 + (c9 + 2) - 1); 
          S4(c1, -c1 + c2, -c1 + c3, c4, -c4 + c5, -c4 + c6, c7, -c7 + c8, -c7 + (c9 + 2) - 1); 
          S1(c1, -c1 + c2, -c1 + c3, c4, -c4 + c5, -c4 + c6, c7, -c7 + c8, -c7 + (c9 + 3)); 
          S2(c1, -c1 + c2, -c1 + c3, c4, -c4 + c5, -c4 + c6, c7, -c7 + c8, -c7 + (c9 + 3)); 
          S3(c1, -c1 + c2, -c1 + c3, c4, -c4 + c5, -c4 + c6, c7, -c7 + c8, -c7 + (c9 + 3) - 1); 
          S4(c1, -c1 + c2, -c1 + c3, c4, -c4 + c5, -c4 + c6, c7, -c7 + c8, -c7 + (c9 + 3) - 1); 
          S1(c1, -c1 + c2, -c1 + c3, c4, -c4 + c5, -c4 + c6, c7, -c7 + c8, -c7 + (c9 + 4)); 
          S2(c1, -c1 + c2, -c1 + c3, c4, -c4 + c5, -c4 + c6, c7, -c7 + c8, -c7 + (c9 + 4)); 
          S3(c1, -c1 + c2, -c1 + c3, c4, -c4 + c5, -c4 + c6, c7, -c7 + c8, -c7 + (c9 + 4) - 1); 
          S4(c1, -c1 + c2, -c1 + c3, c4, -c4 + c5, -c4 + c6, c7, -c7 + c8, -c7 + (c9 + 4) - 1); 
          S1(c1, -c1 + c2, -c1 + c3, c4, -c4 + c5, -c4 + c6, c7, -c7 + c8, -c7 + (c9 + 5)); 
          S2(c1, -c1 + c2, -c1 + c3, c4, -c4 + c5, -c4 + c6, c7, -c7 + c8, -c7 + (c9 + 5)); 
          S3(c1, -c1 + c2, -c1 + c3, c4, -c4 + c5, -c4 + c6, c7, -c7 + c8, -c7 + (c9 + 5) - 1); 
          S4(c1, -c1 + c2, -c1 + c3, c4, -c4 + c5, -c4 + c6, c7, -c7 + c8, -c7 + (c9 + 5) - 1); 
          S1(c1, -c1 + c2, -c1 + c3, c4, -c4 + c5, -c4 + c6, c7, -c7 + c8, -c7 + (c9 + 6)); 
          S2(c1, -c1 + c2, -c1 + c3, c4, -c4 + c5, -c4 + c6, c7, -c7 + c8, -c7 + (c9 + 6)); 
          S3(c1, -c1 + c2, -c1 + c3, c4, -c4 + c5, -c4 + c6, c7, -c7 + c8, -c7 + (c9 + 6) - 1); 
          S4(c1, -c1 + c2, -c1 + c3, c4, -c4 + c5, -c4 + c6, c7, -c7 + c8, -c7 + (c9 + 6) - 1); 
          S1(c1, -c1 + c2, -c1 + c3, c4, -c4 + c5, -c4 + c6, c7, -c7 + c8, -c7 + (c9 + 7)); 
          S2(c1, -c1 + c2, -c1 + c3, c4, -c4 + c5, -c4 + c6, c7, -c7 + c8, -c7 + (c9 + 7)); 
          S3(c1, -c1 + c2, -c1 + c3, c4, -c4 + c5, -c4 + c6, c7, -c7 + c8, -c7 + (c9 + 7) - 1); 
          S4(c1, -c1 + c2, -c1 + c3, c4, -c4 + c5, -c4 + c6, c7, -c7 + c8, -c7 + (c9 + 7) - 1); 
        } 

      for (; c9 <= 32 * c6 + 31; c9 = c9 + 1)         { 
          S1(c1, -c1 + c2, -c1 + c3, c4, -c4 + c5, -c4 + c6, c7, -c7 + c8, -c7 + c9); 
          S2(c1, -c1 + c2, -c1 + c3, c4, -c4 + c5, -c4 + c6, c7, -c7 + c8, -c7 + c9); 
          S3(c1, -c1 + c2, -c1 + c3, c4, -c4 + c5, -c4 + c6, c7, -c7 + c8, -c7 + c9 - 1); 
          S4(c1, -c1 + c2, -c1 + c3, c4, -c4 + c5, -c4 + c6, c7, -c7 + c8, -c7 + c9 - 1); 
        } 
    } 
} 
/*@ end @*/
            }
            if ((c4 >= c5) && (c5 <= min(floord(32*c6-1,32),floord(T-32,32)))) {
              for (c9=max(32*c6,32*c5+32);c9<=min(32*c6+31,32*c5+N+30);c9++) {
                S1(c1,-c1+c2,-c1+c3,c4,-c4+c5,-c4+c6,32*c5+31,0,-32*c5+c9-31) ;
                S2(c1,-c1+c2,-c1+c3,c4,-c4+c5,-c4+c6,32*c5+31,0,-32*c5+c9-31) ;
              }
            }
          }
        }
      }
    }
  }
}
/* End of CLooG code */

    annot_t_end = rtclock();
    annot_t_total += annot_t_end - annot_t_start;
  }
  
  annot_t_total = annot_t_total / REPS;
  printf("%f\n", annot_t_total);
  
  return ((int) B[0][0]); 

}
