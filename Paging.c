#include <stdio.h> 
#include <math.h> 
int bit_calc(int); 
int bin_conv(int); 
int dec_conv(int, int);
void disp_bin_res(int, int); 
int bin_result[40], 
input[32]; 
int main()
{
int p_s, pg_s, ph_s, f_n, p_n; 
int pg_tab[5][3]; 
int i; 
int p_bits, l_bits, p_b, l_b; 
int page_bits; 
printf("\nPlease enter the Process Size in KB: "); 
scanf("%d", &p_s); 
printf("\nPlease enter Page Size in bytes: "); 
scanf("%d", &pg_s); 
page_bits = bit_calc(pg_s * 1024); 
printf("\nPlease enter Physical Memory Size in MB: "); 
scanf("%d", &ph_s); 
for (i = 0; i < 5; i++)
{
printf("\nPlease enter data for Page Table entry %d\n", (i + 1)); 
printf("Page No: "); 
scanf("%d", &pg_tab[i][0]); 
printf("Frame No: "); scanf("%d", &pg_tab[i][1]);
printf("Valid/Invalid Bit: "); scanf("%d", &pg_tab[i][2]);
} f_n = ph_s / pg_s; 
printf("\nThe Total number of Frames in the Physical Memory are: %d\n", f_n); 
p_n = p_s / pg_s; printf("The Total number of entries in the Page Table are: %d\n", p_n); p_bits = bit_calc(ph_s); printf("\nThe number of bits in the Physical Address are: %d\n", (p_bits +
page_bits));
printf("The distribution is %d:%d\n",p_bits,page_bits); 
p_b=p_bits+page_bits; l_bits = bit_calc(p_s); 
printf("\nThe number of bits in the Logical Address are: %d\n", (l_bits +
page_bits));
printf("The distribution is %d:%d\n",l_bits,page_bits); 
l_b=l_bits+page_bits; 
while(1)
{
printf("\nPlease enter the logical address:\n"); 
for (i = 0; i < l_b; i++)
{ int temp; 
scanf("%d", &temp); 
if (temp == 2)
{
i = -1; 
break; }
input[i] = temp;
}
if (i == -1) break;
printf("\n"); int page_no = dec_conv(0, l_bits); int pos = -1; for (i = 0; i < 5; i++)
{ if (page_no == pg_tab[i][0]) pos = i;
}
if (pos != -1)
{ if (pg_tab[pos][2] == 1)
{
printf("The generated Physical Address is: "); int p_addr = pg_tab[pos][1]; p_addr = p_addr * pg_s * 1024; p_addr += dec_conv(l_bits, l_b); int start = bin_conv(p_addr); disp_bin_res(start, p_b); printf("\n"); printf("Page hit!\n");
}
else
printf("Page Fault!\n");
}
else
printf("Page not found!\n");
i = 0;
}
return 0;
}
int dec_conv(int start, int stop)
{
int i; int res = 0; int n = stop - start; int j = 0; for (i = start; i < stop; i++)
{
double temp = pow(2, (n - j - 1)); res = res + (input[i] * (int)temp); j++;
}
return res; }
int bin_conv(int n)
{
int i = 0; while ((n / 2) >= 2)
{
bin_result[i] = n % 2; n /= 2; i++; }
i++; bin_result[i] = 1; return i;
}
void disp_bin_res(int n, int min_l)
{
int i; if (min_l > (n + 1))
{
for (i = 0; i < (min_l - n - 1); i++)
{
printf("%d", 0);
}
}
for (i = n; i >= 0; i--)
{
printf("%d", bin_result[i]);
}
}
int bit_calc(int p_s)
{
int bits = 1; while ((p_s / 2) >= 2)
{ bits++; p_s = p_s / 2;
}
return bits;
}