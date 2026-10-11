#include<stdio.h>
#include<stdlib.h>
#define g getchar()&255
char*O="ADCANDASLBCCBCSBEQBITBMIBNEBPLBRABRKBVCBVSCLCCLDCLICLVCMPCPXCPYDECDEXDEYEORINCINXINYJMPJSRLDALDXLDYLSRNOPORAPHAPHPPHXPHYPLAPLPPLXPLYROLRORRTIRTSSBCSECSEDSEISTASTPSTXSTYSTZTAXTAYTRBTSBTSXTXATXSTYAWAI???",
*N=".Fee_F%eHF%e_F%e,FFe^F%e1F<e^F%e@$ee)$OeL$Oe)$Oe*$$e)$OeT$8e)$OeQ;eee;DeG;De?;De/;;ee;De3;Jee;DeR#ee[#PeK#Pe?#Pe0##e[#PeV#Ne?#Pe-WeeZWYe:)aeZWYe&WWeZWYecWbe[W[eCABeCABe]A\\eCABe'AAeCABe4A`eCABe75ee758e>59d758e+55ee58e25IXe58e6See6S<e=SEe6S<e(SSeeS<eUSMeeS<e",
*M="araaoooaanbayyyamstaoppaa{bayzzayraaoooaanbayyyamstapppaa{bazzzaaraaoooaanbayyyamstaoppaa{aayzzaaraaoooaanba~yyamstapppaa{aa|zzamraaoooaanaayyyamstappqaa{aayzzanrnaoooaanaayyyamstappqaa{aazz{anraaoooaanaayyyamstaoppaa{aayzzanraaoooaanaayyyamstaoppaa{aayzza",
*F[]={"","A","%04X","#$%0*X","$%0*X","$%0*X,X","$%0*X,Y","($%0*X,X)","($%0*X),Y","($%0*X)"};
int main(int c,char**v){char*s=v[1];int b=c-2||*s-48?10:s[1]-120?s[1]-98?s[1]-111?10:8:2:16;
unsigned short a=c-2?0:strtol(s+(b-10?2:0),0,b);printf("%18s* = $%04X\n","",a);while(!feof(stdin)){
int o=g,d=M[o]-97,f=d%10,n=d/10,p=n?g:0,q=n>1?g:0;
printf("%04X   %02X %2.*X %2.*X   %.3s ",a,o,n?2:0,p,n>1?2:0,q,O+(N[o]-35)*3);
printf(F[f],f-2?n*2:a+2+(p^128)-128&65535,q*256+p);puts("");a+=n+1;}}
