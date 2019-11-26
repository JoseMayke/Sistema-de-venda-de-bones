#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define x 100

typedef struct{
    int codigo;
    char nome[20], endereco[20];
    float telefone, cpf;
}clientes;

typedef struct{
    char descricao[200];
    float pvenda;
    int quantidade, codigo;
}produtos;

typedef struct vendas{
    double total;
};

    clientes client[x];
    produtos pro[x];
    int cod=0, codProduto=0, quantidade=x, codcliente=0;
    float valor, total=0, saldo=0;



void caixa(){
    system("cls");
    char conv[30];
    int opcao=1, quant;
    system("cls");
    char cond;
    printf("--------------------------------------------------------------------------------\n");
    printf("-------------------------------------CAIXA--------------------------------------\n");
    printf("--------------------------------------------------------------------------------\n");
    printf("\n1 - VENDER");
    printf("\n2 - VALOR ATUAL DO CAIXA");
    printf("\n3 - BONES");
    printf("\n4 - CLIENTES");
    printf("\n5 - MENU PRINCIPAL\n");
    gets(conv);
    opcao=atoi(conv);
    switch(opcao){
        case 1:{
            int i=0;
            do{
                system("cls");
                printf("INFORME O CODIGO DO PRODUTO:\n");
                scanf("%d", &cod);
                if(ProdutoExiste(cod)!=1){
                    printf("PRODUTO NAO EXISTENTE!");
                    getch();
                    caixa();
                }else{
                    printf("NOME DO BONE:\t\t%s\nVALOR DE VENDA:\t\t%.2f\nESTOQUE:\t\t%d\n", pro[codProduto].descricao, pro[codProduto].pvenda, pro[codProduto].quantidade);
                    printf("INFORME A QUATIDADE DE BONES DA %s A SER VENDIDO:\n", pro[codProduto].descricao);
                    scanf("%d", &quant);
                    if(quant<pro[codProduto].quantidade){
                        valor=quant*pro[codProduto].pvenda;
                        total=total+valor;
                        saldo=saldo+total;
                        pro[codProduto].quantidade=pro[codProduto].quantidade-quant;
                    }else{
                        printf("NAO AH QUANTIDADE SUFICIENTE NO ESTOQUE!\n");
                        getch();
                        caixa();
                    }
                }
                printf("\nSUB TOTAL:\n%.2f\n", total);
                printf("DESEJA FINALIZAR A VENDA(*s* PARA SIM)?\n");
                scanf("%s", &cond);
                }while(cond !='s');
                    printf("VENDA REALIZADA COM SUCESSO!\n");
                    printf("TOTAL A PAGAR:%.2f\n", total);
                    total=0;
                    getch();
                    caixa();
                    break;
        }
        case 2:{
            printf("O VALOR ATUAL DO CAIXA Eh %.2f\n", saldo);
            getch();
            caixa();
            break;
        }
        case 3:{
            bones();
            break;
        }
        case 4:{
            clientis();
            break;
        }
        case 5:{
            menu();
            break;
        }
        default:{
            printf("OPÇAO INVALIDA!\n");
            getch();
            caixa();
            break;
        }

    }
}


void clientis(){
    char conv[30];
    int opcao=1;
    system("cls");
    printf("--------------------------------------------------------------------------------\n");
    printf("------------------------------------CLIENTES------------------------------------\n");
    printf("--------------------------------------------------------------------------------\n");
    printf("\n1 - CADASTRA CLIENTE");
    printf("\n2 - CLIENTES");
    printf("\n3 - LOCALIZAR CLIENTES");
    printf("\n4 - ALTERAR DADOS DO CLIENTE");
    printf("\n5 - EXCLUIR CLIENTE");
    printf("\n6 - IR PARA O CAIXA");
    printf("\n7 - VOLTAR PARA O MENU PRINCIPAL\n");
    fflush(stdin);
    gets(conv);
    opcao=atoi(conv);
    switch(opcao){
        case 1:{
            char conv[30];
            system("cls");
            int cont;
            printf("DIGITE O CODIGO DO NOVO CLIENTE:\n");
            fflush(stdin);
            gets(conv);
            cod=atoi(conv);
            if(cod<=0){
                do{
                    printf("POR FAVOR! \nDIGITE UM CODIGO VALIDO PARA O CLIENTE:\n");
                    fflush(conv);
                    gets(conv);
                    cod=atoi(conv);
                }while(cod<=0);
            }
            if(clienteexiste(cod)==1){
                printf("CLIENTE JA CADASTRADO!\n");
                getch();
                clientis();
            }else{
                while(client[codcliente].codigo>0){
                    codcliente=codcliente+1;
                }
                client[codcliente].codigo=cod;
                printf("\nINFORME O NOME DO NOVO CLIENTE:\n");
                fflush(stdin);
                gets(client[codcliente].nome);
                printf("\nSEU ENDERECO:\n");
                fflush(stdin);
                gets(client[codcliente].endereco);
                printf("\nTELEFONE:\n");
                fflush(stdin);
                gets(conv);
                client[codcliente].telefone=atoi(conv);
                if(client[codcliente].telefone<=0){
                    do{
                        printf("TELEFONE INVALIDO!\n");
                        printf("POR FAVOR DIGITE UM NUMERO DE TELEFONE VALIDO:\n");
                        fflush(stdin);
                        gets(conv);
                        client[codcliente].telefone=atoi(conv);
                    }while(client[codcliente].telefone<=0);
                }
                printf("DIGITE SEU CPF:\n");
                fflush(stdin);
                gets(conv);
                client[codcliente].cpf=atoi(conv);
                if(client[codcliente].cpf<=0){
                    do{
                        printf("CPF INVALIDO!\n");
                        printf("POR FAVOR DIGITE SEU CPF VALIDO:\n");
                        fflush(stdin);
                        gets(conv);
                        client[codcliente].cpf=atoi(conv);
                    }while(client[codcliente].cpf<=0);
                    }
            }
            printf("CADASTRO FEITO COM SUCESSO!\n");
            printf("OS DADOS DO CLIENTE FORAM:\n");
            printf(" CODIGO: %d\n NOME: %s\n ENDERECO: %s\n TELEFONE: %.0f\n CPF: %.0f\n\n", client[codcliente].codigo, client[codcliente].nome, client[codcliente].endereco, client[codcliente].telefone, client[codcliente].cpf);
            printf("CLIQUE BOTAO *ENTER* PARA VOLTAR AO MENU CLIENTES!\n");
            getch();
            clientis();
            break;
        }
        case 2:{
            system("cls");
            int i;
            for(i=0;i<x;i++){
                if(client[i].codigo>0 && client[i].telefone>0 && client[i].cpf>0){
                    printf("\n--------------------------------------------------------------------------------\n");
                    printf(" CODIGO: %d\n NOME: %s\n ENDERECO: %s\n TELEFONE: %.0f\n CPF: %.0f\n\n", client[i].codigo, client[i].nome, client[i].endereco, client[i].telefone, client[i].cpf);
                }
            }
            printf("\nCLIQUE *ENTER* PARA VOLTA AO MENU CLIENTES!\n");
            getch();
            clientis();
            break;
        }
        case 3:{
            system("cls");
            int cod, i;
            printf("------------------------------CLIENTES CADASTRADOS------------------------------\n");
            for(i=0;i<x;i++){
                if(client[i].codigo>0 && client[i].telefone>0 && client[i].cpf>0){
                    printf(" CODIGO: %d\n NOME: %s\n\n", client[i].codigo, client[i].nome);
                }
            }
            printf("--------------------------------------------------------------------------------\n");
            printf("------------------------------LOCALIZAR CLIENTE---------------------------------\n");
            printf("DIGITE O CODIGO DO CLIENTE:\n");
            scanf("%d", &cod);
            if(clienteexiste(cod)!= 1 || cod == 0){
                printf("CLIENTE NAO EXISTENTE!\n");
                getch();
                clientis();
            }else{
                printf("CLIENTE DO CODIGO *%d* ENCONTRADO!\n", cod);
                printf(" NOME: %s\n CPF: %.0f\n ENDERECO: %s\n TELEFONE: %.0f\n\n", client[codcliente].nome, client[codcliente].cpf, client[codcliente].endereco, client[codcliente].telefone);
                }
                printf("CLIQUE *ENTER* PARA VOLTAR AO MENU CLIENTES!\n");
                getch();
                clientis();
                break;
        }
        case 4:{
            system("cls");
            int i, continuar=0;
            char conv[30];
            printf("------------------------------CLIENTES CADASTRADOS------------------------------\n");
            for(i=0;i<x;i++){
                if(client[i].codigo>0 && client[i].telefone>0 && client[i].cpf>0){
                    printf(" CODIDO: %d\n NOME: %s\n\n", client[i].codigo, client[i].nome);
                }
            }
            printf("--------------------------------------------------------------------------------\n\n");
            printf("DIGITE O CODIGO DO CLIENTE PARA EDITAR SEUS DADOS:\n");
            scanf("%d", &cod);
            if(cod<=0){
                printf("CODIGO INVALIDO!\n");
                printf("O CODIGO DO CLIENTE DEVE SER UM NUMERO MAIOR OU IGUAL A 1!\n");
                getch();
                clientis();
            }
            if(clienteexiste(cod) != 1 || cod==0){
                printf("CLIENTE NAO EXISTENTE!\n");
                getch();
                clientis();
            }else{
                printf("CLIENTE ENCONTRDO!\n");
                printf(" NOME: %s\n ENDERECO: %s\n TELEFONE: %.0f\n CPF: %.0f\n\n", client[codcliente].nome, client[codcliente].endereco, client[codcliente].telefone, client[codcliente].cpf);
                printf("EDITANDO DADOS!\n");
                printf("DIGITE O NOVO CODIGO DO CLIENTE:\n");
                fflush(stdin);
                gets(conv);
                client[codcliente].codigo=atoi(conv);
                if(client[codcliente].codigo<=0){
                        do{
                            printf("CODIGO INVALIDO!\n");
                            printf("POR FAVOR\n");
                            printf("DIGITE UM CODIGO VALIDO:\n");
                            fflush(stdin);
                            gets(conv);
                            client[codcliente].codigo=atoi(conv);
                        }while(client[codcliente].codigo<=0);
                }
                printf("DIGITE O NOVO NOME:\n");
                fflush(stdin);
                gets(client[codcliente].nome);
                printf("DIGITE O NOVO ENDERECO:\n");
                fflush(stdin);
                gets(client[codcliente].endereco);
                printf("DIGITE O NOVO TELEFONE:\n");
                fflush(stdin);
                gets(conv);
                client[codcliente].telefone=atoi(conv);
                if(client[codcliente].telefone<=0){
                    do{
                        printf("NUMERO DE TELEFONE INVALIDO!\n");
                        printf("POR FAVOR\n");
                        printf("DIGITE UM TELEFONE VALIDO:\n");
                        fflush(stdin);
                        gets(conv);
                        client[codcliente].telefone=atoi(conv);
                    }while(client[codcliente].telefone<=0);
                }
                printf("DIGITE O NOVO CPF:\n");
                fflush(stdin);
                gets(conv);
                client[codcliente].cpf=atoi(conv);
                if(client[codcliente].cpf<=0){
                    do{
                        printf("ERRO!\n");
                        printf("NUMERO DE CPF INVALIDO!\n");
                        printf("POR FAVOR\n");
                        printf("DIGITE UM NUMERO DE CPF VALIDO:\n");
                        fflush(stdin);
                        gets(conv);
                        client[codcliente].cpf=atoi(conv);
                    }while(client[codcliente].cpf<=0);
                }
                printf("\nALTERAÇAO FEITA COM SUCESSO!\n");
                printf("CLIQUE *ENTER* PARA VOLTAR AO MENU CLIENTES!\n");
                getch();
                clientis();
            }
            break;
        }
        case 5:{
            system("cls");
            int i, resp;
            printf("-------------------------------CLIENTES CADASTRADOS----------------------------\n");
            for(i=0;i<x;i++){
                if(client[i].codigo>0 && client[i].telefone>0 && client[i].cpf>0){
                    printf("\n CODIGO: %d\n NOME: %s\n\n", client[i].codigo, client[i].nome);
                }
            }
            printf("--------------------------------------------------------------------------------\n");
            printf("---------------------------------EXCLUIR CLIENTE--------------------------------\n");
            printf("DIGITE O CODIGO PARA A EXCLUSAO:\n");
            scanf("%d", &cod);
            if(clienteexiste(cod) != 1 || cod==0){
                printf("ERRO!\n");
                printf("CODIGO DO CLIENTE INVALIDO!\n");
                getch();
                clientis();
            }else{
                printf(" NOME: %s\n ENDERECO: %s\n TELEFONE: %.0f\n CPF: %.0f\n\n", client[codcliente].nome, client[codcliente].endereco, client[codcliente].telefone, client[codcliente].cpf);
                printf("ESCOLHA:\n");
                printf("DIGITE *1* PARA EXCLUIR:\n");
                scanf("%d", &resp);
                if(resp==1){
                    client[codcliente].codigo=0;
                    strcpy(client[codcliente].nome,"");
                    strcpy(client[codcliente].endereco,"");
                    client[codcliente].telefone=0;;
                    client[codcliente].cpf=0;;

                    printf("CLIENTE EXCLUIDO COM SUCESSO!\n");
                    printf("DIGITE *ENTER* PARA VOLTAR AO MENU CLIENTES!\n");
                    getch();
                    clientis();
                }else{
                    printf("A EXCLUSAO FOI CANCELADA!\n");
                    getch();
                    clientis();
                }
            }
        }
        case 6:{
            caixa();
            break;
        }
        case 7:{
            menu();
            break;
        }
        default:{
            printf("OPÇAO INVALIDA\n");
            getch();
            clientis();
        }
    }
}

void bones(){
    char conv[30];
    int opcao=1;
    system("cls");
    printf("--------------------------------------------------------------------------------\n");
    printf("--------------------------------------BONES-------------------------------------\n");
    printf("--------------------------------------------------------------------------------\n");
    printf("\n1 - CADASTRO");
    printf("\n2 - BONES");
    printf("\n3 - PESQUIZAR BONE");
    printf("\n4 - ALTERAR DADOS");
    printf("\n5 - EXCLUIR CADASTRO");
    printf("\n6 - CAIXA");
    printf("\n7 - MENU PRINCIPAL\n");
    fflush(stdin);
    gets(conv);
    opcao=atoi(conv);
    switch(opcao){
        case 1:{
            char conv[30];
            system("cls");
            printf("DGITE O CODIGO DO SEU NOVO BONE:\n");
            fflush(stdin);
            gets(conv);
            cod=atoi(conv);
            if(cod<=0){
                do{
                    printf("CODIGO INVALIDO!\n");
                    printf("DIGITE UM CODIGO VALIDO:\n");
                    fflush(stdin);
                    gets(conv);
                    cod=atoi(conv);
                }while(cod<=0);
            }
            if(ProdutoExiste(cod)==1){
                printf("CODIGO JA EXISTENTE!\n");
                getch();
                bones();
            }else{
                while(pro[codProduto].codigo>0){
                    codProduto=codProduto+1;
                }
                pro[codProduto].codigo=cod;
                printf("DGITE O NOME DO NOVO BONE:\n");
                fflush(stdin);
                gets(pro[codProduto].descricao);
                printf("DIGITE A QUANTIDADE DO ESTOQUE:\n");
                fflush(stdin);
                gets(conv);
                pro[codProduto].quantidade=atoi(conv);
                if(pro[codProduto].quantidade<=0){
                    do{
                        printf("QUANTIDADE INVALIDA!\n");
                        printf("\nPOR FAVOR\n");
                        printf("DIGITE UMA QUANTIDADE VALIDA DE ESTOQUE:\n");
                        fflush(stdin);
                        gets(conv);
                        pro[codProduto].quantidade=atoi(conv);
                    }while(pro[codProduto].quantidade<=0);
                }
                printf("DIGITE O VALOR DE VENDA DO BONE:\n");
                fflush(stdin);
                gets(conv);
                pro[codProduto].pvenda=atoi(conv);
                if(pro[codProduto].pvenda<=0){
                    do{
                        printf("VALOR INVALIDO!");
                        printf("\nPOR FAVOR\n");
                        printf("DIGITE UM VALOR VALIDO PARA VENDA DESTE BONE:\n");
                        fflush(stdin);
                        gets(conv);
                        pro[codProduto].pvenda=atoi(conv);
                    }while(pro[codProduto].pvenda<=0);
                }
            }
            printf("\nCADASTRO FOI REALIZADO COM SUCESSO!\n");
            printf("\nOS DADOS DO PRODUTO SAO:\n");
            printf(" CODIGO: %d\n NOME DO BONE: %s\n ESTOQUE: %d\n VALOR DE VENDA: %.2f\n\n",pro[codProduto].codigo, pro[codProduto].descricao, pro[codProduto].quantidade, pro[codProduto].pvenda);
            printf("CLIQUE *ENTER* PARA IR AO MENU BONES!\n");
            getch();
            bones();
            break;
        }
        case 2:{
            system("cls");
            int i;
            for(i=0;i<x;i++){
                if(pro[i].codigo>0){
                    printf("----------------------------------------------------------\n");
                    printf(" CODIGO: %d\n NOME DO BONE: %s\n ESTOQUE: %d\n VALOR DE VENDA: %.2f\n\n", pro[i].codigo, pro[i].descricao, pro[i].quantidade, pro[i].pvenda);
                }
            }
            printf("CLIQUE *ENTER* PARA SVOLTAR AO MENU BONES!\n");
            getch();
            bones();
            break;
        }
        case 3:{
            system("cls");
            int cod, i;
            printf("--------------------------------BONES CADASTRADOS-------------------------------\n\n");
            for(i=0;i<x;i++){
                if(pro[i].codigo>0 && pro[i].pvenda>0){
                    printf(" CODIGO: %d\n NOME DO BONE: %s\n\n", pro[i].codigo, pro[i].descricao);
                }
            }
            printf("--------------------------------------------------------------------------------\n");
            printf("PARA LOCALIZAR E VER DETALHES\nDE UM DOS BONE DIGITE O CODIGO:\n");
            scanf("%d",&cod);
            if(ProdutoExiste(cod)!=1 || cod==0){
                printf("CODIGO INVALIDO!\n");
                getch();
                bones();
            }else{
                printf("RESULTADO DO CODIGO *%d* EH:\n");
                printf(" NOME DO BONE: %s\n ESTOQUE: %d\n VALOR DE VENDA: %.2f\n\n", pro[codProduto].descricao, pro[codProduto].quantidade, pro[codProduto].pvenda);
            }
            printf("CLIQUE *ENTER* PARA VOLTAR AO MENU BONES!\n");
            getch();
            bones();
            break;
        }
        case 4:{
            system("cls");
            char conv[30];
            int i;
            printf("---------------------------------BONES CADASTRADOS------------------------------\n");
            for(i=0;i<x;i++){
                if(pro[i].codigo>0 && pro[i].quantidade>0 && pro[i].pvenda>0){
                    printf(" CODIGO: %d\n NOME: %s\n\n", pro[i].codigo, pro[i].descricao);
                }
            }
            printf("--------------------------------------------------------------------------------\n");
            printf("DIGITE O CODIGO DO BONE PARA ALTERAR SEUS DADOS:\n");
            scanf("%d",&cod);
            if(ProdutoExiste(cod) != 1){
                printf("CODIGO INVALIDO!\n");
                printf("\nPOR FAVOR\n");
                printf("DIGITE UM CODIGO VALIDO\n");
                scanf("%d", &cod);
                getch();
                bones();
            }else{
                printf("\n NOME DO BONÉ: %s\n ESTOQUE: %d\n VALOR DE VENDA: %.2f\n\n", pro[codProduto].descricao, pro[codProduto].quantidade, pro[codProduto].pvenda);
                printf("DIGITE O NOVO CODIGO DO BONE:\n");
                fflush(stdin);
                gets(conv);
                pro[codProduto].codigo=atoi(conv);
                if(pro[codProduto].codigo<=0){
                    do{
                        printf("CODIGO INVALIDO!\n");
                        printf("POR FAVOR\n");
                        printf("DIGITE UM CODIGO VALIDO:\n");
                        fflush(stdin);
                        gets(conv);
                        pro[codProduto].codigo=atoi(conv);
                    }while(pro[codProduto].codigo<=0);
                }
                printf("DIGITE O NOVO NOME DO BONE:\n");
                fflush(stdin);
                gets(pro[codProduto].descricao);
                printf("DIGITE O A NOVA QUATIDADE DE ESTOQUE:\n");
                fflush(stdin);
                gets(conv);
                pro[codProduto].quantidade=atoi(conv);
                if(pro[codProduto].quantidade<=0){
                    do{
                        printf("QUANTIDADE INVLIDA!\n");
                        printf("POR FAVOR\n");
                        printf("DIGITE UMA QUANTIDADE DE ESTOQUE VALIDA:\n");
                        fflush(stdin);
                        gets(conv);
                        pro[codProduto].quantidade=atoi(conv);
                    }while(pro[codProduto].quantidade<=0);
                }
                printf("DIGITE O NOVO VALOR DE VENDA:\n");
                fflush(stdin);
                gets(conv);
                pro[codProduto].pvenda=atoi(conv);
                if(pro[codProduto].pvenda<=0){
                    do{
                        printf("VALOR INVALIDO!\n");
                        printf("POR FAVOR\n");
                        printf("DIGITE UM VALOR DE VENDA VALIDO:\n");
                        fflush(stdin);
                        gets(conv);
                        pro[codProduto].pvenda=atoi(conv);
                    }while(pro[codProduto].pvenda<=0);
                }
            }
            printf("ALTERAÇAO DE DADOS REALIZADA COM SUCESSO!\n\n");
            printf(" CODIGO: %d\n NOME DO BONE: %s\n ESTOQUE: %d\n VALOR DE VENDA: %.2f\n\n", pro[codProduto].codigo, pro[codProduto].descricao, pro[codProduto].quantidade, pro[codProduto].pvenda);
            printf("CLIQUE *ENTER* PARA VOLTAR AO MENU BONES!\n");
            getch();
            bones();
            break;
        }
        case 5:{
            system("cls");
            int resp, i;
            printf("---------------------------------BONES CADASTRADOS------------------------------\n\n");
            for(i=0;i<x;i++){
                if(pro[i].codigo>0 && pro[i].quantidade>0 && pro[i].pvenda>0){
                    printf(" CODIGO: %d\n NOME DO BONE: %s\n\n", pro[i].codigo, pro[i].descricao);
                }
            }
            printf("--------------------------------------------------------------------------------\n\n");
            printf("DIGITE O CODIGO PARA EXCLUIR O PRODUTO:\n");
            scanf("%d", &cod);
            if(ProdutoExiste(cod) != 1){
                printf("CODIGO INVALIDO!\n");
                getch();
                bones();
            }else{
                printf("BONE DO COD %d ENCONTRADO!\n", cod);
                printf("SEUS DADOS SÃO:\n");
                printf(" NOME DO BONE: %s\n ESTOQUE: %d\n VALOR DE VENDA: %.2f\n\n", pro[codProduto].descricao, pro[codProduto].quantidade, pro[codProduto].pvenda);
                printf("DIGITE *1* OU QUALQUER TECLA PARA PARA CONTINUAR COM A EXLCLUSAO:\n");
                scanf("%d",&resp);
            }
            if(resp==1){
                pro[codProduto].codigo=0;
                strcpy(pro[codProduto].descricao,"");
                pro[codProduto].quantidade=0;
                pro[codProduto].pvenda=0;
                printf("BONE EXCLUIDO COM SUCESSO!\n\n");
                printf("CLIQUE *ENTER* PARA VOLTAR AO MENU BONES!\n");
                getch();
                bones();
            }else{
                printf("EXCLUSAO CANCELADA!\n");
                getch();
                bones();
            }
            break;
        }
        case 6:{
            caixa();
            break;
        }
        case 7:{
            menu();
            break;
        }
        default:{
            printf("OPCAO INVALIDA!\n");
            getch();
            bones();
        }
    }
}
int ProdutoExiste(int cod){
    int i, retorno = 0;
    for(i=0;i<x;i++){
        if(pro[i].codigo==cod){
            codProduto=i;
            retorno=1;
        }
    }
    return retorno;
}

int clienteexiste(int cod){
    int i, retorno = 0;
    for(i=0;i<x;i++){
        if(client[i].codigo==cod){
            codcliente=i;
            retorno=1;
        }
    }
    return retorno;
}


void sair(){
    system("cls");
    printf("\n\n\n\n\n\n\n\n--------------------------------------------------------------------------------\n");
    printf("--------------------------OBRIGADO E VOLTE SEMPRE!------------------------------\n");
    printf("--------------------------------------------------------------------------------\n");
    getch();
    exit(0);
}


void sobre(){
    system("cls");
    printf("-------------------------------SOBRE O APLICATIVO-------------------------------\n\n\n");
    printf("TRABALHO FINAL!\n");
    printf(" APLICATIVO CRIADO EM 18/02/2017\nPELO O ALUNO JOSE MAYKE MOURA CARDOSO\nDO CURSO DE SISTEMA DE INFORMACAO DA UNIVERSIDADE FEDERAL DO PIAUI - PICOS!\n\n\n");
    printf("------------------------------MOTIVO DO APLICATIVO------------------------------\n");
    printf(" ESSE APLICATIVO FOI FEITO COM O PRINCIPAL OBJETIVO DE SER UM CADASTRO DE BONES\nPOREM ELE POSSUI FUNCOES EXTRAS COMO POR EXEMPLO: VENDA DO PRODUTO, CADASTROS \nDE CLIENTES UM CAIXA. SAO FUNCOES COMPLEMENTARES IDEALIZADAS POR SEU CRIADOR\nCOM A INTENCAO DE APRIMORAR/MELHORAR O MESMO.");
    getch();
    menu();
}



void bemvindo(){
    printf("--------------------------------------------------------------------------------\n\n\n");
    printf("                                   BEM VINDO!\n\n\n\n");
    printf("--------------------------------------------------------------------------------\n");
    getch();
    menu();
}

void menu(){
    char conv[30];
    int opcao=1;
    system("cls");
    printf("--------------------------------------------------------------------------------\n");
    printf("---------------------------------MENU-PRINCIPAL---------------------------------\n");
    printf("--------------------------------------------------------------------------------\n");
    printf("\n1 - CAIXA");
    printf("\n2 - BONES");
    printf("\n3 - CLIENTES");
    printf("\n4 - SOBRE O APLICATIVO");
    printf("\n5 - SAIR DO PROGRAMA\n");
    gets(conv);
    opcao=atoi(conv);
    switch(opcao){
        case 1:{
            system("cls");
            caixa();
            getch();
            menu();
            break;
        }
        case 2:{
            bones();
            getch();
            menu();
            break;
        }
        case 3:{
            clientis();
            getch();
            menu();
            break;
        }
        case 4:{
            sobre();
            getch();
            menu();
            break;
        }
        case 5:{
            sair();
            break;
        }
        default:{
            printf("OPCAO INVALIDA!\n");
            printf("TENTE NOVAMENTE!\n");
            getch();
            menu();
        }
    }
}

int main(){
    client[0].codigo=10;
    strcpy (client[0].nome,"Jose");
    strcpy (client[0].endereco,"Rua sol nacente");
    client[0].telefone=99984132939;
    client[0].cpf=6679645768;
    client[1].codigo=20;
    strcpy (client[1].nome,"mabson");
    strcpy (client[1].endereco,"Rua conjuto oeiras");
    client[1].telefone=99982571935;
    client[1].cpf=91284763785;
    client[2].codigo=30;
    strcpy (client[2].nome,"mykaene");
    strcpy (client[2].endereco,"Rua ze de elena");
    client[2].telefone=99984157306;
    client[2].cpf=34242553645;
    client[3].codigo=40;
    strcpy (client[3].nome,"edilma");
    strcpy (client[3].endereco,"Rua projetada");
    client[3].telefone=99981906810;
    client[3].cpf=46546566566;
    pro[97].codigo=10;
    strcpy (pro[97].descricao,"ADIDAS");
    pro[97].quantidade=20;
    pro[97].pvenda=30;
    pro[98].codigo=20;
    strcpy (pro[98].descricao,"COCA COLA");
    pro[98].quantidade=30;
    pro[98].pvenda=35;
    pro[99].codigo=30;
    strcpy (pro[99].descricao,"ZIKA");
    pro[99].quantidade=30;
    pro[99].pvenda=20;
    bemvindo();
}
