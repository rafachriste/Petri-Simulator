/* ************************************************************************ *
 *    Simulador de Rede de Petri, V0.1                                      *
 *    Programa que um simulador geral da rede de petri                      *
 *                                                                          *
 *    Copyright (C) 2017 by Rafaella Christe Correa                         *
 *                                                                          *
 *    This program is free software; you can redistribute it and/or modify  *
 *    it under the terms of the GNU General Public License as published by  *
 *    the Free Software Foundation; either version 2 of the License, or     *
 *    (at your option) any later version.                                   *
 *                                                                          *
 *    This program is distributed in the hope that it will be useful,       *
 *    but WITHOUT ANY WARRANTY; without even the implied warranty of        *
 *    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the         *
 *    GNU General Public License for more details.                          *
 *                                                                          *
 *    You should have received a copy of the GNU General Public License     *
 *    along with this program; if not, write to the                         *
 *    Free Software Foundation, Inc.,                                       *
 *    59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.             *
 *                                                                          *
 *    To contact the author, please write to:                               *
 *    Nome Completo <rfllchriste352@gmail.com>                              *
 *    Webpage: http://www.upe.br                                            *
 *    Phone: +55 (81) 9799-2001                                             *
 * ************************************************************************ *
 * 
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 100


typedef struct
{
    char tokens;
    char lugares[MAX];
    char transicoes;
    char tip_arco;
    char aconsumidores;
    char aprodutores;
    char consumidor[MAX][MAX];
    char produtor[MAX][MAX];
}filedata;

char getnext(void);
filedata getdata(void);
void print(filedata data);

int main(void)
{
    petri(getdata()); 
    print(getdata());
    return EXIT_SUCCESS;
}



filedata getdata(void)
{
    filedata data;
    int i=1;
    
    data.tokens = getnext();
    //printf("tokens: %d\n", data.tokens);

    while(1)
    {
        switch(i)
        {
            case 1:
                //printf("case 1\n");
                for(int j = 0; j < data.tokens; j++)
                {
                    data.lugares[j] = getnext();
                    //printf("lugares[j]: %d\n", data.lugares[j]);
                }
                break;
            case 2: 
                //printf("case 2\n");
                data.transicoes = getnext();
                //printf("%d\n", data.transicoes);
                break;
            case 3:
                //printf("case 3\n");
                data.tip_arco = getnext();
                //printf("%d\n", data.tip_arco);
                break;
            case 4:
                //printf("case 4\n");
                data.aconsumidores = getnext();
                //printf("%d\n", data.aconsumidores);
                break;
            case 5:
                //printf("case 5\n");
                for(int k = 0; k < data.aconsumidores; k++)
                    for(int l = 0; l < data.tokens; l++)
                    { 
                        data.consumidor[k][l] = getnext();
                        //printf("***consumidores[%d,%d]: %d\n",k, l, data.consumidor[k][l]);
                    }
                break;
            case 6:
                //printf("case 6\n");
                data.aprodutores = getnext();
                //printf("%d\n", data.aprodutores);
                break;
            case 7:
                //printf("case 7\n");
                for(int m = 0; m < data.tokens; m++) 
                    for(int n = 0; n < data.aprodutores; n++)
                    { 
                        data.produtor[m][n] = getnext();
                        //printf("%d\n", data.produtor[m][n]);
                    }
                break;
        }
        i++;
        //printf("i: %d\n", i);
        if(i==8)
            break;
    }
    return data;
}

char getnext(void)
{
    char valor;

    while(valor != EOF)
    {
        scanf("%c", &valor);
        //printf("valor: %d\n", valor);
        if(valor >=48 && valor <= 57)
            return valor - 48;
    }
    return 0;
}
void print(filedata data)
{
    printf("lugares:%d\n", data.tokens);

    for(int j = 0; j < data.tokens; j++)
        printf("tokens:%d\n", data.lugares[j]);
    
    printf("transicoes: %d\ntipos de arcos: %d\narcos consumidores: %d{\n", data.transicoes, data.tip_arco, data.aconsumidores);

    for(int o = 0; o < data.aconsumidores; o++)
    {
        for(int p = 0; p < data.tokens; p++)
            printf("%d",data.consumidor[o][p]); 
        printf("\n");
    }

    printf("arcos produtores: %d{\n", data.aprodutores);

    for(int q = 0; q < data.tokens; q++)
    {
        for(int r = 0; r < data.aprodutores; r++)
            printf("%d ", data.produtor[q][r]); 
        printf("\n");
    }
    printf("}\n");
}


petri(filedata data)
{
    

