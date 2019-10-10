#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*

Crie um programa em C que permita ao cliente
escolher seu Hamburger, batata (pequena,
média ou grande) e refrigerante ou suco. A
batata e a bebida são opcionais.


Ele deverá, também, ter a opção de montar um
combo com Hamburger, batata grande e
refrigerante.

Caso ele queira trocar o refrigerante por suco
(no combo), deverá ser acrescido mais R$ 1,00
na conta.
Ao final, o programa deverá informar o valor
total a pagar

hamburger
opcionais
batata
refrigerante ou suco 


*/

int main(){
    float hamburger, batata , bebida, combo,valor_final;
    int escolha,escolha2,beb,continua=2;
    char sCombo[40],sHam[30],sBat[10],sBeb[10];
    
    while(continua!=1){
        printf("Hamburgueria C\n\nDeseja escolher um combo ou escolher o lanche?: \n");
        printf("\n1. Combo\n2. Escolher lanche\n3. Sair do programa\n");
        scanf("%i",&escolha);
        
        //Combo
        if(escolha == 1){
            a:
            escolha = 0;
            printf("\nEscolha um combo abaixo: \n");
            printf("1. Hamburger Vegetariano + Batata grande + Refrigerante\n2. Hamburger Frango + Batata grande + Refrigerante\n3. Hamburger Picanha + Batata grande + Refrigerante\n4. Hamburger Salmao + Batata grande + Refrigerante\n");
            scanf("\n%i",&escolha);
        
            switch (escolha){
                case 1: 
                combo = 39.00;
                printf("\n + %.2f",combo);
                strcpy(sCombo,"Hamburger Vegetariano + Batata grande +");
                break;
                
                case 2: 
                combo = 45.00;
                strcpy(sCombo, "Hamburger Frango + Batata grande +");
                break;
                
                case 3: 
                combo = 50.00;
                printf("\n + %.2f",combo);
                strcpy(sCombo,"Hamburger Picanha + Batata grande +");
                
                break;

                case 4: 
                combo = 56.00;
                printf("+ %.2f",combo);
                strcpy(sCombo,"Hamburger Salmao + Batata grande +") ;
                break;


                default: 
                printf("\n\nInsira um valor valido\n\n");
                goto a;
                break;
            }
            b:
            printf("\nDeseja trocar o refrigerante pelo suco por mais 1 real?");
            printf("\n1. Sim\n2. Nao\n");
            scanf("%i",&beb);
            
            if(beb == 1){
                combo++;
                strcat(sCombo," Suco");
            }else if (beb==2){
                strcat(sCombo," Refrigerante");
            }else{
            goto b;
            }
            printf("\nResumo do pedido: \n%s \n\nValor total ficou em: %.2f\n", sCombo, combo);
            goto f;
        //==================================================================    
        }else if (escolha == 2){
            //montar combo
            //Escolhendo hamburger
            c:
            printf("\nEscolha um hamburger:\n");
            printf("\n1. Hamburguer Vegetariano\n2. Hamburguer Frango\n3. Hamburguer Picanha\n4. Hamburger Salmao\n");
            scanf("%i",&escolha2);

            switch (escolha2){
                case 1:
                    hamburger = 32.00;
                    printf("+ %.2f", hamburger);
                    strcpy(sHam,"Hamburguer Vegetariano");
                    break;
                case 2:
                    hamburger = 38.00;
                    printf("+ %.2f", hamburger);
                    strcpy(sHam,"Hamburguer Frango");
                    break;
                case 3:
                    hamburger = 43.00;
                    printf("+ %.2f", hamburger);
                    strcpy(sHam,"Hamburguer Picanha");
                    break;
                case 4:
                    hamburger = 49.00;
                    printf("+ %.2f", hamburger);
                    strcpy(sHam,"Hamburger Salmao");
                    break;  
                default: 
                    printf("\nEscolha um valor correto!!!\n");
                goto c;
                break;
            }
            escolha2 = 0;
            //BATATAS
            d:
            printf("\nDeseja adicionar batata?\n");
            printf("\n1. Sim\n2. Nao\n");
            scanf("%i",&escolha2);

            switch (escolha2){
            case 1:
                escolha2 = 0;
                printf("\nEscolha qual batata:\n");
                printf("\n1. Batata pequena\n2. Batata media \n3. Batata grande\n4. Nao adicionar batata\n");
                scanf("%i",&escolha2);
                    switch(escolha2){
                        case 1:
                            batata = 4.80;
                            printf("+ %.2f",batata);
                            strcpy(sBat,"Batata pequena");
                            break;  
                        case 2:
                            batata = 6.30;
                            strcpy(sBat,"Batata media");
                            printf("+ %.2f",batata);
                            break;
                        case 3:
                            batata = 8.00;
                            strcpy(sBat,"Batata grande");
                            printf("+ %.2f",batata);
                            break;
                        case 4: 
                            batata = 0;
                            strcpy(sBat,"Sem batata");
                            printf("+ %.2f",batata);
                            break;
                        default: 
                            printf("Insira um valor correto\n");
                            goto d;
                            break;
                    }
                break;
                case 2: 
                    batata = 0;
                    printf("\nBatatas nao foram adicionadas ao pedido\n\n");
                    strcpy(sBat,"Sem batata");
                default:
                break;
            }
            //BEBIDAS
            e:
            printf("\nDeseja adicionar bebidas?");
            printf("\n1. Refrigerante\n2. Suco\n3. Nao\n");
            escolha2 = 0;
            scanf("%i",&escolha2);
            switch(escolha2){
                case 1:
                    bebida = 7.00;
                    printf("+ %.2f",bebida);
                    strcpy(sBeb,"Refrigerante");
                    break;
                case 2:
                    bebida = 8.00;
                    printf("+ %.2f",bebida);
                    strcpy(sBeb,"Suco");
                    break;
                case 3:
                    bebida = 0;
                    printf("\nSem bebidas\n");
                    strcpy(sBeb,"Sem Bebidas");
                    break;
                default:
                    printf("\nInsira um numero correto!\n");
                    goto e;
                    break;
            }
            valor_final = hamburger + batata + bebida;
            printf("\nO pedido ficou:\n%s ....... %.2f\n%s ....... %.2f\n%s.......... %.2f \n\nO valor total do pedido ficou: %.2f\n\n\n",sHam,hamburger,sBat,batata,sBeb,bebida,valor_final);
        }else{
            break;
        }
        f:
        system("pause");
        g:
        printf("\n\n\nDeseja fazer um novo pedido ou encerrar?\n\n1. Encerrar\n2. Novo Pedido\n\n");
        scanf("%i",&continua);
        if(continua!=1 && continua!=2){
            goto g;
        }
    }
    printf("\nSaindo do programa!!\n");
    printf("Encerrando....");
    system("pause");
    return 0; 
}