#include<stdio.h>
#include<stdint.h>
#define H(v)m[STK+s--]=v
#define L m[STK+ ++s]
enum{STK=0x200,BRKV=0xF800,NMIV=0xF802,RESV=0xFFFC,IRQV=0xFFFE};
typedef uint8_t B;typedef uint16_t W;B m[1<<16],a,x,y,s,P;W pc;W G(W e,int k){return m[e]|m[e+1&k|e&~k]<<8;}
B N(B r){P=P&125|r&128|!r*2;return r;}void I(W v,int b){v=G(v,65535);H(pc>>8);H(pc);if(b)H(P=P&239|b),P|=4;pc=v;}
void init(){s=253;pc=a=x=y=P=0;}void nmi(){I(NMIV,32);}void res(){I(RESV,32);}void irq(){if(~P&4)I(IRQV,32);}
void step(){B o=m[pc++],A=o>>5,k=o>>2&7,r,*p,*q=o&2||o>223?&x:o&1?&a:&y,v,c=P&1,l;W e;k=(o|k)&1?k:k&2?k+6:2;
r=k-3?k==6||(o&195)==130?y:x:0;p=k>8?&s:o-202?&a:&x;if(k<8){e=k-2?m[pc++]:pc++;if(200>>k&1)e+=m[pc++]*256+r;
else if(k==5)e=e+r&255;else if(k%4<1)e=k?G(e,255)+y:G(e+x&255,255);p=m+e;}v=*p;switch(o){
case 0:e=BRKV;case 32:I(e,!o*48);break;case 40:case 64:P=L;if(A>1)case 96:pc=L,pc+=L*256+A%2;break;
case 8:P|=48;case 72:H(A?a:P);break;case 136:case 200:case 232:*q=N(*q-1+A/5*2);break;
case 104:case 152:case 138:a=N(o-104?*q:L);case 234:break;case 108:e=G(e,255);case 76:pc=e;break;
case 36:case 44:P=P&61|v&192|!(v&a)*2;break;default:if((l=o&31)==16)pc+=(P>>"7601"[A/2]%8^A)&1?0:(v^128)-128;
else if(l==24)l="\1\4@\b"[A/2],P=A&1&&A-5?P|l:P&~l;else if((o&99)==97){r=A>6?~v:v;e=a+r+c;
P=P&190|e>>8|((a^e)&(r^e)&128)/2;if(P&8){if(A>6)l=a%16-v%16-!c,k=a/16-v/16-l/128,l-=l/128*6,k-=k/128*6;
else l=a%16+v%16+c,l+=(l>9)*6,k=a/16+v/16+(l>15),k+=(k>9)*6,P=P&190|k>15;e=k*16|l%16;}a=N(e);}
else if(A>5)if(o&2)*p=N(v+A*2-13);else P=P&254|*q>=v,N(*q-v);else if(A>4)*q=N(v);else if(A>3)*p=*q;
else if(o&1)a=N(A?A>1?a^v:a&v:a|v);else l=A&c,P=P&254|(A<2?v>>7:v&1),*p=N(A<2?v*2|l:v/2|l<<7);}}
int main(){FILE*f=fopen("test1.bin","rb");if(!f)return 1;fread(m+0x4000,1,0xC000,f);
init();res();do step();while(pc!=0x45C0);puts(m[0x210]==255?"passed":"failed");}
