#include 	<stdio.h>
#include 	<stdlib.h>
#define 	NUM_P 			5 		/* Numero de produtos */
#define 	NUM_MP 			3 		/* Numeros de materias primas */
#define 	NOME_PRODUTO 	30 		/* Numero maximo de caracteres para o nome de um Produto */
#define 	NOME_MATERIASP 	30      /* Numero maximo de caracteres para o nome de uma Materia Prima */
#define		CEM_POR_CENTO 	100
#define		TONELADA 		1000

/* directivas de pre-compilador, definicao de tipos/estruturas, variaveis globais, etc. */


typedef struct{
	char nome[NOME_PRODUTO+1]; 		/* Vector com o nome do produto */
	double k_mo; 					/* coeficiente k_mo */
	double k_en; 					/* coeficiente k_en*/
	double k_eq; 					/* coeficiente k_eq*/
	double perdas; 					/* perdas de producao  */
	double vendas; 					/* toneladas vendidas por ano de cada produto */
	double PVendas; 				/* preco por tonelada por produto */
} Produto;
	
typedef struct{
	char nome[NOME_MATERIASP+1]; /* vector com o nome das materias primas */
	double preco_mp; /* preco de cada materia prima */
} MateriasPrimas;

typedef struct{
	double orcamento;
} Orcamento;

Produto 		lista_produtos[NUM_P];
MateriasPrimas	lista_materiasPrimas[NUM_MP];
Orcamento       lista_orcamentos[NUM_P];

/* Variaveis globais */
double comp_prod[NUM_P][NUM_MP];

double custoA = 0;
double custoB[NUM_P]; 
double custoC[NUM_P];  
double custoE = 0;
double custoD[NUM_P];
double custoF[NUM_P]; 
double cTOT[NUM_P];
double cIND[NUM_P];
double cMPEE[NUM_P];
double margem[NUM_P];

/* Funcoes */
void executa_d();
void executa_c();
void executa_w();
void executa_t();


/* Funcoes que calculam os diferentes custos dos produtos */

double calc_custoA();
void calc_custoB(double custo_b[NUM_P]);				
void calc_custoC(double custo_c[NUM_P]);
void calc_custoD(double custo_d[NUM_P]);
double calc_custoE();
void calc_custoF(double custo_f[NUM_P]); 


/* Funcoes le */
void leNome_produto();
void leNome_materiaisP();
void lek_mo();
void lek_en();
void lek_eq();
void leVendas();
void lePerdas();
void lePVendas();
void lePreco_mp();
void leComp_prod();
void leOrcamento();

/* Comando d i */
void leNome_produto (){ /* Funcao que le o nome dos produtos */
	int i;
	for ( i = 0 ; i< NUM_P; i++){
		scanf("%s", lista_produtos[i].nome);
		if(i!=0){
			printf(" ");
		}
		printf("%s", lista_produtos[i].nome);
	}
	printf("\n");
}

/* Comando j n */		
void leNome_materiasP (){ /* Funcao que le o nome das materias primas */
	int i;
	for (i=0; i<NUM_MP; i++){
		scanf("%s", lista_materiasPrimas[i].nome);
		if(i!=0){
			printf(" ");
		}
		printf("%s", lista_materiasPrimas[i].nome);
	}
	printf("\n");
}
/* Comando d m */		
void lek_mo (){ /* Funcao que le o coeficiente k_mo */
	int i;
	for (i=0; i<NUM_P; i++)
		scanf("%lf", &(lista_produtos[i].k_mo));
}

/* Comando d n */
void lek_en (){ /* Funcao que le o coeficiente k_en */
	int i;
	for (i=0; i<NUM_P; i++)
		scanf("%lf", &(lista_produtos[i].k_en));
}

/* Comando d q */
void lek_eq (){ /* Funcao que le o coeficiente k_eq */
	int i;
	for (i=0; i<NUM_P; i++)
		scanf("%lf", &(lista_produtos[i].k_eq));
}

void leVendas (){ /* Funcao que le o Vendas anuais */
	int i;
	for (i=0; i<NUM_P; i++)
		scanf("%lf", &(lista_produtos[i].vendas));
}

void lePerdas (){ /* Funcao que le as perdas na producao */
	int i;
	for (i=0; i<NUM_P; i++)
		scanf("%lf", &(lista_produtos[i].perdas));
}

void lePVendas (){ /* Funcao que le preco por tonelada  */
	int i;
	for (i=0; i<NUM_P; i++)
		scanf("%lf", &(lista_produtos[i].PVendas));
}

void lePreco_mp (){ /* Funcao que le o preco das materias primas  */
	int i;
	for (i=0; i<NUM_MP; i++)
		scanf("%lf", &(lista_materiasPrimas[i].preco_mp));
}


void leComp_prod (){
	int i, j;
	for (i=0; i<NUM_P; i++){
		for (j=0; j<NUM_MP; j++)
			scanf("%lf", &(comp_prod[i][j])); 
	}														 	
}															 
															 
void leOrcamento(){
	int i;
	for (i=0; i<NUM_P; i++)
		scanf("%lf", &(lista_orcamentos[i].orcamento));
}

/* Funcoes custos A...F */

double calc_custoA(){

	int i;
	double custo_a;
	double VendasTotais=0;
	
	for(i=0; i < NUM_P; i++)
		VendasTotais = VendasTotais + (lista_produtos[i].vendas);

	custo_a = (lista_orcamentos[0].orcamento) / VendasTotais;

	return custo_a;						

}	

void calc_custoB(double custo_b[NUM_P]){
	
	int i,j;
	double mo = 0;

	for(i=0; i < NUM_P; i++)
		mo = mo+ (lista_produtos[i].k_mo * lista_produtos[i].vendas);

	for(j=0;j < NUM_P;j++)
		custo_b[j]= (lista_orcamentos[1].orcamento * lista_produtos[j].k_mo) / mo;	

}

void calc_custoC(double custo_c[NUM_P]){

	int i, j;
	double en = 0;
	
	for(i=0; i<NUM_P; i++)
		en = en + ((lista_produtos[i].k_en) * (lista_produtos[i].vendas));

	for(j=0; j<NUM_P; j++)
		custo_c[j] = ((lista_orcamentos[2].orcamento) * (lista_produtos[j].k_en)) / en;
}


void calc_custoD(double custo_d[NUM_P]){

	int i, j;
	double eq = 0;
	
	for(i=0; i<NUM_P; i++)
		eq = eq + ((lista_produtos[i].k_eq) * (lista_produtos[i].vendas));

	for(j=0; j<NUM_P; j++)
		custo_d[j] = ((lista_orcamentos[3].orcamento) * (lista_produtos[j].k_eq)) / eq;
}

double calc_custoE(){

	int i;
	double custo_e;
	double VendasTotais=0;

	for(i=0; i < NUM_P; i++)
		VendasTotais = VendasTotais + (lista_produtos[i].vendas);

	custo_e = (lista_orcamentos[4].orcamento) / VendasTotais;

	return custo_e;						
}	


void calc_custoF(double custo_f[NUM_P]){

	int i , j;
	double soma;

	for(i=0; i < NUM_P; i++){
		soma = 0;
		for(j=0; j < NUM_MP; j++){
			soma = soma + lista_materiasPrimas[j].preco_mp * comp_prod[i][j];
		}
		
		custo_f[i] = (soma/(CEM_POR_CENTO - lista_produtos[i].perdas)) * TONELADA;
		
	}		
}

/* Funcoes que imprimem a informacao relevante */

void executa_d(){
    char subcomando;
    getchar(); /* le o espaco */
    subcomando = getchar(); /* le o sub-comando */

    switch (subcomando) {
    case 'i':
		/* Executa comando d i */
        leNome_produto();
        break;
    case 'j':
        /* Executa comando d j */
        leNome_materiasP();
        break;
    case 'y':
        /* Executa comando d y */
        lePreco_mp();
        break;
    case 'v':
        /* Executa comando d v */
        leVendas();
        break;
    case 'z':
        /* Executa comando d z */
        lePVendas();
        break;
    case 'p':
        /* Executa comando d p */
        lePerdas();
        break;
    case 'm':
        /* Executa comando d m */
        lek_mo();
        break;
    case 'n':
        /* Executa comando d n */
        lek_en();
        break;
    case 'q':
        /* Executa comando d q */
        lek_eq();
        break;
    case 'o':
        /* Executa comando d o */
        leOrcamento();
        break;
    case 'c':
        /* Executa comando d c */
        leComp_prod();
        break;
    default:
        printf("ERRO: Comando l [%c] desconhecido\n",subcomando);
    }
}

void executa_c(){
	
	int i;


	custoA = calc_custoA();
	calc_custoB(custoB);
	calc_custoC(custoC);
	calc_custoD(custoD);
	custoE = calc_custoE();
	calc_custoF(custoF);

	printf("cTOT ");

	
	for(i=0; i < NUM_P; i++)
	{
		cTOT[i]  = custoA + custoB[i] + custoC[i] + custoD[i] + custoE + custoF[i];
		printf("%.2f " ,cTOT[i]);
	}

	printf("\nM ");

	for(i=0; i < NUM_P; i++)
	{
		margem[i]  = (lista_produtos[i].PVendas - cTOT[i])/(lista_produtos[i].PVendas)*CEM_POR_CENTO;
		printf("%.2f " ,margem[i]);
	}

	printf("\ncIND ");

	for(i=0; i < NUM_P; i++)
	{
		cIND[i]  = cTOT[i] - custoA ;
		printf("%.2f " ,cIND[i]);
	}

	printf("\ncMPEE ");

	for(i=0; i < NUM_P; i++)
	{
		cMPEE[i]  = custoC[i] + custoE + custoF[i];
		printf("%.2f " ,cMPEE[i]);
	}
	printf("\n");
	
}

void executa_w(){

	int i;

	scanf("%d",&i);
	i= i-1;

	printf("W %s A:%.2f B:%.2f C:%.2f D:%.2f E:%.2f F:%.2f\n",lista_produtos[i].nome,custoA,custoB[i],custoC[i],custoD[i],custoE,custoF[i]);


}

void executa_t(){

	int i;

	double custo = 0;
	double venda = 0;
	double lucro = 0;
	double margem = 0;

	for (i=0; i < NUM_P; i++)
		venda = venda + lista_produtos[i].PVendas * lista_produtos[i].vendas;
	for (i=0; i < NUM_P; i++)
		custo = custo + cTOT[i]*lista_produtos[i].vendas;
	
	lucro = venda - custo;
	margem = ((venda - custo)/(venda))*CEM_POR_CENTO;

	printf("T %.2f %.2f %.2f %.2f\n", custo, venda, lucro, margem);
	



}


int main(){
    char comando;
    while (1) {
		
        comando = getchar(); /* le o comando */
        while (comando == '\n' || comando == ' '){
			comando = getchar();
		}
        switch (comando) 
        {
        case 'd':
            executa_d(); /* Executa comando d */
            break;
        case 'c':
            executa_c(); /* Executa comando c */
            break;
        case 'w':
			executa_w(); /* Executa comando w */
            break;
        case 't':
            executa_t(); /* Executa comando t */
            break;
        case 'v':
            /* Executa comando v */
            break;
        case 'x':
            /* Executa comando x */
            return EXIT_SUCCESS; /* Termina o programa */
        default:
            printf("ERRO: Comando [%c] desconhecido\n",comando);
        }
        getchar(); /* le o '\n' introduzido pelo utilizador */
    }
  
    return EXIT_FAILURE;
}

/*alhsdjahslhajkhladhdjahdjhjkhajkshadjksh*/

/* restantes funcoes */

